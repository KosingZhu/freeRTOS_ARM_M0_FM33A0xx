
#include "general.h"


#define UART0_REC_FIFO_SIZE			512
#define UART1_REC_FIFO_SIZE			1
#define UART2_REC_FIFO_SIZE			1
#define UART3_REC_FIFO_SIZE			1
#define UART4_REC_FIFO_SIZE			128
#define UART5_REC_FIFO_SIZE			1


static uint08 uart0_rec_fifo[UART0_REC_FIFO_SIZE] = {0};
static uint08 uart1_rec_fifo[UART1_REC_FIFO_SIZE] = {0};
static uint08 uart2_rec_fifo[UART2_REC_FIFO_SIZE] = {0};
static uint08 uart3_rec_fifo[UART3_REC_FIFO_SIZE] = {0};
static uint08 uart4_rec_fifo[UART4_REC_FIFO_SIZE] = {0};
static uint08 uart5_rec_fifo[UART5_REC_FIFO_SIZE] = {0};
	

static ST_QUEUE st_uart_queue[UART_NUM] = {
	{uart0_rec_fifo, UART0_REC_FIFO_SIZE, 0, 0},
	{uart1_rec_fifo, UART1_REC_FIFO_SIZE, 0, 0},
	{uart2_rec_fifo, UART2_REC_FIFO_SIZE, 0, 0},
	{uart3_rec_fifo, UART3_REC_FIFO_SIZE, 0, 0},
	{uart4_rec_fifo, UART4_REC_FIFO_SIZE, 0, 0},
	{uart5_rec_fifo, UART5_REC_FIFO_SIZE, 0, 0},
};

void UART0_IRQHandler(void)
{
	uint08 tmp08;
	
	//接收中断处理
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART0, RxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART0, RxInt)))
	{
		//中断转发接收到的数据
		tmp08 = UARTx_RXREG_Read(UART0);//接收中断标志仅可通过读取rxreg寄存器清除		
		uart_FIFO_enter_data(UART0SEQ, tmp08); 
	}
	
	//发送中断处理
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART0, TxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART0, TxInt)))
	{

	}
}
	
void UART1_IRQHandler(void)
{
	uint08 tmp08;
	
	//接收中断处理
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART1, RxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART1, RxInt)))
	{
		//中断转发接收到的数据
		tmp08 = UARTx_RXREG_Read(UART1);//接收中断标志仅可通过读取rxreg寄存器清除
		uart_FIFO_enter_data(UART1SEQ, tmp08); 
	}
	
	//发送中断处理
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART1, TxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART1, TxInt)))
	{

	}
}

void UART2_IRQHandler(void)
{
	uint08 tmp08;
	
	//接收中断处理
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART2, RxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART2, RxInt)))
	{
		//中断转发接收到的数据
		tmp08 = UARTx_RXREG_Read(UART2);//接收中断标志仅可通过读取rxreg寄存器清除		
		uart_FIFO_enter_data(UART2SEQ, tmp08); 
	}
	
	//发送中断处理
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART2, TxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART2, TxInt)))
	{

	}
}

void UART3_IRQHandler(void)
{
	uint08 tmp08;
	
	//接收中断处理
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART3, RxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART3, RxInt)))
	{
		//中断转发接收到的数据
		tmp08 = UARTx_RXREG_Read(UART3);//接收中断标志仅可通过读取rxreg寄存器清除
		uart_FIFO_enter_data(UART3SEQ, tmp08); 
	}
	
	//发送中断处理
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART3, TxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART3, TxInt)))
	{

	}
}

void UART4_IRQHandler(void)
{
	uint08 tmp08;
	
	//接收中断处理
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART4, RxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART4, RxInt)))
	{
		//中断转发接收到的数据
		tmp08 = UARTx_RXREG_Read(UART4);//接收中断标志仅可通过读取rxreg寄存器清除		
		uart_FIFO_enter_data(UART4SEQ, tmp08); 
	}
	
	//发送中断处理
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART4, TxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART4, TxInt)))
	{

	}
}

