/**
  ******************************************************************************
  * 文件名程: bsp_spiflash.c
  * 作    者: 硬石嵌入式开发团队
  * 版    本: V1.0
  * 编写日期: 2017-03-30
  * 功    能: 板载串行Flash底层驱动实现
  ******************************************************************************
  * 说明：
  * 本例程配套硬石stm32开发板YS-F4Pro使用。
  *
  * 淘宝：
  * 论坛：http://www.ing10bbs.com
  * 版权归硬石嵌入式开发团队所有，请勿商用。
  ******************************************************************************
  */

/* 包含头文件 ----------------------------------------------------------------*/
#include "bsp_spiflash.h"

#if 0
#include "ff.h"
#include "ff_gen_drv.h"
#include "spiflash_diskio.h"
#include "string.h"

extern Diskio_drvTypeDef  SPIFLASH_Driver;
typedef char TCHAR;

/* 私有类型定义 --------------------------------------------------------------*/
/* 私有宏定义 ----------------------------------------------------------------*/
/* 私有变量 ------------------------------------------------------------------*/
char SPIFLASH_Path[4];            /* 串行Flash逻辑设备路径 */
FATFS fs;													/* FatFs文件系统对象 */
FIL file;													/* 文件对象 */
FRESULT f_res;                    /* 文件操作结果 */
UINT fnum;            					  /* 文件成功读写数量 */
char fpath[100];                  /* 保存当前扫描路径 */
char readbuffer[512];
DIR dir;

/* 扩展变量 ------------------------------------------------------------------*/
/* 私有函数原形 --------------------------------------------------------------*/
static void printf_fatfs_error(FRESULT fresult);
static FRESULT miscellaneous(void);
static FRESULT file_check(void);
static FRESULT scan_files (char* path);

int BSP_SPIFlash_SimpleTest(void)
{
	char SPIFLASHPath[4];             /* 串行Flash逻辑设备路径 */
	BYTE ReadBuffer[1024]={0};        /* 读缓冲区 */
	BYTE WriteBuffer[]= "TOPPERS/ASP3 + TECS + FATFS 文件系统测试文件\n";/* 写缓冲区*/

	  /* 注册一个FatFS设备：串行FLASH */
	  if(FATFS_LinkDriver(&SPIFLASH_Driver, SPIFLASHPath) == 0)
	  {
	    /* 在串行FLASH挂载文件系统，文件系统挂载时会对串行FLASH初始化 */
	    f_res = f_mount(&fs,(TCHAR const*)SPIFLASHPath,1);
	    printf_fatfs_error(f_res);
	    /*----------------------- 格式化测试 ---------------------------*/
	    /* 如果没有文件系统就格式化创建创建文件系统 */
	    if(f_res == FR_NO_FILESYSTEM)
	    {
	      printf("》串行FLASH还没有文件系统，即将进行格式化...\n");
	      /* 格式化 */
	      f_res=f_mkfs((TCHAR const*)SPIFLASHPath,0,0);

	      if(f_res == FR_OK)
	      {
	        printf("》串行FLASH已成功格式化文件系统。\n");
	        /* 格式化后，先取消挂载 */
	        f_res = f_mount(NULL,(TCHAR const*)SPIFLASHPath,1);
	        /* 重新挂载	*/
	        f_res = f_mount(&fs,(TCHAR const*)SPIFLASHPath,1);
	      }
	      else
	      {
	        printf("《《格式化失败。》》\n");
	        return f_res;
	      }
	    }
	    else if(f_res!=FR_OK)
	    {
	      printf("！！串行FLASH挂载文件系统失败。(%d)\n",f_res);
	      printf_fatfs_error(f_res);
	      return f_res;
	    }
	    else
	    {
	      printf("》文件系统挂载成功，可以进行读写测试\n");
	    }

	    /*----------------------- 文件系统测试：写测试 -----------------------------*/
	    /* 打开文件，如果文件不存在则创建它 */
	    printf("****** 即将进行文件写入测试... ******\n");
	    f_res = f_open(&file, "FatFsTestFile.txt",FA_CREATE_ALWAYS | FA_WRITE );
	    if ( f_res == FR_OK )
	    {
	      printf("》打开/创建FatFsTestFile.txt文件成功，向文件写入数据。\n");
	      /* 将指定存储区内容写入到文件内 */
	      f_res=f_write(&file,WriteBuffer,sizeof(WriteBuffer),&fnum);
	      if(f_res==FR_OK)
	      {
	        printf("》文件写入成功，写入字节数据：%d\n",fnum);
	        printf("》向文件写入的数据为：\n%s\n",WriteBuffer);
	      }
	      else
	      {
	        printf("！！文件写入失败：(%d)\n",f_res);
	      }
	      /* 不再读写，关闭文件 */
	      f_close(&file);
	    }
	    else
	    {
	      printf("！！打开/创建文件失败。\n");
	    }

	    /*------------------- 文件系统测试：读测试 ------------------------------------*/
	    printf("****** 即将进行文件读取测试... ******\n");
	    f_res = f_open(&file, "FatFsTestFile.txt", FA_OPEN_EXISTING | FA_READ);
	    if(f_res == FR_OK)
	    {
	      printf("》打开文件成功。\n");
	      f_res = f_read(&file, ReadBuffer, sizeof(ReadBuffer), &fnum);
	      if(f_res==FR_OK)
	      {
	        printf("》文件读取成功,读到字节数据：%d\n",fnum);
	        printf("》读取得的文件数据为：\n%s \n", ReadBuffer);
	      }
	      else
	      {
	        printf("！！文件读取失败：(%d)\n",f_res);
	      }
	    }
	    else
	    {
	      printf("！！打开文件失败。\n");
	    }
	    /* 不再读写，关闭文件 */
	    f_close(&file);

	    printf("\n*************** 文件信息获取测试 **************\r\n");
	    f_res = file_check();

	    printf("***************** 文件扫描测试 ****************\r\n");
	    strcpy(fpath,SPIFLASHPath);
	    scan_files(fpath);

	    /* 不再使用，取消挂载 */
	    f_res = f_mount(NULL,(TCHAR const*)SPIFLASHPath,1);
	  }

	  /* 注销一个FatFS设备：串行FLASH */
	  FATFS_UnLinkDriver(SPIFLASHPath);

	  return 0;
}


