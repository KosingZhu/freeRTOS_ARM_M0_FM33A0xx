#include "user_task.h"
#include "general.h"

uint32 uIDLERunCount = 0;
extern QueueHandle_t xQueue1, xQueue2;
extern QueueSetHandle_t xQueueSet;

#ifdef DEBUG
uint08 string[PRINT_LEN] = {0};
#endif //DEBUG



void TASK_LED1_Blinky(void *gh)
{

	//xTaskCreate(TASK_LED2_Blinky,"led1",1000,NULL,5,NULL);
	UBaseType_t len;
	BaseType_t xStatus;
	int lReceivedValue;
	QueueHandle_t xQueueThatContainsData;

	TickType_t xTicksToWait = pdMS_TO_TICKS(100);
	
	for( ; ; )
    {
		IWDT_Clr();             //清系统看门狗		
		
		LED0_ON;//红
		  //TicksDelayMs( 300, NULL );//软件延时
		  //vTaskDelay(pdMS_TO_TICKS(200));
		LED0_OFF;			  //LED0闪烁
		  //TicksDelayMs( 300, NULL );//软件延时 
		  //vTaskDelay(pdMS_TO_TICKS(200));
		  //vTaskPrioritySet(NULL, 1);

   		uIDLERunCount--;
		 xQueueThatContainsData = xQueueSelectFromSet(xQueueSet, portMAX_DELAY);
		 xStatus = xQueueReceive(xQueueThatContainsData, &lReceivedValue, 0);
		 
		 sprintf(string, "param:%d, %p\n", lReceivedValue, xQueueThatContainsData);
		 uart_send(PRINTF_UART, string, strlen(string));
		sprintf(string, "q1:%p, q2:%p\n", xQueue1, xQueue2);
		 uart_send(PRINTF_UART, string, strlen(string));
		/*
		len = uxQueueMessagesWaiting(xQueue);
		if(len == 0)
		{
			sprintf(string, "queue is empty.\n");
			uart_send(PRINTF_UART, string, strlen(string));			
			//continue;
		}
		else{
			sprintf(string, "len:%d\n", len);
			uart_send(PRINTF_UART, string, strlen(string));			
		}
		
		xStatus = xQueueReceive(xQueue, &lReceivedValue, xTicksToWait);
		if(xStatus == pdPASS)
		{
			sprintf(string, "param:%d\n", lReceivedValue);
			uart_send(PRINTF_UART, string, strlen(string));
		}
		*/
    }	
	vTaskDelete(NULL);//task must be deleted before reaching the end of its implement.

}

void TASK_LED2_Blinky(void *gh)
{
	TickType_t xLastWakeTime;
	BaseType_t xStatus;
	int i = 0;

	xLastWakeTime = xTaskGetTickCount();

	i = (uint08)gh;
	
	//for( i = 0; i < 5 ; i++)
	for( ; ; )
    {
		IWDT_Clr();             //清系统看门狗
		
		sprintf(string, (uint08*)gh);
		uart_send(PRINTF_UART, string, strlen(string));
		sprintf(string, "\n");
		uart_send(PRINTF_UART, string, strlen(string));
		//TicksDelayMs(200, NULL);
		vTaskDelay(pdMS_TO_TICKS(100));
		//portYIELD();
/*   
      LED1_ON;//key
	 // vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(200));
		//TicksDelayMs( 200, NULL );//软件延时
		 vTaskDelay(pdMS_TO_TICKS(100));
      LED1_OFF;	            //LED0闪烁      
	  
	 // vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(200));
		//TicksDelayMs( 200, NULL );//软件延时
		//vTaskPrioritySet(NULL, 1);
		 vTaskDelay(pdMS_TO_TICKS(100));
	 	if(i == 100)
			xStatus = xQueueSendToBack(xQueue1, &i, 0);
		else
			xStatus = xQueueSendToBack(xQueue2, &i, 0);
		
		if(xStatus !=  pdPASS)
		{
	sprintf(string, "send fail%d\n", i);
	uart_send(PRINTF_UART, string, strlen(string));
		}	
*/		
    }	
	vTaskDelete(NULL);//task must be deleted before reaching the end of its implement.

}