void UART5_IRQHandler(void)
{
	uint08 tmp08;
	
	//接收中断处理
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART5, RxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART5, RxInt)))
	{
		//中断转发接收到的数据
		tmp08 = UARTx_RXREG_Read(UART5);//接收中断标志仅可通过读取rxreg寄存器清除		
		uart_FIFO_enter_data(UART5SEQ, tmp08); 
		//UARTx_TXREG_Write(UART5, tmp08);
	}
	
	//发送中断处理
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART5, TxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART5, TxInt)))
	{

	}
}


//释放uart IO使其变成一般状态
void uartGPIODeinit(uint32 UARTx)
{

#ifdef FM33A0_MCU

	GPIOx_Type *IOPort;
	uint32 RxPin, TxPin;

	if(UART0 == (UARTx_Type*)UARTx)
	{
		IOPort = Uart0Port;
		RxPin  = Uart0RxPin;
		TxPin = Uart0TxPin;
	}	
	else if(UART4 == (UARTx_Type*)UARTx)
	{
		IOPort = Uart4Port;
		RxPin = Uart4RxPin;
		TxPin = Uart4TxPin;
	}
	CloseeIO(IOPort, RxPin);
	CloseeIO(IOPort, TxPin);
	GPIO_ResetBits(IOPort, RxPin);
	GPIO_ResetBits(IOPort, TxPin);
	
#else
	uint08 PINPort, RxPin, TxPin;
	if(UART2 == UARTx)
	{
		PINPort =Uart2Port;
		RxPin = Uart2RxPin;
		TxPin = Uart2TxPin;
	}
	else if(UART3 == UARTx)
	{
		PINPort = Uart3Port;
		RxPin = Uart3RxPin;
		TxPin = Uart3TxPin;
	}
	GPIO_Init(PINPort, RxPin, GPIO_MODE_IO_OFF, MODE_ALTERNATE_SELECT_NULL);	
	GPIO_Init(PINPort, TxPin, GPIO_MODE_IO_OFF, MODE_ALTERNATE_SELECT_NULL);
	GPIO_Write_Output_Data_Bit(PINPort, RxPin, 0);
	GPIO_Write_Output_Data_Bit(PINPort, TxPin, 0);
#endif

}


//初始化对应的uart IO使其变成UART功能状态
void uartGPIOInit(uint32 UARTx)
{

#ifdef FM33A0_MCU
	
	GPIOx_Type *IOPort;
	uint32 RxPin, TxPin;
	
	if(UART0 == (UARTx_Type*)UARTx)
	{
		IOPort = Uart0Port;
		RxPin  = Uart0RxPin;
		TxPin = Uart0TxPin;
	}	
	else if(UART4 == (UARTx_Type*)UARTx)
	{
		IOPort = Uart4Port;
		RxPin = Uart4RxPin;
		TxPin = Uart4TxPin;
	}
	AltFunIO(IOPort, RxPin, ALTFUN_PULLUP);
	AltFunIO(IOPort, TxPin, ALTFUN_PULLUP);
				
#else

	uint08 PINPort, RxPin, TxPin;
	
	if(UART2 == UARTx)
	{
		PINPort = Uart2Port;
		RxPin = Uart2RxPin;
		TxPin = Uart2TxPin;
	}
	else if(UART3 == UARTx)
	{
		PINPort = Uart3Port;
		RxPin = Uart3RxPin;
		TxPin = Uart3TxPin;
	}
	GPIO_Init(PINPort, RxPin, GPIO_MODE_ALTERNATE_FUNCTION, MODE_ALTERNATE_SELECT_0);	
	GPIO_Init(PINPort, TxPin, GPIO_MODE_ALTERNATE_FUNCTION, MODE_ALTERNATE_SELECT_0);
#endif

}