int BSP_SPIFlash_Makefs(void)
{
	/* 注册一个FatFS设备：串行FLASH */
	if(FATFS_LinkDriver(&SPIFLASH_Driver, SPIFLASH_Path) == 0)
	{
	  /* 在串行FLASH挂载文件系统，文件系统挂载时会对串行FLASH初始化 */
	  f_res = f_mount(&fs,(TCHAR const*)SPIFLASH_Path,1);
	  printf_fatfs_error(f_res);
	  /*----------------------- 格式化测试 ---------------------------*/
	  /* 如果没有文件系统就格式化创建创建文件系统 */
	  if(f_res == FR_NO_FILESYSTEM)
	  {
		printf("》串行FLASH还没有文件系统，即将进行格式化...\n");
		/* 格式化 */
		f_res=f_mkfs((TCHAR const*)SPIFLASH_Path,0,0);

		if(f_res == FR_OK)
		{
		  printf("》串行FLASH已成功格式化文件系统。\n");
		  /* 格式化后，先取消挂载 */
		  f_res = f_mount(NULL,(TCHAR const*)SPIFLASH_Path,1);
		  /* 重新挂载	*/
		  f_res = f_mount(&fs,(TCHAR const*)SPIFLASH_Path,1);
		}
		else
		{
		  printf("《《格式化失败。》》\n");
		  return f_res;
		}
	  }
	  else if(f_res!=FR_OK)
	  {
		printf_fatfs_error(f_res);
		return f_res;
	  }
	  else
	  {
		printf("》文件系统可以进行读写测试\n");
	  }

	  f_mount(NULL,(TCHAR const*)SPIFLASH_Path,1);
	  FATFS_UnLinkDriver(SPIFLASH_Path);
	}

	return 0;
}

/**
  * 函数功能: 主函数.
  * 输入参数: 无
  * 返 回 值: 无
  * 说    明: 无
  */
int BSP_SPIFlash_Test(void)
{
  printf("****** 这是一个基于串行Flash的FatFS文件系统功能使用 ******\n");

  /* 注册一个FatFS设备：串行Flash */
  if(FATFS_LinkDriver(&SPIFLASH_Driver, SPIFLASH_Path) == 0)
  {
    //在串行Flash挂载文件系统，文件系统挂载时会对串行Flash初始化
    f_res = f_mount(&fs,(TCHAR const*)SPIFLASH_Path,1);
    printf_fatfs_error(f_res);
    if(f_res!=FR_OK)
    {
      printf("！！串行Flash挂载文件系统失败。\n");
      return f_res;
    }
    else
    {
      printf("》串行Flash文件系统挂载成功，可以进行测试。\n");
    }

    /* FatFs多项功能测试 */
    f_res = miscellaneous();

    printf("\n*************** 文件信息获取测试 **************\r\n");
    f_res = file_check();

    printf("***************** 文件扫描测试 ****************\r\n");
    strcpy(fpath,SPIFLASH_Path);
    scan_files(fpath);

    /* 不再使用，取消挂载 */
    f_res = f_mount(NULL,(TCHAR const*)SPIFLASH_Path,1);
  }

  /* 注销一个FatFS设备：串行Flash */
  FATFS_UnLinkDriver(SPIFLASH_Path);

  return 0;
}

