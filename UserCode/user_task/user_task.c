#include "user_task.h"


void TASK_LED1_Blinky(void *gh)
{

	for( ; ; )
    {
		IWDT_Clr();             //��ϵͳ���Ź�		
   
       LED0_ON;
		TicksDelayMs( 300, NULL );//�����ʱ			
      LED0_OFF;	            //LED0��˸
		TicksDelayMs( 300, NULL );//�����ʱ 
    }	



}

void TASK_LED2_Blinky(void *gh)
{

	for( ; ; )
    {
		IWDT_Clr();             //��ϵͳ���Ź�		
   
      LED1_ON;
		TicksDelayMs( 200, NULL );//�����ʱ				
       LED1_OFF;	            //LED0��˸
		TicksDelayMs( 200, NULL );//�����ʱ
    }	



}