void EnableUARTx(uint32 UARTx)
{
	uartGPIOInit(UARTx);
	
#ifdef FM33A0_MCU
	//RCC_PERCLK_SetableEx(UARTCOMCLK, ENABLE);	//UART0~5共享寄存器时钟使能
	//RCC_PERCLK_SetableEx(UART4CLK, ENABLE); //UARTx时钟使能 
	/*NVIC中断配置*/
	//NVIC_DisableIRQ(UART4_IRQn);
	//NVIC_SetPriority(UART4_IRQn,2);//中断优先级配置
	//NVIC_EnableIRQ(UART4_IRQn);

	UARTx_RXSTA_RXEN_Setable((UARTx_Type*)UARTx, ENABLE);
	UARTx_TXSTA_TXEN_Setable((UARTx_Type*)UARTx, ENABLE);
	UART_UARTIE_RxTxIE_SetableEx((UARTx_Type*)UARTx, RxInt, ENABLE);		//接收中断
	//UART_UARTIE_RxTxIE_SetableEx(UARTx, TxInt, para->TXIE);		//发送中断	
#else
	UART_RX_Interrupt_Enable(UARTx);
	UART_TX_Enable(UARTx);
	UART_RX_Enable(UARTx);
#endif

}

void DisableUARTx(uint32 UARTx)
{

#ifdef FM33A0_MCU
	UART_UARTIE_RxTxIE_SetableEx((UARTx_Type*)UARTx, RxInt, DISABLE);		//接收中断
	//UART_UARTIE_RxTxIE_SetableEx(UARTx, TxInt, para->TXIE);		//发送中断	
	UARTx_RXSTA_RXEN_Setable((UARTx_Type*)UARTx, DISABLE);
	UARTx_TXSTA_TXEN_Setable((UARTx_Type*)UARTx, DISABLE);
#else
	UART_RX_Interrupt_Disable(UARTx);
	UART_TX_Disable(UARTx);
	UART_RX_Disable(UARTx);
#endif
	uartGPIODeinit(UARTx);
}