/**
  * 函数功能: FatFS文件系统操作结果信息处理.
  * 输入参数: FatFS文件系统操作结果：FRESULT
  * 返 回 值: 无
  * 说    明: 无
  */
static void printf_fatfs_error(FRESULT fresult)
{
  switch(fresult)
  {
    case FR_OK:                   //(0)
      printf("》操作成功。\n");
    break;
    case FR_DISK_ERR:             //(1)
      printf("！！硬件输入输出驱动出错。\n");
    break;
    case FR_INT_ERR:              //(2)
      printf("！！断言错误。\n");
    break;
    case FR_NOT_READY:            //(3)
      printf("！！物理设备无法工作。\n");
    break;
    case FR_NO_FILE:              //(4)
      printf("！！无法找到文件。\n");
    break;
    case FR_NO_PATH:              //(5)
      printf("！！无法找到路径。\n");
    break;
    case FR_INVALID_NAME:         //(6)
      printf("！！无效的路径名。\n");
    break;
    case FR_DENIED:               //(7)
    case FR_EXIST:                //(8)
      printf("！！拒绝访问。\n");
    break;
    case FR_INVALID_OBJECT:       //(9)
      printf("！！无效的文件或路径。\n");
    break;
    case FR_WRITE_PROTECTED:      //(10)
      printf("！！逻辑设备写保护。\n");
    break;
    case FR_INVALID_DRIVE:        //(11)
      printf("！！无效的逻辑设备。\n");
    break;
    case FR_NOT_ENABLED:          //(12)
      printf("！！无效的工作区。\n");
    break;
    case FR_NO_FILESYSTEM:        //(13)
      printf("！！无效的文件系统。\n");
    break;
    case FR_MKFS_ABORTED:         //(14)
      printf("！！因函数参数问题导致f_mkfs函数操作失败。\n");
    break;
    case FR_TIMEOUT:              //(15)
      printf("！！操作超时。\n");
    break;
    case FR_LOCKED:               //(16)
      printf("！！文件被保护。\n");
    break;
    case FR_NOT_ENOUGH_CORE:      //(17)
      printf("！！长文件名支持获取堆空间失败。\n");
    break;
    case FR_TOO_MANY_OPEN_FILES:  //(18)
      printf("！！打开太多文件。\n");
    break;
    case FR_INVALID_PARAMETER:    // (19)
      printf("！！参数无效。\n");
    break;
  }
}


/* FatFs多项功能测试 */
static FRESULT miscellaneous(void)
{
  FATFS *pfs;
  DWORD fre_clust, fre_sect, tot_sect;

  printf("\n*************** 设备信息获取 ***************\r\n");
  /* 获取设备信息和空簇大小 */
  f_res = f_getfree((TCHAR const*)SPIFLASH_Path, &fre_clust, &pfs);

  /* 计算得到总的扇区个数和空扇区个数 */
  tot_sect = (pfs->n_fatent - 2) * pfs->csize;
  fre_sect = fre_clust * pfs->csize;

  /* 打印信息(4096 字节/扇区) */
  printf("》设备总空间：%10lu KB。\n》可用空间：  %10lu KB。\n", tot_sect *4, fre_sect *4);

  printf("\n******** 文件定位和格式化写入功能测试 ********\r\n");
  f_res = f_open(&file, "FatFsTestFile.txt",
		  FA_CREATE_NEW|FA_WRITE|FA_READ);
  printf("f_res=%d",f_res);
	if ( f_res == FR_OK )
	{
    /*  文件定位 */
    f_res = f_lseek(&file,f_size(&file)-1);
    if (f_res == FR_OK)
    {
      /* 格式化写入，参数格式类似printf函数 */
      f_printf(&file,"\n在原来文件新添加一行内容\n");
      f_printf(&file,"》设备总空间：%10lu KB。\n》可用空间：  %10lu KB。\n", tot_sect *4, fre_sect *4);
      /*  文件定位到文件起始位置 */
      f_res = f_lseek(&file,0);
      /* 读取文件所有内容到缓存区 */
      f_res = f_read(&file,readbuffer,f_size(&file),&fnum);
      if(f_res == FR_OK)
      {
        printf("》文件内容：\n%s\n",readbuffer);
      }
    }
    f_close(&file);

    printf("\n********** 目录创建和重命名功能测试 **********\r\n");
    /* 尝试打开目录 */
    f_res=f_opendir(&dir,"TestDir");
    if(f_res!=FR_OK)
    {
      /* 打开目录失败，就创建目录 */
      f_res=f_mkdir("TestDir");
    }
    else
    {
      /* 如果目录已经存在，关闭它 */
      f_res=f_closedir(&dir);
      /* 删除文件 */
      f_unlink("TestDir/testdir.txt");
    }
    if(f_res==FR_OK)
    {
      /* 重命名并移动文件 */
      f_res=f_rename("FatFsTestFile.txt","TestDir/testdir.txt");
    }
	}
  else
  {
    printf("!! 打开文件失败：%d\n",f_res);
    printf("!! 或许需要再次运行“FatFs移植与读写测试”工程\n");
  }
  return f_res;
}


