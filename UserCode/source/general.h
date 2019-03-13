#ifndef _general_H
#define _general_H



typedef enum{
	FALSE = 0,
	TRUE
}BOOL;


#ifndef DEBUG			//flash.h还有定义
#define DEBUG  	1		//打开可以使用PRINTF_UART打印输出
#endif	//DEBUG

#ifndef FM33A0_MCU
#define FM33A0_MCU
#endif  //FM33A0_MCU

#define TIME_DELAY_5MS 		800		//主频时钟为8M时
#define TIME_DELAY_2P5MS 	400		//主频时钟为8M时


#define PRINT_LEN		(128)

//#define TRUE        (1)
//#define FALSE       (0)
#define true        TRUE
#define false       FALSE


#define ALARM_R_PORT			GPIOD	//	4
#define ALARM_R_PIN				GPIO_Pin_0

// alarm LED R
#define ALARM_R_ON      		GPIO_ResetBits(ALARM_R_PORT, ALARM_R_PIN)
#define ALARM_R_OFF     		GPIO_SetBits(ALARM_R_PORT, ALARM_R_PIN)
#define ALARM_R_BLINK           GPIO_ToggleBits(ALARM_R_PORT, ALARM_R_PIN)



#define LED_Flash(Times, LED)				\
do{											\
	for(uint08 i = 0; i < Times; i++)		\
	{										\
		LED##BLINK;							\
		TicksDelayMs(50, NULL);				\
	}										\
	LED##OFF;								\
}while(0)




#include "define_all.h"
#include "uart.h"
#include "myQueue.h"
#include "timer.h"



//#include "stack.h"



#define TRUE	1
#define FALSE	0
#define true 	TRUE
#define false	FALSE
#define TURE	TRUE



extern uint08 string[PRINT_LEN];


extern void interruptHandle(void* para1, uint32_t para2);



#endif

