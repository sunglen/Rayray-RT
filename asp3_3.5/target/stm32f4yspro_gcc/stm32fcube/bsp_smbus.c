#include "bsp_smbus.h"

void delay_us(u32 nus)
{
	dly_tsk(nus);
}

void delay_ms(u16 nms)
{
	u32 i;
	for(i=0;i<nms;i++) delay_us(1000);
}

float BSP_SMBUS_ReadTemp(void)
{
	float temp = 0.0;
	int count = 0;

	for(count=0;count<3;count++)
	{
		temp=temp+SMBus_ReadTemp();  //读取温度
	}
	temp=temp/3.0;

	return temp;
}

void BSP_SMBUS_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* 打开GPIO时钟 */
  SMBUS_GPIO_CLK_ENABLE();

  GPIO_InitStruct.Pin = SMBUS_SDA_PIN|SMBUS_SCL_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(SMBUS_PORT, &GPIO_InitStruct);

	 /* 给一个停止信号, 复位I2C总线上的所有设备到待机模式 */
	/* 当SCL高电平时，SDA出现一个上跳沿表示I2C总线停止信号 */
	SMBUS_SDA =0;
	SMBUS_SCL =1;
  delay_ms(9);
	//
	//
	SMBUS_SCL =1;
	SMBUS_SDA =1;
	delay_ms(9);

}

void SMBUS_Start(void)
{
	SDA_OUT();
	SMBUS_SDA =1;
	SMBUS_SCL =1;
	delay_us(4);
	SMBUS_SDA =0;
	delay_us(4);
	SMBUS_SCL =0;
}



 void SMBUS_Stop(void)
{
	SDA_OUT();
  SMBUS_SCL =0;
  SMBUS_SDA =0;
  delay_us(4);
	SMBUS_SCL =1;
	SMBUS_SDA =1;
	delay_us(4);
}

//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
u8 SMBUS_Wait_Ack(void)
{
	u8 ucErrTime=0;
	SDA_IN();      //SDA设置为输入
	SMBUS_SDA=1;delay_us(1);
	SMBUS_SCL=1;delay_us(1);
	while(READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			SMBUS_Stop();
			return 1;
		}
	}
	SMBUS_SCL=0;//时钟输出0
	return 0;
}

//产生ACK应答
void SMBUS_Ack(void)
{
	SMBUS_SCL=0;
	SDA_OUT();
	SMBUS_SDA=0;
	delay_us(2);
	SMBUS_SCL=1;
	delay_us(2);
	SMBUS_SCL=0;
}

//不产生ACK应答
void SMBUS_NAck(void)
{
	SMBUS_SCL=0;
	SDA_OUT();
	SMBUS_SDA=1;
	delay_us(2);
	SMBUS_SCL=1;
	delay_us(2);
	SMBUS_SCL=0;

}

u8 SMBus_SendByte(u8 Tx_buffer)
{
    u8	Bit_counter;
    u8	Ack_bit;
    u8	bit_out;

    for(Bit_counter=8; Bit_counter; Bit_counter--)
    {
        if (Tx_buffer&0x80)
        {
            bit_out=1;   // If the current bit of Tx_buffer is 1 set bit_out
        }
        else
        {
            bit_out=0;  // else clear bit_out
        }
        SMBus_SendBit(bit_out);		// Send the current bit on SDA
        Tx_buffer<<=1;				// Get next bit for checking
    }
		 Ack_bit=SMBus_ReceiveBit();		// Get acknowledgment bit
     return	Ack_bit;
	}
/*******************************************************************************
* Function Name  : SMBus_SendBit
* Description    : Send a bit on SMBus 82.5kHz
* Input          : bit_out
* Output         : None
* Return         : None
*******************************************************************************/
void SMBus_SendBit(u8 bit_out)
{
    if(bit_out==0)
    {
        SMBUS_SDA =0;
    }
    else
    {
        SMBUS_SDA=1;
    }
    delay_us(2);					// Tsu:dat = 250ns minimum
    SMBUS_SCL =1;					// Set SCL line
    delay_us(6);					// High Level of Clock Pulse
    SMBUS_SCL =0;					// Clear SCL line
    delay_us(3);					// Low Level of Clock Pulse
//	SMBUS_SDA_H();				    // Master release SDA line ,
    return;
}

/*******************************************************************************
* Function Name  : SMBus_ReceiveBit
* Description    : Receive a bit on SMBus
* Input          : None
* Output         : None
* Return         : Ack_bit
*******************************************************************************/
u8 SMBus_ReceiveBit(void)
{
    u8 Ack_bit;

    SMBUS_SDA =1;;          //引脚靠外部电阻上拉，当作输入
	  delay_us(2);			// High Level of Clock Pulse
    SMBUS_SCL =1;			// Set SCL line
    delay_us(5);			// High Level of Clock Pulse
    if (READ_SDA ==1)
    {
        Ack_bit=1;
    }
    else
    {
        Ack_bit=0;
    }
    SMBUS_SCL =0;			// Clear SCL line
    delay_us(3);			// Low Level of Clock Pulse

    return	Ack_bit;
}

