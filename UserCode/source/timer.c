#include "general.h"


volatile  uint32_t waitResponseTimer;//�ط��жϼ�ʱ��

#include "FreeRTOS.h"
#include "semphr.h"
#include "timers.h"
#include "event_groups.h"


/*��ʱ����ʱ����*/
volatile  uint08 second;
volatile  uint08 minute;
volatile  uint08 hour;
volatile  uint16 day;
volatile  uint16 year;
volatile  uint32 Timer0Tick = 0;
volatile  uint08 genneralWaitTime = 0;//�س��Խ���ȴ�ʱ��
volatile  uint08 chgScrTimer = 0;//����7777/������Կʱ�鿴�ĵ�ַ�Զ�����ʱ��ʱ�����

static volatile uint16 BuzzerTimer = 0;//����ͬʱʹ�øü���������15�붨ʱ��1.5�붨ʱ//��������
volatile uint16 HMIBuzzerTimer = 0;//���ڶ�ʱ����ʱ����buzzer����,��λ:��
static volatile uint32 TimerCnt = 0;//��ѭ����ʱ����
volatile uint08 KeyInputModeTimer = 0;//������ʾģʽ��ʱ��������ʱ����ʱ���������û��û������û�����룬���������buff�е����� 


extern SemaphoreHandle_t semaphore;
extern BaseType_t xHigherPriorityTaskWoken;
extern QueueHandle_t xIntegerQueue;
extern EventGroupHandle_t xEventGroup;


void ETIM1_IRQHandler(void)
{
	if(SET == ETIMx_ETxIF_OVIF_Chk(ETIM1))
	{
		ETIMx_ETxIF_OVIF_Clr(ETIM1);
		//LED_TOG;	
	}
}

void ETIM2_IRQHandler(void)
{
	if(SET == ETIMx_ETxIF_OVIF_Chk(ETIM2))
	{
		ETIMx_ETxIF_OVIF_Clr(ETIM2);
		//LED_TOG;	
	}
}
	
void ETIM3_IRQHandler(void)
{
	if(SET == ETIMx_ETxIF_OVIF_Chk(ETIM3))
	{
		ETIMx_ETxIF_OVIF_Clr(ETIM3);
		//LED0_TOG;	
	}
}

#if 0

void ETIM4_IRQHandler(void)
{
	if(SET == ETIMx_ETxIF_OVIF_Chk(ETIM4))
	{
		ETIMx_ETxIF_OVIF_Clr(ETIM4);
		LED0_TOG;	
	}
}

#else