void myUartInit(UARTx_Type* UARTx, UART_INIT_STRU *init)
{
	UART_SInitTypeDef UART_para;
	RCC_ClocksType RCC_Clocks;
	volatile uint08 tmp08;
	
	//uartGPIOInit((uint32)UARTx);
	
	RCC_PERCLK_SetableEx(UARTCOMCLK, ENABLE);	//UART0~5共享寄存器时钟使能

	/*清接收和发送中断标识，清接收和发送缓冲区*/
	UART_UARTIF_RxTxIF_ClrEx(UARTx);
	
	tmp08 = ((uint32_t)UARTx - UART0_BASE)>>5;	//获取uart
	switch(tmp08)
	{
		case 0:
			RCC_PERCLK_SetableEx(UART0CLK, ENABLE);	//UARTx时钟使能
			//	UART0 IO 配置
			AltFunIO(GPIOF, GPIO_Pin_3, 0);		//PF3 UART0 RX
			AltFunIO(GPIOF, GPIO_Pin_4, 0);		//PF4 UART0 TX
		
			/*NVIC中断配置*/
			NVIC_DisableIRQ(UART0_IRQn);
			NVIC_SetPriority(UART0_IRQn,2);//中断优先级配置
			NVIC_EnableIRQ(UART0_IRQn);	
			break;
		
		case 1:
			RCC_PERCLK_SetableEx(UART1CLK, ENABLE);	//UARTx时钟使能	
			//	UART1 IO 配置
			AltFunIO(GPIOB, GPIO_Pin_0, 0);		//PB0 UART1 RX
			AltFunIO(GPIOB, GPIO_Pin_1, 0);		//PB1 UART1 TX
			
			//AltFunIO(GPIOE, GPIO_Pin_3, 0);		//PE3 UART1 RX
			//AltFunIO(GPIOE, GPIO_Pin_4, 0);		//PE4 UART1 TX
		
			/*NVIC中断配置*/
			NVIC_DisableIRQ(UART1_IRQn);
			NVIC_SetPriority(UART1_IRQn,2);//中断优先级配置
			NVIC_EnableIRQ(UART1_IRQn);	
			break;
		
		case 2:
			RCC_PERCLK_SetableEx(UART2CLK, ENABLE);	//UARTx时钟使能	
			//	UART2 IO 配置
			AltFunIO(GPIOB, GPIO_Pin_2, 0);		//PB2 UART2 RX
			AltFunIO(GPIOB, GPIO_Pin_3, 0);		//PB3 UART2 TX	
		
			/*NVIC中断配置*/
			NVIC_DisableIRQ(UART2_IRQn);
			NVIC_SetPriority(UART2_IRQn,2);//中断优先级配置
			NVIC_EnableIRQ(UART2_IRQn);	
			break;
		
		case 3:
			RCC_PERCLK_SetableEx(UART3CLK, ENABLE);	//UARTx时钟使能	
			//	UART3 IO 配置
			AltFunIO(GPIOC, GPIO_Pin_10, 0);	//PC10 UART3 RX
			AltFunIO(GPIOC, GPIO_Pin_11, 0);	//PC11 UART3 TX
		
			/*NVIC中断配置*/
			NVIC_DisableIRQ(UART3_IRQn);
			NVIC_SetPriority(UART3_IRQn,2);//中断优先级配置
			NVIC_EnableIRQ(UART3_IRQn);	
			break;
		
		case 4:
			RCC_PERCLK_SetableEx(UART4CLK, ENABLE);	//UARTx时钟使能	
			//	UART4 IO 配置
			AltFunIO(GPIOD, GPIO_Pin_0, 0);		//PD0 UART4 RX
			AltFunIO(GPIOD, GPIO_Pin_1, 0);		//PD1 UART4 TX
			//仅100脚
			//AltFunIO(GPIOD, GPIO_Pin_9, 0);		//PD9 UART4 RX
			//AltFunIO(GPIOD, GPIO_Pin_10, 0);	//PD10 UART4 TX
		
			/*NVIC中断配置*/
			NVIC_DisableIRQ(UART4_IRQn);
			NVIC_SetPriority(UART4_IRQn, 2);//中断优先级配置
			NVIC_EnableIRQ(UART4_IRQn);	
			break;
		
		case 5:
			RCC_PERCLK_SetableEx(UART5CLK, ENABLE);	//UARTx时钟使能	
			//	UART5 IO 配置
			AltFunIO(GPIOC, GPIO_Pin_4, 0);		//PC4 UART5 RX
			AltFunIO(GPIOC, GPIO_Pin_5, 0);		//PC5 UART5 TX	
		
			/*NVIC中断配置*/
			NVIC_DisableIRQ(UART5_IRQn);
			NVIC_SetPriority(UART5_IRQn,2);//中断优先级配置
			NVIC_EnableIRQ(UART5_IRQn);	
			break;
		
		default:
			break;
	}
	
	//UART初始化配置
	UART_para.BaudRate = init->UART_BaudRate;								//波特率
	UART_para.DataBit = (UART_DataBitTypeDef)init->UART_DataLength;			//数据位数
	UART_para.ParityBit = (UART_ParityBitTypeDef)init->UART_Parity;							//奇偶校验
	UART_para.StopBit = (UART_StopBitTypeDef)init->UART_StopBits;							//停止位
	
	RCC_GetClocksFreq(&RCC_Clocks);//获取APB时钟频率
	UART_SInit(UARTx, &UART_para, RCC_Clocks.APBCLK_Frequency);	//初始化uart

	UART_UARTIE_RxTxIE_SetableEx(UARTx, RxInt, ENABLE);		//接收中断
	UART_UARTIE_RxTxIE_SetableEx(UARTx, TxInt, DISABLE);		//发送中断

	if(init->UART_RxTxDfl == 2 || init->UART_RxTxDfl == 3)
	{
		UARTx_RTXCON_RXDFLAG_Setable(UARTx, ENABLE);	//接收数据取反控制位
	}
	else{
		UARTx_RTXCON_RXDFLAG_Setable(UARTx, DISABLE);	//接收数据取反控制位		
	}

	if(init->UART_RxTxDfl == 1 || init->UART_RxTxDfl == 3)
	{
		UARTx_RTXCON_TXDFLAG_Setable(UARTx, ENABLE);	//发送数据取反控制位
	}
	else{		
		UARTx_RTXCON_RXDFLAG_Setable(UARTx, DISABLE);	//接收数据取反控制位
	}

	UARTx_RXSTA_RXEN_Setable(UARTx, ENABLE);		//接收模块使能控制
	UARTx_TXSTA_TXEN_Setable(UARTx, ENABLE);		//发送模块使能控制
	UARTx_TXSTA_IREN_Setable(UARTx, DISABLE);		//发送红外调制使能位

}


