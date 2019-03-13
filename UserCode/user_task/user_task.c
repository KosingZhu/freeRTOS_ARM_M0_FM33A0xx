#include "user_task.h"


void TASK_LED1_Blinky(void *gh)
{

	for( ; ; )
    {
		IWDT_Clr();             //清系统看门狗		
   
       LED0_ON;
		TicksDelayMs( 300, NULL );//软件延时			
      LED0_OFF;	            //LED0闪烁
		TicksDelayMs( 300, NULL );//软件延时 
    }	



}

void TASK_LED2_Blinky(void *gh)
{

	for( ; ; )
    {
		IWDT_Clr();             //清系统看门狗		
   
      LED1_ON;
		TicksDelayMs( 200, NULL );//软件延时				
       LED1_OFF;	            //LED0闪烁
		TicksDelayMs( 200, NULL );//软件延时
    }	



}







