#include "general.h"


volatile  uint32_t waitResponseTimer;//重发判断计时器

#include "FreeRTOS.h"
#include "semphr.h"
#include "timers.h"
#include "event_groups.h"


/*定时器计时变量*/
volatile  uint08 second;
volatile  uint08 minute;
volatile  uint08 hour;
volatile  uint16 day;
volatile  uint16 year;
volatile  uint32 Timer0Tick = 0;
volatile  uint08 genneralWaitTime = 0;//回常显界面等待时间
volatile  uint08 chgScrTimer = 0;//用于7777/更改密钥时查看的地址自动切屏时的时间控制

static volatile uint16 BuzzerTimer = 0;//不能同时使用该计数器进行15秒定时和1.5秒定时//不可重入
volatile uint16 HMIBuzzerTimer = 0;//用于定时任意时长的buzzer操作,单位:秒
static volatile uint32 TimerCnt = 0;//主循环定时计数
volatile uint08 KeyInputModeTimer = 0;//按键显示模式定时器，当定时到达时，如果按键没有没处理且没有输入，则清掉按键buff中的内容 


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
输入:ETIMx指定定时器; 
	 howlong定时时间长度(单位毫秒)
输出:无
返回:无
说明:8M 100分频每个溢出周期最长定时~820ms,最短定时约12us
********************/
void TimerInit(ETIMx_Type* ETIMx, uint16 howlong)
{

	ETIM_InitTypeDef init_para;
	volatile uint08 EtimNum;

	EtimNum = ((uint32_t)ETIMx - ETIMER1_BASE)>>5;
	
	//信号源参数
	init_para.sig_src_para.SIG1SEL = ETIMx_ETxINSEL_SIG1SEL_GROUP1;		/* 内部信号1源选择GROUP1 */
	init_para.sig_src_para.SIG2SEL = ETIMx_ETxINSEL_SIG2SEL_GROUP1;		/* 内部信号2源选择GROUP1 */

        //信号源参数
	init_para.sig_src_para.GRP1SEL = ETIMx_ETxINSEL_GRP1SEL_ET1234_APBCLK;		/* GROUP1 信号选择APBCLK */
	init_para.sig_src_para.GRP2SEL = ETIMx_ETxINSEL_GRP2SEL_ET1_XTLF<<(EtimNum>>1);		/* GROUP2 信号选择XTLF */        
        //ET1时钟使能	
	RCC_PERCLK_SetableEx(ET1CLK+(uint32)EtimNum, ENABLE);		
        //NVIC中断配置
	NVIC_DisableIRQ(ETIM1_IRQn+EtimNum);
	NVIC_SetPriority(ETIM1_IRQn+EtimNum, 1);//中断优先级配置
	NVIC_EnableIRQ(ETIM1_IRQn+EtimNum);		

	/*输入时钟分频*/
	init_para.sig_src_para.PRESCALE1 = clkmode - 1 + 99;    //100分频	/* ETx预分频寄存器1 */ 00表示1分频，FF表示256分频
	init_para.sig_src_para.PRESCALE2 = clkmode - 1;    		//1分频		/* ETx预分频寄存器2 */ 00表示1分频，FF表示256分频
	
	
	//控制类参数
	init_para.ctrl_para.EXFLT = ENABLE;								/* 引脚输入数字滤波使能打开 */
	init_para.ctrl_para.MOD = ETIMx_ETxCR_MOD_COUNTER;				/* 工作模式选择计数模式 */
	init_para.ctrl_para.CASEN = DISABLE;							/* 扩展定时器级联关闭 */
	init_para.ctrl_para.EDGESEL = ETIMx_ETxCR_EDGESEL_RISING;		/* 计数模式采沿方式选择（计数时钟选择mcu_clk时该位无效，总是采用mcu_clk时钟上升沿计数） */

	init_para.ctrl_para.PWM = DISABLE;								/* PWM输出关闭 */

	init_para.ctrl_para.CAPMOD = ETIMx_ETxCR_CAPMOD_PERIOD;			/* 捕捉模式控制 */
	init_para.ctrl_para.CAPCLR = DISABLE;							/* 带清零捕捉模式控制 */
	init_para.ctrl_para.CAPONCE = DISABLE;							/* 单次捕捉控制 */
	init_para.ctrl_para.CAPEDGE = ETIMx_ETxCR_CAPEDGE_RISING;		/* 捕捉沿选择 */

	init_para.ctrl_para.CMPIE = DISABLE;		/* 扩展定时器比较中断使能 */
	init_para.ctrl_para.CAPIE = DISABLE;		/* 扩展定时器捕捉中断使能 */
	init_para.ctrl_para.OVIE = ENABLE;			/* 扩展定时器溢出中断使能 */

	init_para.ctrl_para.INITVALUE = 0xffff - (mSecond*howlong); //计数初值，8000000的100分频 计数 8000个周期 = 100ms ;		/* ETx初值寄存器 */
	init_para.ctrl_para.CMP = 0;			/* ETx比较寄存器 */
	
	init_para.ctrl_para.CEN = DISABLE;		/* 启动控制 */
	
	//初始化ETIM
	ETIMx_Init(ETIMx, &init_para);
	
	ETIMx_ETxCR_CEN_Setable(ETIMx, ENABLE);	//启动定时器
	
}


//前置动作TimerInit()
//定时howlong毫秒
void setTime(ETIMx_Type* ETIMx, uint16 howlong)
{
	uint16 time = (0xFFFF-mSecond*howlong);
	
	ETIMx_ETxCR_CEN_Setable(ETIMx, DISABLE);	//启动定时器
	ETIMx_ETxIF_OVIF_Clr(ETIMx);
	ETIMx_ETxIVR_Write(ETIMx, time);	/* ETx初值寄存器 */	
	ETIMx_ETxCR_CEN_Setable(ETIMx, ENABLE);	//启动定时器
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
		IWDT_Clr();             //清系统看门狗	
		
//        LED0_TOG;	            //LED0
		TicksDelayMs(50, NULL );//软件延时
    }	
}