/**
  * 文件信息获取
  */
static FRESULT file_check(void)
{
  static FILINFO finfo;
  /* 获取文件信息 */
  //f_res=f_stat("TestDir/testdir.txt",&finfo);
  f_res=f_stat("FatFsTestFile.txt",&finfo);
  if(f_res==FR_OK)
  {
    printf("“FatFsTestFile.txt”文件信息：\n");
    printf("》文件大小: %ld(字节)\n", finfo.fsize);
    printf("》时间戳: %u/%02u/%02u, %02u:%02u\n",
           (finfo.fdate >> 9) + 1980, finfo.fdate >> 5 & 15, finfo.fdate & 31,finfo.ftime >> 11, finfo.ftime >> 5 & 63);
    printf("》属性: %c%c%c%c%c\n\n",
           (finfo.fattrib & AM_DIR) ? 'D' : '-',      // 是一个目录
           (finfo.fattrib & AM_RDO) ? 'R' : '-',      // 只读文件
           (finfo.fattrib & AM_HID) ? 'H' : '-',      // 隐藏文件
           (finfo.fattrib & AM_SYS) ? 'S' : '-',      // 系统文件
           (finfo.fattrib & AM_ARC) ? 'A' : '-');     // 档案文件
  }
  return f_res;
}

/**
  * @brief  scan_files 递归扫描FatFs内的文件
  * @param  path:初始扫描路径
  * @retval result:文件系统的返回值
  */
static FRESULT scan_files (char* path)
{
  FRESULT res; 		//部分在递归过程被修改的变量，不用全局变量
  FILINFO fno;
  int i;
  char *fn;        // 文件名

#if _USE_LFN
  /* 长文件名支持 */
  /* 简体中文需要2个字节保存一个“字”*/
  static char lfn[_MAX_LFN*2 + 1];
  fno.lfname = lfn;
  fno.lfsize = sizeof(lfn);
#endif
  //打开目录
  res = f_opendir(&dir, path);
  if (res == FR_OK)
	{
    i = strlen(path);
    for (;;)
		{
      //读取目录下的内容，再读会自动读下一个文件
      res = f_readdir(&dir, &fno);
      //为空时表示所有项目读取完毕，跳出
      if (res != FR_OK || fno.fname[0] == 0) break;
#if _USE_LFN
      fn = *fno.lfname ? fno.lfname : fno.fname;
#else
      fn = fno.fname;
#endif
      //点表示当前目录，跳过
      if (*fn == '.') continue;
      //目录，递归读取
      if (fno.fattrib & AM_DIR)
			{
        //合成完整目录名
        sprintf(&path[i], "/%s", fn);
        //递归遍历
        res = scan_files(path);
        path[i] = 0;
        //打开失败，跳出循环
        if (res != FR_OK)
					break;
      }
			else
			{
				printf("%s/%s\n", path, fn);								//输出文件名
        /* 可以在这里提取特定格式的文件路径 */
      }//else
    } //for
  }
  return res;
}

#endif

/* 私有类型定义 --------------------------------------------------------------*/
/* 私有宏定义 ----------------------------------------------------------------*/
#define SPI_FLASH_PageSize              256
#define SPI_FLASH_PerWritePageSize      256
#define W25X_WriteEnable		            0x06
#define W25X_WriteDisable		            0x04
#define W25X_ReadStatusReg		          0x05
#define W25X_WriteStatusReg		          0x01
#define W25X_ReadData			              0x03
#define W25X_FastReadData		            0x0B
#define W25X_FastReadDual		            0x3B
#define W25X_PageProgram		            0x02
#define W25X_BlockErase			            0xD8
#define W25X_SectorErase		            0x20
#define W25X_ChipErase			            0xC7
#define W25X_PowerDown			            0xB9
#define W25X_ReleasePowerDown	          0xAB
#define W25X_DeviceID			              0xAB
#define W25X_ManufactDeviceID   	      0x90
#define W25X_JedecDeviceID		          0x9F

#define WIP_Flag                        0x01  /* Write In Progress (WIP) flag */

#define Dummy_Byte                      0xFF

/* 私有变量 ------------------------------------------------------------------*/
SPI_HandleTypeDef hspiflash;

/* 扩展变量 ------------------------------------------------------------------*/
/* 私有函数原形 --------------------------------------------------------------*/
/* 函数体 --------------------------------------------------------------------*/

