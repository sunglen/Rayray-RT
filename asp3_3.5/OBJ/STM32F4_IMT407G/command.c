#include <kernel.h>
#include <t_syslog.h>
#include <stdio.h>
#include <t_stdlib.h>
#include <stdlib.h>

#include "device.h"
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "monitor.h"

#include "lwipopts.h"

/*
 *  デバイスコマンド番号
 */
#ifdef USE_PINGSEND
#define NUM_DEVICE_CMD   7
#else
#define NUM_DEVICE_CMD   6
#endif

static int_t led_func(int argc, char **argv);
static int_t cnc_func(int argc, char **argv);
static int_t sto_func(int argc, char **argv);
static int_t tmp_func(int argc, char **argv);
static int_t oled_func(int argc, char **argv);
#ifdef USE_PINGSEND
static int_t png_func(int argc, char **argv);
#endif
static int_t eeprom_func(int argc, char **argv);
static int_t tmc_func(int argc, char **argv);

/*
 *  デバイスコマンドテーブル
 */
static const COMMAND_INFO device_command_info[NUM_DEVICE_CMD] = {
	{"LED",		led_func},
	{"CNC",		cnc_func},
//	{"STO",		sto_func},
	{"TMP",		tmp_func},
#ifdef USE_PINGSEND
	{"PING",    png_func},
#endif
	{"OLED",	oled_func},
	{"EEPROM",	eeprom_func},
	{"TMC",	tmc_func},
};

static const char device_name[] = "DEVICE";
static const char device_help[] =
"  Device  LED (no) (on-1,off-0)  led   control\n"
"          CNC (direction) (cmd)  cnc   control\n"
//"          STO (sdc/flash) (cmd)  sto   control\n"
"          TMP (cmd) (cmd)  temperature control\n"
#ifdef USE_PINGSEND
"          PING addr              send  ping   \n"
#endif
"          OLED (cmd) (cmd) oled display control\n"
"          EEPROM (addr) (data) i2c hw eeprom test\n"
"          TMC (cmd) (cmd) tmc motor driver test\n";

static const uint16_t led_pattern[2] = {
	LED0_PIN, LED1_PIN, LED2_PIN
};

static COMMAND_LINK device_command_link = {
	NULL,
	NUM_DEVICE_CMD,
	device_name,
	NULL,
	device_help,
	&device_command_info[0]
};

static int a2i(char *str)
{
	int num = 0;

	while(*str >= '0' && *str <= '9'){
		num = num * 10 + *str++ - '0';
	}
	return num;
}

/*
 *  DEVICEコマンド設定関数
 */
void device_info_init(intptr_t exinf)
{
	setup_command(&device_command_link);
}

/*
 *  LED設定コマンド関数
 */
static int_t led_func(int argc, char **argv)
{
	int_t    arg1=0, arg2;
	uint16_t reg;

	if(argc < 3)
		return -1;
	arg1 = a2i(argv[1]);
	arg2 = a2i(argv[2]);
	if(arg1 >= 0 && arg1 <= 2){
		reg = led_in(arg1);
		if(arg2 != reg)
			led_out(arg1, arg2);
	}
	return 0;
}

/*
 *  CNCテストコマンド関数
 */
static int_t cnc_func(int argc, char **argv)
{
	int_t   arg1=0, arg2=0;

	if(argc > 1)
		arg1 = a2i(argv[1]);
	if(argc > 2)
		arg2 = a2i(argv[2]);

	cnc_digital(arg1);
	printf("cnc digital set value: %d\n", arg1);
	printf("cnc analog get value: %d\n", cnc_analog());

	printf("\n");
	return 0;
}

/*
 *  STORAGE テストコマンド関数
 */
static int_t sto_func(int argc, char **argv)
{
	int_t   arg1=0, arg2=0;

	if(argc > 1)
		arg1 = a2i(argv[1]);
	if(argc > 2)
		arg2 = a2i(argv[2]);

	flash_mkfs();
	flash_test();

	printf("\n");
	return 0;
}

/*
 *  温度読み出し テストコマンド関数
 */
static int_t tmp_func(int argc, char **argv)
{
	int_t   arg1=0, arg2=0;
	float temp=0.0;
	float decimal=0.0;

	if(argc > 1)
		arg1 = a2i(argv[1]);
	if(argc > 2)
		arg2 = a2i(argv[2]);

	temp=tmp_read();

	//unable to print float number by format %f.
	decimal=temp-(int)temp;
	printf("%d.%02d", (int)(temp), abs((int)(decimal*100)));

	printf("\n");
	return 0;
}


static int_t oled_func(int argc, char **argv)
{
	int_t   arg1=0, arg2=0;

	if(argc > 1)
		arg1 = a2i(argv[1]);
	if(argc > 2)
		arg2 = a2i(argv[2]);

	oled_test();

	return 0;
}

#ifdef USE_PINGSEND
/*
 *  PING送信マンド関数
 */
static int_t png_func(int argc, char **argv)
{
	const char *addr;
	uint32_t paddr = 0;
	int      a, i;

	if(argc < 2)
		return -1;
	addr = argv[1];
	for(i = a = 0 ; i < 4 ; addr++){
		if(*addr <= '9' && *addr >= '0'){
			a *= 10;
			a += *addr - '0';
		}
		else{
			paddr |= a << (i * 8);
			a = 0;
			i++;
		}
		if(*addr == 0)
			break;
	}
	set_pingaddr(paddr);
	return 0;
}
#endif

static int_t eeprom_func(int argc, char **argv)
{
	int_t   arg1=255, arg2=0XAB;
	uint8_t data, read_only=0;
	uint8_t failed;

	if(argc == 1){
		printf("usage: eeprom addr [data]\n");
		return -1;
	}

	if(argc == 2){
		read_only=1;
	}

	if(argc > 1)
		arg1 = a2i(argv[1]);
	if(argc > 2)
		arg2 = a2i(argv[2]);

	failed=i2c_hw_eeprom_test(arg1, arg2, &data, read_only);

	if(read_only){
		printf("i2c hardware eeprom read test: addr(0x%x)=%d\n", arg1, data);
	}else{
		printf("i2c hardware eeprom write test: addr(0x%x)=%d, ", arg1, data);
		if(failed){
			printf("failed.\n");
		}else{
			printf("passed.\n");
		}
	}

	return 0;
}

static int_t tmc_func(int argc, char **argv)
{
	int_t   arg1=0, arg2=0;

	if(argc > 1)
		arg1 = atoi(argv[1]);
	if(argc > 2)
		arg2 = atoi(argv[2]);

	tmc_test(arg1);

	return 0;
}
