#ifndef _uart_H
#define _uart_H



#define PRINTF_UART			((uint32)UART4)
#define DataUART			((uint32)UART0)

#define UART_NUM	6

#define UART0SEQ	0
#define UART1SEQ	1
#define UART2SEQ	2
#define UART3SEQ	3
#define UART4SEQ	4
#define UART5SEQ	5



#define Uart2Port		PORTG
#define Uart2RxPin		PIN0
#define Uart2TxPin		PIN1


#define Uart3Port	PORTG
#define Uart3RxPin	PIN6
#define Uart3TxPin	PIN5


//FM33A0
#define Uart4Port	GPIOD
#define Uart4RxPin	GPIO_Pin_0
#define Uart4TxPin	GPIO_Pin_1

#define Uart0Port	GPIOF
#define Uart0RxPin	GPIO_Pin_3
#define Uart0TxPin	GPIO_Pin_4

	
typedef struct{
	uint08	UARTx;
	uint08 	PINPort;
	uint08 	RxPin;
	uint08	TxPin;
}UART_GPIO_S;

typedef struct
{

  unsigned long UART_BaudRate;  //������ ���115200bps          
  unsigned int UART_DataLength; //����λ���� 7��8 �� 9 (7λ��9λ������У��λ)        
  unsigned int UART_StopBits;   //ֹͣλ 1 �� 2       
  unsigned int UART_Parity;		//У��λ 0 ��У��  ��1��У��  ��2 żУ��         
  unsigned int UART_RxTxDfl; 		//��ƽȡ��(RS485��ͬ�ͺ�ʹ��) 0 ��ȡ�� ��1����ȡ�� ��2����ȡ����3���շ��Ͷ�ȡ��

} UART_INIT_STRU;


void EnableUARTx(uint32 UARTx);
void DisableUARTx(uint32 UARTx);
void myUartInit(UARTx_Type* UARTx, UART_INIT_STRU *init);
uint16 uart_receive(uint08 UARTx, uint08* receive_buf, uint08 expect_len, uint16 waitTime);
uint08 uart_send(uint32 UARTx, uint08 *sendBuf, const uint08 length);
void uart_FIFO_clear(uint08 uart_port);
int08 uart_FIFO_enter_data(uint08 uart, uint08 dat);
void uartGPIODeinit(uint32 UARTx);
void uartGPIOInit(uint32 UARTx);
void myUartDeInit(uint32 UARTx);
void UartDefaultInit(uint32 UARTx, uint08 RxTxDfl);



#endif
