
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
	
	//�����жϴ���
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART0, RxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART0, RxInt)))
	{
		//�ж�ת�����յ�������
		tmp08 = UARTx_RXREG_Read(UART0);//�����жϱ�־����ͨ����ȡrxreg�Ĵ������		
		uart_FIFO_enter_data(UART0SEQ, tmp08); 
	}
	
	//�����жϴ���
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART0, TxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART0, TxInt)))
	{

	}
}
	
void UART1_IRQHandler(void)
{
	uint08 tmp08;
	
	//�����жϴ���
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART1, RxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART1, RxInt)))
	{
		//�ж�ת�����յ�������
		tmp08 = UARTx_RXREG_Read(UART1);//�����жϱ�־����ͨ����ȡrxreg�Ĵ������
		uart_FIFO_enter_data(UART1SEQ, tmp08); 
	}
	
	//�����жϴ���
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART1, TxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART1, TxInt)))
	{

	}
}

void UART2_IRQHandler(void)
{
	uint08 tmp08;
	
	//�����жϴ���
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART2, RxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART2, RxInt)))
	{
		//�ж�ת�����յ�������
		tmp08 = UARTx_RXREG_Read(UART2);//�����жϱ�־����ͨ����ȡrxreg�Ĵ������		
		uart_FIFO_enter_data(UART2SEQ, tmp08); 
	}
	
	//�����жϴ���
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART2, TxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART2, TxInt)))
	{

	}
}

void UART3_IRQHandler(void)
{
	uint08 tmp08;
	
	//�����жϴ���
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART3, RxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART3, RxInt)))
	{
		//�ж�ת�����յ�������
		tmp08 = UARTx_RXREG_Read(UART3);//�����жϱ�־����ͨ����ȡrxreg�Ĵ������
		uart_FIFO_enter_data(UART3SEQ, tmp08); 
	}
	
	//�����жϴ���
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART3, TxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART3, TxInt)))
	{

	}
}

void UART4_IRQHandler(void)
{
	uint08 tmp08;
	
	//�����жϴ���
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART4, RxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART4, RxInt)))
	{
		//�ж�ת�����յ�������
		tmp08 = UARTx_RXREG_Read(UART4);//�����жϱ�־����ͨ����ȡrxreg�Ĵ������		
		uart_FIFO_enter_data(UART4SEQ, tmp08); 
	}
	
	//�����жϴ���
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART4, TxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART4, TxInt)))
	{

	}
}

void UART5_IRQHandler(void)
{
	uint08 tmp08;
	
	//�����жϴ���
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART5, RxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART5, RxInt)))
	{
		//�ж�ת�����յ�������
		tmp08 = UARTx_RXREG_Read(UART5);//�����жϱ�־����ͨ����ȡrxreg�Ĵ������		
		uart_FIFO_enter_data(UART5SEQ, tmp08); 
		//UARTx_TXREG_Write(UART5, tmp08);
	}
	
	//�����жϴ���
	if((ENABLE == UART_UARTIE_RxTxIE_GetableEx(UART5, TxInt))
		&&(SET == UART_UARTIF_RxTxIF_ChkEx(UART5, TxInt)))
	{

	}
}


//�ͷ�uart IOʹ����һ��״̬
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


//��ʼ����Ӧ��uart IOʹ����UART����״̬
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
	//RCC_PERCLK_SetableEx(UARTCOMCLK, ENABLE);	//UART0~5����Ĵ���ʱ��ʹ��
	//RCC_PERCLK_SetableEx(UART4CLK, ENABLE); //UARTxʱ��ʹ�� 
	/*NVIC�ж�����*/
	//NVIC_DisableIRQ(UART4_IRQn);
	//NVIC_SetPriority(UART4_IRQn,2);//�ж����ȼ�����
	//NVIC_EnableIRQ(UART4_IRQn);

	UARTx_RXSTA_RXEN_Setable((UARTx_Type*)UARTx, ENABLE);
	UARTx_TXSTA_TXEN_Setable((UARTx_Type*)UARTx, ENABLE);
	UART_UARTIE_RxTxIE_SetableEx((UARTx_Type*)UARTx, RxInt, ENABLE);		//�����ж�
	//UART_UARTIE_RxTxIE_SetableEx(UARTx, TxInt, para->TXIE);		//�����ж�	