/**
  * 函数功能: 串行FLASH初始化
  * 输入参数: huart：串口句柄类型指针
  * 返 回 值: 无
  * 说    明: 该函数被HAL库内部调用
*/
void BSP_SPIFlash_Init(void)
{
  hspiflash.Instance = FLASH_SPIx;
  hspiflash.Init.Mode = SPI_MODE_MASTER;
  hspiflash.Init.Direction = SPI_DIRECTION_2LINES;
  hspiflash.Init.DataSize = SPI_DATASIZE_8BIT;
  hspiflash.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspiflash.Init.CLKPhase = SPI_PHASE_2EDGE;
  hspiflash.Init.NSS = SPI_NSS_SOFT;
  hspiflash.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspiflash.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspiflash.Init.TIMode = SPI_TIMODE_DISABLE;
  hspiflash.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspiflash.Init.CRCPolynomial = 10;
  HAL_SPI_Init(&hspiflash);
}

/**
  * 函数功能: SPI外设系统级初始化
  * 输入参数: hspi：SPI句柄类型指针
  * 返 回 值: 无
  * 说    明: 该函数被HAL库内部调用
  */
void HAL_SPI_MspInit(SPI_HandleTypeDef* hspi)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  if(hspi->Instance==FLASH_SPIx)
  {
    /* SPI外设时钟使能 */
    FLASH_SPIx_RCC_CLK_ENABLE();
    /* GPIO外设时钟使能 */
    FLASH_SPI_GPIO_ClK_ENABLE();

    GPIO_InitStruct.Pin = FLASH_SPI_SCK_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = FLASH_SPI_AF;
    HAL_GPIO_Init(FLASH_SPI_SCK_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = FLASH_SPI_MOSI_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = FLASH_SPI_AF;
    HAL_GPIO_Init(FLASH_SPI_MOSI_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = FLASH_SPI_MISO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Alternate = FLASH_SPI_AF;
    HAL_GPIO_Init(FLASH_SPI_MISO_PORT, &GPIO_InitStruct);

    HAL_GPIO_WritePin(FLASH_SPI_CS_PORT, FLASH_SPI_CS_PIN, GPIO_PIN_SET);
    GPIO_InitStruct.Pin = FLASH_SPI_CS_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    HAL_GPIO_Init(FLASH_SPI_CS_PORT, &GPIO_InitStruct);
  }
}

/**
  * 函数功能: SPI外设系统级反初始化
  * 输入参数: hspi：SPI句柄类型指针
  * 返 回 值: 无
  * 说    明: 该函数被HAL库内部调用
  */
void HAL_SPI_MspDeInit(SPI_HandleTypeDef* hspi)
{

  if(hspi->Instance==FLASH_SPIx)
  {
    /* SPI外设时钟禁用 */
    FLASH_SPIx_RCC_CLK_DISABLE();

    HAL_GPIO_DeInit(FLASH_SPI_MOSI_PORT, FLASH_SPI_MOSI_PIN);
    HAL_GPIO_DeInit(FLASH_SPI_MISO_PORT, FLASH_SPI_MISO_PIN);
    HAL_GPIO_DeInit(FLASH_SPI_SCK_PORT, FLASH_SPI_SCK_PIN);
    HAL_GPIO_DeInit(FLASH_SPI_CS_PORT, FLASH_SPI_CS_PIN);
  }
}


/**
  * 函数功能: 擦除扇区
  * 输入参数: SectorAddr：待擦除扇区地址，要求为4096倍数
  * 返 回 值: 无
  * 说    明：串行Flash最小擦除块大小为4KB(4096字节)，即一个扇区大小，要求输入参数
  *           为4096倍数。在往串行Flash芯片写入数据之前要求先擦除空间。
  */
void SPI_FLASH_SectorErase(uint32_t SectorAddr)
{
  /* 发送FLASH写使能命令 */
  SPI_FLASH_WriteEnable();
  SPI_FLASH_WaitForWriteEnd();
  /* 擦除扇区 */
  /* 选择串行FLASH: CS低电平 */
  FLASH_SPI_CS_ENABLE();
  /* 发送扇区擦除指令*/
  SPI_FLASH_SendByte(W25X_SectorErase);
  /*发送擦除扇区地址的高位*/
  SPI_FLASH_SendByte((SectorAddr & 0xFF0000) >> 16);
  /* 发送擦除扇区地址的中位 */
  SPI_FLASH_SendByte((SectorAddr & 0xFF00) >> 8);
  /* 发送擦除扇区地址的低位 */
  SPI_FLASH_SendByte(SectorAddr & 0xFF);
  /* 禁用串行FLASH: CS 高电平 */
  FLASH_SPI_CS_DISABLE();
  /* 等待擦除完毕*/
  SPI_FLASH_WaitForWriteEnd();
}

/**
  * 函数功能: 擦除整片
  * 输入参数: 无
  * 返 回 值: 无
  * 说    明：擦除串行Flash整片空间
  */
void SPI_FLASH_BulkErase(void)
{
 /* 发送FLASH写使能命令 */
  SPI_FLASH_WriteEnable();

  /* 整片擦除 Erase */
  /* 选择串行FLASH: CS低电平 */
  FLASH_SPI_CS_ENABLE();
  /* 发送整片擦除指令*/
  SPI_FLASH_SendByte(W25X_ChipErase);
  /* 禁用串行FLASH: CS高电平 */
  FLASH_SPI_CS_DISABLE();

  /* 等待擦除完毕*/
  SPI_FLASH_WaitForWriteEnd();
}

/**
  * 函数功能: 往串行FLASH按页写入数据，调用本函数写入数据前需要先擦除扇区
  * 输入参数: pBuffer：待写入数据的指针
  *           WriteAddr：写入地址
  *           NumByteToWrite：写入数据长度，必须小于等于SPI_FLASH_PerWritePageSize
  * 返 回 值: 无
  * 说    明：串行Flash每页大小为256个字节
  */
void SPI_FLASH_PageWrite(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{
  /* 发送FLASH写使能命令 */
  SPI_FLASH_WriteEnable();

   /* 寻找串行FLASH: CS低电平 */
  FLASH_SPI_CS_ENABLE();
  /* 写送写指令*/
  SPI_FLASH_SendByte(W25X_PageProgram);
  /*发送写地址的高位*/
  SPI_FLASH_SendByte((WriteAddr & 0xFF0000) >> 16);
  /*发送写地址的中位*/
  SPI_FLASH_SendByte((WriteAddr & 0xFF00) >> 8);
  /*发送写地址的低位*/
  SPI_FLASH_SendByte(WriteAddr & 0xFF);

  if(NumByteToWrite > SPI_FLASH_PerWritePageSize)
  {
     NumByteToWrite = SPI_FLASH_PerWritePageSize;
     //printf("Err: SPI_FLASH_PageWrite too large!\n");
  }

  /* 写入数据*/
  while (NumByteToWrite--)
  {
     /* 发送当前要写入的字节数据 */
    SPI_FLASH_SendByte(*pBuffer);
     /* 指向下一字节数据 */
    pBuffer++;
  }

  /* 禁用串行FLASH: CS 高电平 */
  FLASH_SPI_CS_DISABLE();

  /* 等待写入完毕*/
  SPI_FLASH_WaitForWriteEnd();
}

/**
  * 函数功能: 往串行FLASH写入数据，调用本函数写入数据前需要先擦除扇区
  * 输入参数: pBuffer：待写入数据的指针
  *           WriteAddr：写入地址
  *           NumByteToWrite：写入数据长度
  * 返 回 值: 无
  * 说    明：该函数可以设置任意写入数据长度
  */
void SPI_FLASH_BufferWrite(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite)
{
  uint8_t NumOfPage = 0, NumOfSingle = 0, Addr = 0, count = 0, temp = 0;

  Addr = WriteAddr % SPI_FLASH_PageSize;
  count = SPI_FLASH_PageSize - Addr;
  NumOfPage =  NumByteToWrite / SPI_FLASH_PageSize;
  NumOfSingle = NumByteToWrite % SPI_FLASH_PageSize;

  if (Addr == 0) /* 若地址与 SPI_FLASH_PageSize 对齐  */
  {
    if (NumOfPage == 0) /* NumByteToWrite < SPI_FLASH_PageSize */
    {
      SPI_FLASH_PageWrite(pBuffer, WriteAddr, NumByteToWrite);
    }
    else /* NumByteToWrite > SPI_FLASH_PageSize */
    {
      while (NumOfPage--)
      {
        SPI_FLASH_PageWrite(pBuffer, WriteAddr, SPI_FLASH_PageSize);
        WriteAddr +=  SPI_FLASH_PageSize;
        pBuffer += SPI_FLASH_PageSize;
      }

      SPI_FLASH_PageWrite(pBuffer, WriteAddr, NumOfSingle);
    }
  }
  else /* 若地址与 SPI_FLASH_PageSize 不对齐 */
  {
    if (NumOfPage == 0) /* NumByteToWrite < SPI_FLASH_PageSize */
    {
      if (NumOfSingle > count) /* (NumByteToWrite + WriteAddr) > SPI_FLASH_PageSize */
      {
        temp = NumOfSingle - count;

        SPI_FLASH_PageWrite(pBuffer, WriteAddr, count);
        WriteAddr +=  count;
        pBuffer += count;

        SPI_FLASH_PageWrite(pBuffer, WriteAddr, temp);
      }
      else
      {
        SPI_FLASH_PageWrite(pBuffer, WriteAddr, NumByteToWrite);
      }
    }
    else /* NumByteToWrite > SPI_FLASH_PageSize */
    {
      NumByteToWrite -= count;
      NumOfPage =  NumByteToWrite / SPI_FLASH_PageSize;
      NumOfSingle = NumByteToWrite % SPI_FLASH_PageSize;

      SPI_FLASH_PageWrite(pBuffer, WriteAddr, count);
      WriteAddr +=  count;
      pBuffer += count;

      while (NumOfPage--)
      {
        SPI_FLASH_PageWrite(pBuffer, WriteAddr, SPI_FLASH_PageSize);
        WriteAddr +=  SPI_FLASH_PageSize;
        pBuffer += SPI_FLASH_PageSize;
      }

      if (NumOfSingle != 0)
      {
        SPI_FLASH_PageWrite(pBuffer, WriteAddr, NumOfSingle);
      }
    }
  }
}

/**
  * 函数功能: 从串行Flash读取数据
  * 输入参数: pBuffer：存放读取到数据的指针
  *           ReadAddr：读取数据目标地址
  *           NumByteToRead：读取数据长度
  * 返 回 值: 无
  * 说    明：该函数可以设置任意读取数据长度
  */
void SPI_FLASH_BufferRead(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead)
{
  /* 选择串行FLASH: CS低电平 */
  FLASH_SPI_CS_ENABLE();

  /* 发送 读 指令 */
  SPI_FLASH_SendByte(W25X_ReadData);

  /* 发送 读 地址高位 */
  SPI_FLASH_SendByte((ReadAddr & 0xFF0000) >> 16);
  /* 发送 读 地址中位 */
  SPI_FLASH_SendByte((ReadAddr& 0xFF00) >> 8);
  /* 发送 读 地址低位 */
  SPI_FLASH_SendByte(ReadAddr & 0xFF);

  while (NumByteToRead--) /* 读取数据 */
  {
     /* 读取一个字节*/
    *pBuffer = SPI_FLASH_SendByte(Dummy_Byte);
    /* 指向下一个字节缓冲区 */
    pBuffer++;
  }

  /* 禁用串行FLASH: CS 高电平 */
  FLASH_SPI_CS_DISABLE();
}

/**
  * 函数功能: 读取串行Flash型号的ID
  * 输入参数: 无
  * 返 回 值: uint32_t：串行Flash的型号ID
  * 说    明：  FLASH_ID      IC型号      存储空间大小
                0xEF3015      W25X16        2M byte
                0xEF4015	    W25Q16        4M byte
                0XEF4017      W25Q64        8M byte
                0XEF4018      W25Q128       16M byte  (YS-F4Pro开发板默认配置)
  */
uint32_t SPI_FLASH_ReadID(void)
{
  uint32_t Temp = 0, Temp0 = 0, Temp1 = 0, Temp2 = 0;

  /* 选择串行FLASH: CS低电平 */
  FLASH_SPI_CS_ENABLE();

  /* 发送命令：读取芯片型号ID */
  SPI_FLASH_SendByte(W25X_JedecDeviceID);

  /* 从串行Flash读取一个字节数据 */
  Temp0 = SPI_FLASH_SendByte(Dummy_Byte);

  /* 从串行Flash读取一个字节数据 */
  Temp1 = SPI_FLASH_SendByte(Dummy_Byte);

  /* 从串行Flash读取一个字节数据 */
  Temp2 = SPI_FLASH_SendByte(Dummy_Byte);

  /* 禁用串行Flash：CS高电平 */
  FLASH_SPI_CS_DISABLE();

  Temp = (Temp0 << 16) | (Temp1 << 8) | Temp2;
  return Temp;
}

/**
  * 函数功能: 读取串行Flash设备ID
  * 输入参数: 无
  * 返 回 值: uint32_t：串行Flash的设备ID
  * 说    明：
  */
uint32_t SPI_FLASH_ReadDeviceID(void)
{
  uint32_t Temp = 0;

  /* 选择串行FLASH: CS低电平 */
  FLASH_SPI_CS_ENABLE();

  /* 发送命令：读取芯片设备ID * */
  SPI_FLASH_SendByte(W25X_DeviceID);
  SPI_FLASH_SendByte(Dummy_Byte);
  SPI_FLASH_SendByte(Dummy_Byte);
  SPI_FLASH_SendByte(Dummy_Byte);

  /* 从串行Flash读取一个字节数据 */
  Temp = SPI_FLASH_SendByte(Dummy_Byte);

  /* 禁用串行Flash：CS高电平 */
  FLASH_SPI_CS_DISABLE();

  return Temp;
}

/**
  * 函数功能: 启动连续读取数据串
  * 输入参数: ReadAddr：读取地址
  * 返 回 值: 无
  * 说    明：Initiates a read data byte (READ) sequence from the Flash.
  *           This is done by driving the /CS line low to select the device,
  *           then the READ instruction is transmitted followed by 3 bytes
  *           address. This function exit and keep the /CS line low, so the
  *           Flash still being selected. With this technique the whole
  *           content of the Flash is read with a single READ instruction.
  */
void SPI_FLASH_StartReadSequence(uint32_t ReadAddr)
{
  /* Select the FLASH: Chip Select low */
  FLASH_SPI_CS_ENABLE();

  /* Send "Read from Memory " instruction */
  SPI_FLASH_SendByte(W25X_ReadData);

  /* Send the 24-bit address of the address to read from -----------------------*/
  /* Send ReadAddr high nibble address byte */
  SPI_FLASH_SendByte((ReadAddr & 0xFF0000) >> 16);
  /* Send ReadAddr medium nibble address byte */
  SPI_FLASH_SendByte((ReadAddr& 0xFF00) >> 8);
  /* Send ReadAddr low nibble address byte */
  SPI_FLASH_SendByte(ReadAddr & 0xFF);
}

/**
  * 函数功能: 从串行Flash读取一个字节数据
  * 输入参数: 无
  * 返 回 值: uint8_t：读取到的数据
  * 说    明：This function must be used only if the Start_Read_Sequence
  *           function has been previously called.
  */
uint8_t SPI_FLASH_ReadByte(void)
{
  uint8_t d_read,d_send=Dummy_Byte;
  if(HAL_SPI_TransmitReceive(&hspiflash,&d_send,&d_read,1,0xFFFFFF)!=HAL_OK)
    d_read=Dummy_Byte;

  return d_read;
}

/**
  * 函数功能: 往串行Flash读取写入一个字节数据并接收一个字节数据
  * 输入参数: byte：待发送数据
  * 返 回 值: uint8_t：接收到的数据
  * 说    明：无
  */
uint8_t SPI_FLASH_SendByte(uint8_t byte)
{
  uint8_t d_read,d_send=byte;
  if(HAL_SPI_TransmitReceive(&hspiflash,&d_send,&d_read,1,0xFFFFFF)!=HAL_OK)
    d_read=Dummy_Byte;

  return d_read;
}

/**
  * 函数功能: 使能串行Flash写操作
  * 输入参数: 无
  * 返 回 值: 无
  * 说    明：无
  */
void SPI_FLASH_WriteEnable(void)
{
  /* 选择串行FLASH: CS低电平 */
  FLASH_SPI_CS_ENABLE();

  /* 发送命令：写使能 */
  SPI_FLASH_SendByte(W25X_WriteEnable);

  /* 禁用串行Flash：CS高电平 */
  FLASH_SPI_CS_DISABLE();
}

/**
  * 函数功能: 等待数据写入完成
  * 输入参数: 无
  * 返 回 值: 无
  * 说    明：Polls the status of the Write In Progress (WIP) flag in the
  *           FLASH's status  register  and  loop  until write  opertaion
  *           has completed.
  */
void SPI_FLASH_WaitForWriteEnd(void)
{
  uint8_t FLASH_Status = 0;

  /* Select the FLASH: Chip Select low */
  FLASH_SPI_CS_ENABLE();

  /* Send "Read Status Register" instruction */
  SPI_FLASH_SendByte(W25X_ReadStatusReg);

  /* Loop as long as the memory is busy with a write cycle */
  do
  {
    /* Send a dummy byte to generate the clock needed by the FLASH
    and put the value of the status register in FLASH_Status variable */
    FLASH_Status = SPI_FLASH_SendByte(Dummy_Byte);
  }
  while ((FLASH_Status & WIP_Flag) == SET); /* Write in progress */

  /* Deselect the FLASH: Chip Select high */
  FLASH_SPI_CS_DISABLE();
}


/**
  * 函数功能: 进入掉电模式
  * 输入参数: 无
  * 返 回 值: 无
  * 说    明：无
  */
void SPI_Flash_PowerDown(void)
{
  /* Select the FLASH: Chip Select low */
  FLASH_SPI_CS_ENABLE();

  /* Send "Power Down" instruction */
  SPI_FLASH_SendByte(W25X_PowerDown);

  /* Deselect the FLASH: Chip Select high */
  FLASH_SPI_CS_DISABLE();
}

/**
  * 函数功能: 唤醒串行Flash
  * 输入参数: 无
  * 返 回 值: 无
  * 说    明：无
  */
void SPI_Flash_WAKEUP(void)
{
  /* Select the FLASH: Chip Select low */
  FLASH_SPI_CS_ENABLE();

  /* Send "Power Down" instruction */
  SPI_FLASH_SendByte(W25X_ReleasePowerDown);

  /* Deselect the FLASH: Chip Select high */
  FLASH_SPI_CS_DISABLE();
}

/******************* (C) COPYRIGHT 2015-2020 硬石嵌入式开发团队 *****END OF FILE****/

