
#include "general.h"

/*注意改队列的最大长度为256-1，入队的每个数据最大值为255*/


/**********************************************************
Function		:init_FIFO
Description	: 队列初始化
Calls		:
Called by	: 无
Input		: fifo_addr  指定的队列首地址
                fifo_size  队列最大长度
Output		: st_fifo 初始化后的队列结构
Return		: 无
Others		: 
**********************************************************/
void init_FIFO(ST_QUEUE *st_fifo, uint08 *fifo_addr, const uint08 fifo_size)
{
	st_fifo->FIFO = fifo_addr;
	st_fifo->FIFO_SIZE = fifo_size;
	st_fifo->front = 0;
	st_fifo->rear = 0;
	return;
}


/**********************************************************
Function	: FIFO_top_data
Description	:取得队顶的元素，不从队列中删除
Calls		:
Called by	: 
Input		: 
                
Output		: 
Return		: 
                
Others		: 
**********************************************************/
uint08 FIFO_top_data(ST_QUEUE *st_fifo, uint08 *dat)
{
	if(TRUE == FIFO_is_empty(st_fifo))
	{
		return FALSE;
	}
	
	*dat = st_fifo->FIFO[st_fifo->front];
	
	return TRUE;
}


/**********************************************************
Function	: FIFO_travel
Description	:遍历队列，并将队列中的数据写到buf中返回
Calls		:
Called by	: 
Input		: 
                
Output		: 
Return		: 返回实际写入buf中的数据的个数
                
Others		: 
**********************************************************/
uint08 FIFO_travel(ST_QUEUE *st_fifo, uint08 *buf, uint08 len)
{
	uint08 i, index = 0;
	
	i = FIFO_data_length(st_fifo);
	len = len > i ? i : len;
	
	index = st_fifo->front;
	for(i = 0; i < len; i++)
	{
		buf[i] = st_fifo->FIFO[index];
		index = (index+1) % st_fifo->FIFO_SIZE;
	}
	
	return len;
}



/**********************************************************
Function	: FIFO_pop_data
Description	:将队列元素弹出队列
Calls		:
Called by	: 
Input		: 
                
Output		: 
Return		: 
                
Others		: 
**********************************************************/
uint08 FIFO_pop_data(ST_QUEUE *st_fifo)
{
	if(TRUE == FIFO_is_empty(st_fifo))
	{
		return FALSE;
	}
	
	st_fifo->front = (st_fifo->front+1) % st_fifo->FIFO_SIZE;
		
	return TRUE;
}




/**********************************************************
Function		:FIFO_is_full
Description	: 判断队列是否满
Calls		:
Called by	: 无
Input		: st_fifo 队列结构的地址
                
Output		: 
Return		: TRUE 队满
                FALSE 队未满
Others		: 
**********************************************************/
uint08 FIFO_is_full(ST_QUEUE *st_fifo)
{

	/* 如果front 只比 rear小1，就认为队满 */
	if(st_fifo->front == (st_fifo->rear+1) % st_fifo->FIFO_SIZE)
	{
		return TRUE;	
	}
	else
	{
		return FALSE;
	}
}



/**********************************************************
Function		:FIFO_is_empty
Description	: 判断队列是否空
Calls		:
Called by	: 无
Input		: st_fifo 队列结构的地址
                
Output		: 
Return		: TRUE 队空
                FALSE 队未空
Others		: 
**********************************************************/
uint08 FIFO_is_empty(ST_QUEUE *st_fifo)
{
	/* front和rear指向队中同一个位置，就认为队空 */
	if( st_fifo->front == st_fifo->rear )
	{
		return TRUE;	
	}
	else
	{
		return FALSE;
	}
}
/**********************************************************
Function		:FIFO_data_length
Description	: 获知队列有多少个数据
Calls		:
Called by	: 无
Input		: st_fifo 队列结构的地址
                
Output		: 
Return		: 数据个数
                
Others		: 
**********************************************************/
uint08 FIFO_data_length(ST_QUEUE* st_fifo)
{
	return (st_fifo->rear - st_fifo->front + st_fifo->FIFO_SIZE) % st_fifo->FIFO_SIZE;
}


