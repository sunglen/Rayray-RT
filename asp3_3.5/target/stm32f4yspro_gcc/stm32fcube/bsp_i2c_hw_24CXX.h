#ifndef BSP_I2C_HW_24CXX_H_
#define BSP_I2C_HW_24CXX_H_

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

//EEPROM24c02相关函数
u8 AT24C02_ReadByte(u8 ReadAddr);							     //指定地址读取一个字节
void AT24C02_WriteByte(u8 WriteAddr,u8 DataToWrite);		//指定地址写入一个字节

void AT24C02_Write(u8 WriteAddr,u8 *pBuffer,u8 WriteNum);	//从指定地址开始写入指定长度的数据
void AT24C02_Read(u8 ReadAddr,u8 *pBuffer,u8 ReadNum);   	//从指定地址开始读出指定长度的数据

u8 AT24C02_Test(u8 Addr, u8 DataIn, u8* DataOut, u8 ReadOnly);  //检查器件
void AT24C02_Init(void); //初始化IIC

#endif /* BSP_I2C_HW_24CXX_H_ */
