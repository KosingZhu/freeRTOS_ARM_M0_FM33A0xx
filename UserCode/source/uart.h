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

  unsigned long UART_BaudRate;  //波特率 最高115200bps          
  unsigned int UART_DataLength; //数据位长度 7，8 或 9 (7位与9位数据无校验位)        
  unsigned int UART_StopBits;   //停止位 1 或 2       
  unsigned int UART_Parity;		//校验位 0 无校验  ，1奇校验  ，2 偶校验         
  unsigned int UART_RxTxDfl; 		//电平取反(RS485不同型号使用) 0 不取反 ，1发送取反 ，2接收取反，3接收发送都取反

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