void ETIM4_IRQHandler(void)
{
	static uint32_t ulParameterValue = 0;
	BaseType_t ret;
	
	if(SET == ETIMx_ETxIF_OVIF_Chk(ETIM4))
	{
		ETIMx_ETxIF_OVIF_Clr(ETIM4);
		
	if(++Timer0Tick%ms20 == 0)
	{
		//xTimerPendFunctionCallFromISR(interruptHandle, NULL, ulParameterValue++, &xHigherPriorityTaskWoken);		
		//sprintf(string, "para:%d\n", ulParameterValue);
		//uart_send(PRINTF_UART, string, strlen(string));
		//BaseType_t ret = xQueueSendToBackFromISR(xIntegerQueue, &ulParameterValue, &xHigherPriorityTaskWoken);
		//if(ret == errQUEUE_FULL)
		//{
		//sprintf(string, "full queue\n");
		//uart_send(PRINTF_UART, string, strlen(string));
		//myprintf("full queue\n");
		//}
		//ulParameterValue++;
		//#define task3bit (0x01<<2)
		//xEventGroupSetBitsFromISR(xEventGroup, task3bit, &xHigherPriorityTaskWoken);
		
		//portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

/*	
		xSemaphoreGiveFromISR(semaphore, &xHigherPriorityTaskWoken);
		if(xHigherPriorityTaskWoken == pdPASS)
		{
			portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
		}
		else{
			ALARM_R_BLINK;			
		}
*/		
	}
	if(Timer0Tick%IntOneSecond == 0)
	{
	ALARM_R_BLINK;
	//#define task3bit (0x01<<2)
	//xEventGroupSetBitsFromISR(xEventGroup, task3bit, &xHigherPriorityTaskWoken);
	//if(xHigherPriorityTaskWoken == pdPASS)
	//{
	//myprintf("ISR set bit\n");
	//}
	//portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	}	
	++waitResponseTimer;
	
	}
}

#endif



/******************
����:ETIMxָ����ʱ��; 
	 howlong��ʱʱ�䳤��(��λ����)
���:��
����:��
˵��:8M 100��Ƶÿ������������ʱ~820ms,��̶�ʱԼ12us
********************/
void TimerInit(ETIMx_Type* ETIMx, uint16 howlong)
{

	ETIM_InitTypeDef init_para;
	volatile uint08 EtimNum;

	EtimNum = ((uint32_t)ETIMx - ETIMER1_BASE)>>5;
	
	//�ź�Դ����
	init_para.sig_src_para.SIG1SEL = ETIMx_ETxINSEL_SIG1SEL_GROUP1;		/* �ڲ��ź�1Դѡ��GROUP1 */
	init_para.sig_src_para.SIG2SEL = ETIMx_ETxINSEL_SIG2SEL_GROUP1;		/* �ڲ��ź�2Դѡ��GROUP1 */

        //�ź�Դ����
	init_para.sig_src_para.GRP1SEL = ETIMx_ETxINSEL_GRP1SEL_ET1234_APBCLK;		/* GROUP1 �ź�ѡ��APBCLK */
	init_para.sig_src_para.GRP2SEL = ETIMx_ETxINSEL_GRP2SEL_ET1_XTLF<<(EtimNum>>1);		/* GROUP2 �ź�ѡ��XTLF */        
        //ET1ʱ��ʹ��	
	RCC_PERCLK_SetableEx(ET1CLK+(uint32)EtimNum, ENABLE);		
        //NVIC�ж�����
	NVIC_DisableIRQ(ETIM1_IRQn+EtimNum);
	NVIC_SetPriority(ETIM1_IRQn+EtimNum, 1);//�ж����ȼ�����
	NVIC_EnableIRQ(ETIM1_IRQn+EtimNum);		

	/*����ʱ�ӷ�Ƶ*/
	init_para.sig_src_para.PRESCALE1 = clkmode - 1 + 99;    //100��Ƶ	/* ETxԤ��Ƶ�Ĵ���1 */ 00��ʾ1��Ƶ��FF��ʾ256��Ƶ
	init_para.sig_src_para.PRESCALE2 = clkmode - 1;    		//1��Ƶ		/* ETxԤ��Ƶ�Ĵ���2 */ 00��ʾ1��Ƶ��FF��ʾ256��Ƶ
	
	
	//���������
	init_para.ctrl_para.EXFLT = ENABLE;								/* �������������˲�ʹ�ܴ� */
	init_para.ctrl_para.MOD = ETIMx_ETxCR_MOD_COUNTER;				/* ����ģʽѡ�����ģʽ */
	init_para.ctrl_para.CASEN = DISABLE;							/* ��չ��ʱ�������ر� */
	init_para.ctrl_para.EDGESEL = ETIMx_ETxCR_EDGESEL_RISING;		/* ����ģʽ���ط�ʽѡ�񣨼���ʱ��ѡ��mcu_clkʱ��λ��Ч�����ǲ���mcu_clkʱ�������ؼ����� */

	init_para.ctrl_para.PWM = DISABLE;								/* PWM����ر� */

	init_para.ctrl_para.CAPMOD = ETIMx_ETxCR_CAPMOD_PERIOD;			/* ��׽ģʽ���� */
	init_para.ctrl_para.CAPCLR = DISABLE;							/* �����㲶׽ģʽ���� */
	init_para.ctrl_para.CAPONCE = DISABLE;							/* ���β�׽���� */
	init_para.ctrl_para.CAPEDGE = ETIMx_ETxCR_CAPEDGE_RISING;		/* ��׽��ѡ�� */

	init_para.ctrl_para.CMPIE = DISABLE;		/* ��չ��ʱ���Ƚ��ж�ʹ�� */
	init_para.ctrl_para.CAPIE = DISABLE;		/* ��չ��ʱ����׽�ж�ʹ�� */
	init_para.ctrl_para.OVIE = ENABLE;			/* ��չ��ʱ������ж�ʹ�� */

	init_para.ctrl_para.INITVALUE = 0xffff - (mSecond*howlong); //������ֵ��8000000��100��Ƶ ���� 8000������ = 100ms ;		/* ETx��ֵ�Ĵ��� */
	init_para.ctrl_para.CMP = 0;			/* ETx�ȽϼĴ��� */
	
	init_para.ctrl_para.CEN = DISABLE;		/* �������� */
	
	//��ʼ��ETIM
	ETIMx_Init(ETIMx, &init_para);
	
	ETIMx_ETxCR_CEN_Setable(ETIMx, ENABLE);	//������ʱ��
	
}


//ǰ�ö���TimerInit()
//��ʱhowlong����
void setTime(ETIMx_Type* ETIMx, uint16 howlong)
{
	uint16 time = (0xFFFF-mSecond*howlong);
	
	ETIMx_ETxCR_CEN_Setable(ETIMx, DISABLE);	//������ʱ��
	ETIMx_ETxIF_OVIF_Clr(ETIMx);
	ETIMx_ETxIVR_Write(ETIMx, time);	/* ETx��ֵ�Ĵ��� */	
	ETIMx_ETxCR_CEN_Setable(ETIMx, ENABLE);	//������ʱ��
}



void timerHandle(void)
{}


int testTimer (void)
{		

	TimerInit(ETIM4, 50);

	TicksDelayMs(1500, NULL);

	setTime(ETIM4, 500);
	
	for( ; ; )
    {
		IWDT_Clr();             //��ϵͳ���Ź�	
		
//        LED0_TOG;	            //LED0
		TicksDelayMs(50, NULL );//�����ʱ
    }	
}