void myUartDeInit(uint32 UARTx)
{
	//UART_RX_Interrupt_Disable(UARTx);
	//UART_TX_Disable(UARTx);
	//UART_RX_Disable(UARTx);
	DisableUARTx(UARTx);
	uartGPIODeinit(UARTx);
}

void UartDefaultInit(uint32 UARTx, uint08 RxTxDfl)
{
	UART_INIT_STRU init = {{9600}, {8}, {1}, {2}, {3}};

	init.UART_RxTxDfl = RxTxDfl;

	uartGPIOInit(UARTx);

	myUartInit((UARTx_Type*)UARTx, &init);
	//UART_Init(UARTx, &init);
	//UART_TX_Interrupt_Enable(UARTx);
	//UART_RX_Interrupt_Enable(UARTx);
	//UART_TX_Enable(UARTx);
	//UART_RX_Enable(UARTx);
	EnableUARTx(UARTx);
	
	//Delay_x5ms(1);

}


static uint08 uart_FIFO_data_length(uint08 UARTxSEQ)
{
	return FIFO_data_length(&st_uart_queue[UARTxSEQ]);
}


/*******************************************
*功能描述： 获取串口FIFO中的数据(用户接口)
*参数功能：         
*返回值：实际接收到的数据(返回0表示接收超时)
********************************************/
uint16 uart_receive(uint08 UARTxSEQ, uint08* receive_buf, uint08 expect_len, uint16 waitTime)
{
	uint08 i = 0;
	uint16 time_out = waitTime;

	uint16 rec_len = 0;
	
	do
	{
		/* 获取FIFO中数据的长度 */
		rec_len = uart_FIFO_data_length(UARTxSEQ);
		if(rec_len == 0)//没有数据直接退出，不阻塞等待
			return 0;
		
		if(rec_len >= expect_len) //有数据
		{
			break;
		}
		
	}while(--time_out);
	
    if(!time_out&&0 == rec_len)
	{
		return 0;
	}
	else if(0 != rec_len)
	{
		expect_len = rec_len;
	}

	/* 读取数据 */
	for(i = 0; i < expect_len; i++)
	{
		if(FALSE == FIFO_get_data(&st_uart_queue[UARTxSEQ], &receive_buf[i]))
		{
			return (i+1);
		}
		
	}
	
	return expect_len;
	
}



static uint08 UartSendFinish(uint32 UARTx)
{
	//return (!UARTx_TXBUFSTA_TXFF_Chk((UARTx_Type*)UARTx));
	return (UART_UARTIF_RxTxIF_ChkEx((UARTx_Type*)UARTx, TxInt));
	//return (UARTIF&(txif0<<(UARTx*2)));
}


/*******************************************
*功能描述：串口发送
*参数功能：port 串口选择.
           sendBuf  发送缓存的首地址
           length    发送长度 
           time_out  发送超时设定
*返回值：已发送的数据长度值
********************************************/
uint08 uart_send(uint32 UARTx, uint08 *sendBuf, const uint08 length)
{
	uint08 i = 0;
	uint16 time_out = TIME_DELAY_5MS*80;
	//uint16 time_out = TIME_DELAY_5MS*10;

	for(i = 0; i < length; i++)
	{	
		UARTx_TXREG_Write((UARTx_Type*) UARTx, sendBuf[i]);
		while((!UartSendFinish(UARTx))&&time_out--)
			;
		
		if(!time_out)
			return i;
	}	

	return length;	
	
}

void uart_FIFO_clear(uint08 UARTxSEQ)
{
	FIFO_clear(&st_uart_queue[UARTxSEQ]);
}


int08 uart_FIFO_enter_data(uint08 UARTxSEQ, uint08 dat)
{
	return FIFO_enter_data(&st_uart_queue[UARTxSEQ], dat);	
}



//部分AF功能可能被同时映射到多个IO引脚，比如UART3同时出现在PC10/PC11和PD0/PD1，
//对于此类情况，如果它们被同时配置为UART功能，则UART_TX3同时有效，
//而UART_RX3只有PC10有效，PD0输入不会接到任何电路。
//总体原则是：多映射AF的输出可以同时有效，输入只有低编码序号的管脚有效。