u8 SMBus_ReceiveByte(u8 ack_nack)
{
    u8 	RX_buffer;
    u8	Bit_Counter;

    for(Bit_Counter=8; Bit_Counter; Bit_Counter--)
    {
        if(SMBus_ReceiveBit())			// Get a bit from the SDA line
        {
            RX_buffer <<= 1;			// If the bit is HIGH save 1  in RX_buffer
            RX_buffer |=0x01;
        }
        else
        {
            RX_buffer <<= 1;			// If the bit is LOW save 0 in RX_buffer
            RX_buffer &=0xfe;
        }
    }
    SMBus_SendBit(ack_nack);			// Sends acknowledgment bit
    return RX_buffer;
}

u16 SMBus_ReadMemory(u8 slaveAddress, u8 command)
{
    u16 data;			// Data storage (DataH:DataL)
    u8 Pec;				// PEC byte storage
    u8 DataL=0;			// Low data byte storage
    u8 DataH=0;			// High data byte storage
    u8 arr[6];			// Buffer for the sent bytes
    u8 PecReg;			// Calculated PEC byte storage
    u8 ErrorCounter;	// Defines the number of the attempts for communication with MLX90614

    ErrorCounter=0x00;				// Initialising of ErrorCounter
	slaveAddress <<= 1;	//2-7位表示从机地址

    do
    {
repeat:
        SMBUS_Stop();			    //If slave send NACK stop comunication
        --ErrorCounter;				    //Pre-decrement ErrorCounter
        if(!ErrorCounter) 			    //ErrorCounter=0?
        {
            break;					    //Yes,go out from do-while{}
        }

        SMBUS_Start();				//Start condition
        if(SMBus_SendByte(slaveAddress))//Send SlaveAddress 最低位Wr=0表示接下来写命令
        {
            goto	repeat;			    //Repeat comunication again
        }
        if(SMBus_SendByte(command))	    //Send command
        {
            goto	repeat;		    	//Repeat comunication again
        }

        SMBUS_Start();					//Repeated Start condition
        if(SMBus_SendByte(slaveAddress+1))	//Send SlaveAddress 最低位Rd=1表示接下来读数据
        {
            goto	repeat;             	//Repeat comunication again
        }

        DataL = SMBus_ReceiveByte(ACK);	//Read low data,master must send ACK
        DataH = SMBus_ReceiveByte(ACK); //Read high data,master must send ACK
        Pec = SMBus_ReceiveByte(NACK);	//Read PEC byte, master must send NACK
        SMBUS_Stop();				//Stop condition

        arr[5] = slaveAddress;		//
        arr[4] = command;			//
        arr[3] = slaveAddress+1;	//Load array arr
        arr[2] = DataL;				//
        arr[1] = DataH;				//
        arr[0] = 0;					//
        PecReg=PEC_Calculation(arr);//Calculate CRC
    }
    while(PecReg != Pec);		//If received and calculated CRC are equal go out from do-while{}

	data = (DataH<<8) | DataL;	//data=DataH:DataL
    return data;
}

/*******************************************************************************
* Function Name  : PEC_calculation
* Description    : Calculates the PEC of received bytes
* Input          : pec[]
* Output         : None
* Return         : pec[0]-this byte contains calculated crc value
*******************************************************************************/
u8 PEC_Calculation(u8 pec[])
{
    u8 	crc[6];
    u8	BitPosition=47;
    u8	shift;
    u8	i;
    u8	j;
    u8	temp;

    do
    {
        /*Load pattern value 0x000000000107*/
        crc[5]=0;
        crc[4]=0;
        crc[3]=0;
        crc[2]=0;
        crc[1]=0x01;
        crc[0]=0x07;

        /*Set maximum bit position at 47 ( six bytes byte5...byte0,MSbit=47)*/
        BitPosition=47;

        /*Set shift position at 0*/
        shift=0;

        /*Find first "1" in the transmited message beginning from the MSByte byte5*/
        i=5;
        j=0;
        while((pec[i]&(0x80>>j))==0 && i>0)
        {
            BitPosition--;
            if(j<7)
            {
                j++;
            }
            else
            {
                j=0x00;
                i--;
            }
        }/*End of while */

        /*Get shift value for pattern value*/
        shift=BitPosition-8;

        /*Shift pattern value */
        while(shift)
        {
            for(i=5; i<0xFF; i--)
            {
                if((crc[i-1]&0x80) && (i>0))
                {
                    temp=1;
                }
                else
                {
                    temp=0;
                }
                crc[i]<<=1;
                crc[i]+=temp;
            }/*End of for*/
            shift--;
        }/*End of while*/

        /*Exclusive OR between pec and crc*/
        for(i=0; i<=5; i++)
        {
            pec[i] ^=crc[i];
        }/*End of for*/
    }
    while(BitPosition>8); /*End of do-while*/

    return pec[0];
}

 /*******************************************************************************
 * Function Name  : SMBus_ReadTemp
 * Description    : Calculate and return the temperature
 * Input          : None
 * Output         : None
 * Return         : SMBus_ReadMemory(0x00, 0x07)*0.02-273.15
*******************************************************************************/
float SMBus_ReadTemp(void)
{
	float temp;
	temp = SMBus_ReadMemory(SA, RAM_ACCESS|RAM_TOBJ1)*0.02-273.15;
	return temp;
}