/**********************************************************
Function		:FIFO_enter_data
Description	: 数据入队尾
Calls		:
Called by	: 无
Input		: 
                
Output		: 
Return		: 
                
Others		: 
**********************************************************/
uint08 FIFO_enter_data(ST_QUEUE *st_fifo, const uint08 dat)
{
	if(TRUE == FIFO_is_full(st_fifo))
	{
		return FALSE;
	}
	//sprintf(string, "fifoAdd:%p  \n", st_fifo->FIFO);
	//uart_send(PRINTF_UART, string, strlen(string));
	
	st_fifo->FIFO[st_fifo->rear] = dat;
	
	//sprintf(string, "rear1:%02X, dat:%02X, rearVal:%02X, front:%02X\n",\
	//	st_fifo->rear, dat, st_fifo->FIFO[st_fifo->rear], st_fifo->FIFO[st_fifo->front]);
	//uart_send(PRINTF_UART, string, strlen(string));
	
	st_fifo->rear = (st_fifo->rear+1) % st_fifo->FIFO_SIZE;

	//sprintf(string, "rear2:%02X, size:%02X\n", st_fifo->rear, st_fifo->FIFO_SIZE);
	//uart_send(PRINTF_UART, string, strlen(string));
	
	//sprintf(string, "fifo:%02X, fifoF:%02X\n", st_fifo->FIFO[st_fifo->rear], st_fifo->FIFO[st_fifo->front]);
	//uart_send(PRINTF_UART, string, strlen(string));

	return TRUE;
}





/**********************************************************
Function		: FIFO_get_data
Description	: 队头数据出队
Calls		:
Called by	: 无
Input		: 
                
Output		: 
Return		: 
                
Others		: 
**********************************************************/
uint08 FIFO_get_data(ST_QUEUE *st_fifo, uint08 *dat)
{
	if(TRUE == FIFO_is_empty(st_fifo))
	{
		return FALSE;
	}

	*dat = st_fifo->FIFO[st_fifo->front];
	st_fifo->front = (st_fifo->front+1) % st_fifo->FIFO_SIZE;
	return TRUE;
}


/**********************************************************
Function	: FIFO_rear_data
Description	:取得队尾的元素;必须在队列非空时操作，否则返回值无意义
Calls		:
Called by	: 
Input		: 
                
Output		: 
Return		: 返回队列队尾元素
                
Others		: 先导函数为FIFO_is_empty()
**********************************************************/
uint08 FIFO_rear_data(ST_QUEUE *st_fifo)
{	
	return st_fifo->FIFO[st_fifo->rear-1];
}


/**********************************************************
Function	: FIFO_find
Description	: 在队列中找到value值对应的index
Calls		:
Called by	: 无
Input		: 
                
Output		: 
Return		: 返回index,当返回负数时表示未找到该值
                
Others		: 
**********************************************************/
int16 FIFO_find(ST_QUEUE *st_fifo, uint08 value)
{
	uint08 len, i, index = 0;
	
	len = FIFO_data_length(st_fifo);
	
	index = st_fifo->front;
	for(i = 0; i < len; i++)
	{
		if(value == st_fifo->FIFO[index])
			return index;
		index = (index+1) % st_fifo->FIFO_SIZE;
	}

	return -1;
	
}



/**********************************************************
Function	: FIFO_delete_rear
Description	: 删除队尾的元素
Calls		:
Called by	: 无
Input		: 
                
Output		: 
Return		: 
                
Others		: 
**********************************************************/
void FIFO_delete_rear(ST_QUEUE *st_fifo)
{
	int16 index;
	
	if(TRUE == FIFO_is_empty(st_fifo))
	{
		return;
	}
	index = (st_fifo->rear-1);
	st_fifo->rear = index < 0 ? (st_fifo->FIFO_SIZE - 1) : index;	
	//uart_send(PRINTF_UART, st_fifo->FIFO, FIFO_data_length(st_fifo));
	return;

}


/**********************************************************
Function	: FIFO_getDataToIndex
Description	: 将队列中的数据取出到index指示的位置为止
Calls		:
Called by	: 无
Input		: 
                
Output		: 
Return		: 返回实际取出的数据长度，当返回为负数时表示失败
                
Others		: 
**********************************************************/
int16 FIFO_getDataToIndex(ST_QUEUE *st_fifo, uint08 *buf, uint08 len, uint08 index)
{
	uint08 i;
	
	i = FIFO_data_length(st_fifo);
	len = len > i ? i : len;
	
	for(i = 0; i < len && (st_fifo->front != index); i++)
	{
		buf[i] = st_fifo->FIFO[st_fifo->front];
		st_fifo->front = (st_fifo->front+1) % st_fifo->FIFO_SIZE;
	}

	if(st_fifo->front != index)//没取到index位置
	{
		return -1;
	}
	buf[i++] = st_fifo->FIFO[st_fifo->front];
	st_fifo->front = (st_fifo->front+1) % st_fifo->FIFO_SIZE;

	return i;

}



/**********************************************************
Function		: FIFO_get_data
Description	: 队头数据出队
Calls		:
Called by	: 无
Input		: 
                
Output		: 
Return		: 
                
Others		: 
**********************************************************/
void FIFO_clear(ST_QUEUE *st_fifo)
{
	st_fifo->front = 0;
	st_fifo->rear = 0;
	return;
}