#else
	UART_RX_Interrupt_Enable(UARTx);
	UART_TX_Enable(UARTx);
	UART_RX_Enable(UARTx);
#endif

}

void DisableUARTx(uint32 UARTx)
{

#ifdef FM33A0_MCU
	UART_UARTIE_RxTxIE_SetableEx((UARTx_Type*)UARTx, RxInt, DISABLE);		//�����ж�
	//UART_UARTIE_RxTxIE_SetableEx(UARTx, TxInt, para->TXIE);		//�����ж�	
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
	
	RCC_PERCLK_SetableEx(UARTCOMCLK, ENABLE);	//UART0~5����Ĵ���ʱ��ʹ��

	/*����պͷ����жϱ�ʶ������պͷ��ͻ�����*/
	UART_UARTIF_RxTxIF_ClrEx(UARTx);
	
	tmp08 = ((uint32_t)UARTx - UART0_BASE)>>5;	//��ȡuart
	switch(tmp08)
	{
		case 0:
			RCC_PERCLK_SetableEx(UART0CLK, ENABLE);	//UARTxʱ��ʹ��
			//	UART0 IO ����
			AltFunIO(GPIOF, GPIO_Pin_3, 0);		//PF3 UART0 RX
			AltFunIO(GPIOF, GPIO_Pin_4, 0);		//PF4 UART0 TX
		
			/*NVIC�ж�����*/
			NVIC_DisableIRQ(UART0_IRQn);
			NVIC_SetPriority(UART0_IRQn,2);//�ж����ȼ�����
			NVIC_EnableIRQ(UART0_IRQn);	
			break;
		
		case 1:
			RCC_PERCLK_SetableEx(UART1CLK, ENABLE);	//UARTxʱ��ʹ��	
			//	UART1 IO ����
			AltFunIO(GPIOB, GPIO_Pin_0, 0);		//PB0 UART1 RX
			AltFunIO(GPIOB, GPIO_Pin_1, 0);		//PB1 UART1 TX
			
			//AltFunIO(GPIOE, GPIO_Pin_3, 0);		//PE3 UART1 RX
			//AltFunIO(GPIOE, GPIO_Pin_4, 0);		//PE4 UART1 TX
		
			/*NVIC�ж�����*/
			NVIC_DisableIRQ(UART1_IRQn);
			NVIC_SetPriority(UART1_IRQn,2);//�ж����ȼ�����
			NVIC_EnableIRQ(UART1_IRQn);	
			break;
		
		case 2:
			RCC_PERCLK_SetableEx(UART2CLK, ENABLE);	//UARTxʱ��ʹ��	
			//	UART2 IO ����
			AltFunIO(GPIOB, GPIO_Pin_2, 0);		//PB2 UART2 RX
			AltFunIO(GPIOB, GPIO_Pin_3, 0);		//PB3 UART2 TX	
		
			/*NVIC�ж�����*/
			NVIC_DisableIRQ(UART2_IRQn);
			NVIC_SetPriority(UART2_IRQn,2);//�ж����ȼ�����
			NVIC_EnableIRQ(UART2_IRQn);	
			break;
		
		case 3:
			RCC_PERCLK_SetableEx(UART3CLK, ENABLE);	//UARTxʱ��ʹ��	
			//	UART3 IO ����
			AltFunIO(GPIOC, GPIO_Pin_10, 0);	//PC10 UART3 RX
			AltFunIO(GPIOC, GPIO_Pin_11, 0);	//PC11 UART3 TX
		
			/*NVIC�ж�����*/
			NVIC_DisableIRQ(UART3_IRQn);
			NVIC_SetPriority(UART3_IRQn,2);//�ж����ȼ�����
			NVIC_EnableIRQ(UART3_IRQn);	
			break;
		
		case 4:
			RCC_PERCLK_SetableEx(UART4CLK, ENABLE);	//UARTxʱ��ʹ��	
			//	UART4 IO ����
			AltFunIO(GPIOD, GPIO_Pin_0, 0);		//PD0 UART4 RX
			AltFunIO(GPIOD, GPIO_Pin_1, 0);		//PD1 UART4 TX
			//��100��
			//AltFunIO(GPIOD, GPIO_Pin_9, 0);		//PD9 UART4 RX
			//AltFunIO(GPIOD, GPIO_Pin_10, 0);	//PD10 UART4 TX
		
			/*NVIC�ж�����*/
			NVIC_DisableIRQ(UART4_IRQn);
			NVIC_SetPriority(UART4_IRQn, 2);//�ж����ȼ�����
			NVIC_EnableIRQ(UART4_IRQn);	
			break;
		
		case 5:
			RCC_PERCLK_SetableEx(UART5CLK, ENABLE);	//UARTxʱ��ʹ��	
			//	UART5 IO ����
			AltFunIO(GPIOC, GPIO_Pin_4, 0);		//PC4 UART5 RX
			AltFunIO(GPIOC, GPIO_Pin_5, 0);		//PC5 UART5 TX	
		
			/*NVIC�ж�����*/
			NVIC_DisableIRQ(UART5_IRQn);
			NVIC_SetPriority(UART5_IRQn,2);//�ж����ȼ�����
			NVIC_EnableIRQ(UART5_IRQn);	
			break;
		
		default:
			break;
	}
	
	//UART��ʼ������
	UART_para.BaudRate = init->UART_BaudRate;								//������
	UART_para.DataBit = (UART_DataBitTypeDef)init->UART_DataLength;			//����λ��
	UART_para.ParityBit = (UART_ParityBitTypeDef)init->UART_Parity;							//��żУ��
	UART_para.StopBit = (UART_StopBitTypeDef)init->UART_StopBits;							//ֹͣλ
	
	RCC_GetClocksFreq(&RCC_Clocks);//��ȡAPBʱ��Ƶ��
	UART_SInit(UARTx, &UART_para, RCC_Clocks.APBCLK_Frequency);	//��ʼ��uart

	UART_UARTIE_RxTxIE_SetableEx(UARTx, RxInt, ENABLE);		//�����ж�
	UART_UARTIE_RxTxIE_SetableEx(UARTx, TxInt, DISABLE);		//�����ж�

	if(init->UART_RxTxDfl == 2 || init->UART_RxTxDfl == 3)
	{
		UARTx_RTXCON_RXDFLAG_Setable(UARTx, ENABLE);	//��������ȡ������λ
	}
	else{
		UARTx_RTXCON_RXDFLAG_Setable(UARTx, DISABLE);	//��������ȡ������λ		
	}

	if(init->UART_RxTxDfl == 1 || init->UART_RxTxDfl == 3)
	{
		UARTx_RTXCON_TXDFLAG_Setable(UARTx, ENABLE);	//��������ȡ������λ
	}
	else{		
		UARTx_RTXCON_RXDFLAG_Setable(UARTx, DISABLE);	//��������ȡ������λ
	}

	UARTx_RXSTA_RXEN_Setable(UARTx, ENABLE);		//����ģ��ʹ�ܿ���
	UARTx_TXSTA_TXEN_Setable(UARTx, ENABLE);		//����ģ��ʹ�ܿ���
	UARTx_TXSTA_IREN_Setable(UARTx, DISABLE);		//���ͺ������ʹ��λ

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
*���������� ��ȡ����FIFO�е�����(�û��ӿ�)
*�������ܣ�         
*����ֵ��ʵ�ʽ��յ�������(����0��ʾ���ճ�ʱ)
********************************************/
uint16 uart_receive(uint08 UARTxSEQ, uint08* receive_buf, uint08 expect_len, uint16 waitTime)
{
	uint08 i = 0;
	uint16 time_out = waitTime;

	uint16 rec_len = 0;
	
	do
	{
		/* ��ȡFIFO�����ݵĳ��� */
		rec_len = uart_FIFO_data_length(UARTxSEQ);
		if(rec_len == 0)//û������ֱ���˳����������ȴ�
			return 0;
		
		if(rec_len >= expect_len) //������
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

	/* ��ȡ���� */
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
*�������������ڷ���
*�������ܣ�port ����ѡ��.
           sendBuf  ���ͻ�����׵�ַ
           length    ���ͳ��� 
           time_out  ���ͳ�ʱ�趨
*����ֵ���ѷ��͵����ݳ���ֵ
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



//����AF���ܿ��ܱ�ͬʱӳ�䵽���IO���ţ�����UART3ͬʱ������PC10/PC11��PD0/PD1��
//���ڴ��������������Ǳ�ͬʱ����ΪUART���ܣ���UART_TX3ͬʱ��Ч��
//��UART_RX3ֻ��PC10��Ч��PD0���벻��ӵ��κε�·��
//����ԭ���ǣ���ӳ��AF���������ͬʱ��Ч������ֻ�еͱ�����ŵĹܽ���Ч��



