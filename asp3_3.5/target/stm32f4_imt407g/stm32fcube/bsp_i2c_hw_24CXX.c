#include "bsp_i2c_hw.h"
#include "bsp_i2c_hw_24CXX.h"

/*******************************************************************************
*************************以下为EEPROM24C02读写操作******************************
*******************************************************************************/

void AT24C02_Delay(uint16_t ms)
{
	uint32_t i;
	for(i=0;i<ms;i++)
		dly_tsk(1000);
}

//初始化24c02的IIC接口
void AT24C02_Init(void)
{
	MX_I2C_HW_Init();  //IIC初始化
}

/****************************************************************************
* 名    称: u8 AT24C02_ReadByte(u8 ReadAddr)
* 功    能：在AT24C02指定地址读出一个数据
* 入口参数：ReadAddr：要读取数据所在的地址
* 返回参数：读到的8位数据
* 说    明：  
****************************************************************************/
u8 AT24C02_ReadByte(u8 ReadAddr)
{
	u8 receivedata=0;
	uint16_t Addr=0XA0;

	receivedata=I2C_HW_ReadData(Addr, ReadAddr);

	return receivedata;
}

/****************************************************************************
* 名    称: u8 AT24C02_WriteByte(u8 WriteAddr,u8 WriteData)
* 功    能：在AT24C02指定地址写入一个数据
* 入口参数：WriteAddr：要写入数据所在的地址
            WriteData: 要写入的数据
* 返回参数：
* 说    明：  
****************************************************************************/
void AT24C02_WriteByte(u8 WriteAddr,u8 WriteData)
{
	uint16_t Addr=0XA0;
	I2C_HW_WriteData(Addr, WriteAddr, WriteData);
}

/****************************************************************************
* 名    称: u8 AT24C02_Test(void)
* 功    能：测试AT24C02是否正常
* 入口参数：无
* 返回参数：返回1:检测失败
            返回0:检测成功
* 说    明：  
****************************************************************************/
u8 AT24C02_Test(u8 Addr, u8 DataIn, u8* DataOut, u8 ReadOnly)
{
	u8 Testdata;

	if(!ReadOnly){
		AT24C02_WriteByte(Addr,DataIn);
		AT24C02_Delay(10);
	}

	Testdata=AT24C02_ReadByte(Addr);
	*DataOut = Testdata;

	if(ReadOnly || Testdata==DataIn){
		return 0;
	}else{
		return 1;
	}
}

/****************************************************************************
* 名    称: void AT24C02_Read(u8 ReadAddr,u8 *pBuffer,u8 ReadNum)
* 功    能：从AT24C02里面的指定地址开始读出指定个数的数据
* 入口参数：ReadAddr :开始读出的地址  0~255
            pBuffer  :数据数组首地址
            ReadNum:要读出数据的个数
* 返回参数：
* 说    明：  
****************************************************************************/
void AT24C02_Read(u8 ReadAddr,u8 *pBuffer,u8 ReadNum)
{
	while(ReadNum--)
	{
		*pBuffer++=AT24C02_ReadByte(ReadAddr++);
	}
}

/****************************************************************************
* 名    称: void AT24C02_Write(u8 WriteAddr,u8 *pBuffer,u8 WriteNum)
* 功    能：从AT24C02里面的指定地址开始写入指定个数的数据
* 入口参数：WriteAddr :开始写入的地址  0~255
            pBuffer  :数据数组首地址
            WriteNum:要写入数据的个数
* 返回参数：
* 说    明：  
****************************************************************************/
void AT24C02_Write(u8 WriteAddr,u8 *pBuffer,u8 WriteNum)
{
	while(WriteNum--)
	{
		AT24C02_WriteByte(WriteAddr,*pBuffer);
		WriteAddr++;
		pBuffer++;
	}
}
