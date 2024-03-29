/*
 * This file was automatically generated by tecsgen.
 * Move and rename like below before editing,
 *   gen/tBlueTooth_templ.c => src/tBlueTooth.c
 * to avoid to be overwritten by tecsgen.
 */
/* #[<PREAMBLE>]#
 * Don't edit the comments between #[<...>]# and #[</...>]#
 * These comment are used by tecsmerege when merging.
 *
 * call port function #_TCPF_#
 * call port: cSerialPort signature: sSerialPort context:task
 *   ER             cSerialPort_open( );
 *   ER             cSerialPort_close( );
 *   ER_UINT        cSerialPort_read( char* buffer, uint_t length );
 *   ER_UINT        cSerialPort_write( const char* buffer, uint_t length );
 *   ER             cSerialPort_control( uint_t ioControl );
 *   ER             cSerialPort_refer( T_SERIAL_RPOR* pk_rpor );
 * call port: cnSerialPortManage signature: snSerialPortManage context:task
 *   bool_t         cnSerialPortManage_getChar( char* p_char );
 *
 * #[</PREAMBLE>]# */

/* Put prototype declaration and/or variale definition here #_PAC_# */
#include "tBlueTooth_tecsgen.h"

#include "stm32f4xx_nucleo.h"
#include <string.h>

#include "kernel_cfg.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

//中断缓存串口数据
#define UART_BUFF_SIZE      1024
char buff[UART_BUFF_SIZE];

/**
  * 函数功能: 获取接收到的数据和长度
  * 输入参数: 无
  * 返 回 值: 无
  * 说    明：无
  */
char *get_rebuff(uint16_t *len)
{
	char c;
	int n=0;

	do{
		if(n >=6 && \
				buff[n-1] == '\n' && buff[n-2] =='\r' && \
				buff[n-3] == 'K' && buff[n-4] =='O' && \
				buff[n-5] == '\n' && buff[n-6] =='\r')
		{
			break;
		}

		if(n >=5 && \
				buff[n-1] == '\n' && buff[n-2] =='\r' && \
				buff[n-3] == 'R' && buff[n-4] =='R' && \
				buff[n-5] == 'E')
		{
			break;
		}

		cSerialPort_read(&c, 1);
		printf("%c", c);
		buff[n]=c;
		n++;
	}while(c != 0 && n < UART_BUFF_SIZE);

	*len=n;

    return buff;
}

/**
  * 函数功能: 清空缓冲区
  * 输入参数: 无
  * 返 回 值: 无
  * 说    明：无
  */
void clean_rebuff(void)
{
  uint16_t i=UART_BUFF_SIZE;

  while(i)
	buff[--i]=0;
}

void BlueTooth_Delay(uint16_t ms)
{
	uint32_t i;
	for(i=0;i<ms;i++)
		dly_tsk(1000);
}

/**
  * 函数功能: 串口发送一个字节数据
  * 输入参数: ch：待发送字符
  * 返 回 值: 无
  * 说    明：无
  */
void Usart_SendByte(uint8_t ch)
{
	cSerialPort_write(&ch, 1);
}

/**
  * 函数功能: 串口发送指定长度的字符串
  * 输入参数: str：待发送字符串缓冲器
  *           strlen:指定字符串长度
  * 返 回 值: 无
  * 说    明：无
  */
void Usart_SendStr_length(uint8_t *str,uint32_t strlen)
{
	unsigned int k=0;
    do
    {
        Usart_SendByte( *(str + k) );
        k++;
    } while(k < strlen);
}

/**
  * 函数功能: 串口发送字符串，直到遇到字符串结束符
  * 输入参数: str：待发送字符串缓冲器
  * 返 回 值: 无
  * 说    明：无
  */
void Usart_SendString(uint8_t *str)
{
	unsigned int k=0;
    do
    {
        Usart_SendByte(*(str + k));
        k++;
    } while(*(str + k)!='\0');
}

uint8_t CC2541_Send_CMD(char* cmd,uint8_t clean)
{
  uint16_t len;
  char * redata;
  uint8_t retry=5;
  uint8_t i;
  while(retry--)
  {
   BlueTooth_Delay(10);
   Usart_SendString((uint8_t*)cmd);
    for(i=0;i<20;i++)
    {
     BlueTooth_Delay(10);
     redata=get_rebuff(&len);
      if(len>0)
      {
        if(redata[0]!=0)
        {
          printf("send CMD: %s",cmd);
          printf("receive %s",redata);
        }
        if(strstr(redata,"OK"))
        {
          if(clean==1)
            clean_rebuff();
          return 0;
        }
      }
        else
      {
        BlueTooth_Delay(100);
      }
    }
   }
	if(clean==1)
		clean_rebuff();
	return 1 ;
}


/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eTaskBody
 * entry port: eTaskBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTaskBody_main
 * name:         eTaskBody_main
 * global_name:  tBlueTooth_eTaskBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTaskBody_main()
{
	int len;
	uint16_t set;

	cSerialPort_open();
	cSerialPort_control(IOCTL_NULL);

	dly_tsk(1000000);
	//printf("AT+NAME RAYRAY-RT\n");
	//cSerialPort_write("AT+NAME RAYRAY-RT\r\n", 19);
	CC2541_Send_CMD("AT+NAME RAYRAY-RT\r\n",1);

	BlueTooth_Delay(1000);

    //printf("设置模块为主模式\n");
    //CC2541_Send_CMD("AT+ROLE1\r\n",1);

    printf("设置模块为从模式\n");
    CC2541_Send_CMD("AT+ROLE0\r\n",1);

    //should delay between two commands.
    BlueTooth_Delay(1000);

    printf("设置模块配对码为123456\n");
    CC2541_Send_CMD("AT+PIN123456\r\n",1);

	while(1){
		//Usart_SendString((uint8_t*)"AT+NAME RAYRAY-RT\r\n");
		//BlueTooth_Delay(1000);
		clean_rebuff();
		wai_sem(SEM_DISP);
		get_rebuff(&len);
		printf("received buffer: %s", buff);
		if(strstr(buff,"OK")){
			set=0;
		}else{
			set=1;
		}
		snd_dtq(DTQ_DISP, set);
		sig_sem(SEM_DISP);
		printf("BlueTooth Idle\n");
		dly_tsk(1000000);
	}

	cSerialPort_close();
}

/* #[<ENTRY_PORT>]# eBlueTooth
 * entry port: eBlueTooth
 * signature:  sBlueTooth
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eBlueTooth_blueToothInitialize
 * name:         eBlueTooth_blueToothInitialize
 * global_name:  tBlueTooth_eBlueTooth_blueToothInitialize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eBlueTooth_blueToothInitialize()
{

}

/* #[<POSTAMBLE>]#
 *   Put non-entry functions below.
 * #[</POSTAMBLE>]#*/
