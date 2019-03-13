
#include "general.h"

/*ע��Ķ��е���󳤶�Ϊ256-1����ӵ�ÿ���������ֵΪ255*/


/**********************************************************
Function		:init_FIFO
Description	: ���г�ʼ��
Calls		:
Called by	: ��
Input		: fifo_addr  ָ���Ķ����׵�ַ
                fifo_size  ������󳤶�
Output		: st_fifo ��ʼ����Ķ��нṹ
Return		: ��
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
Description	:ȡ�öӶ���Ԫ�أ����Ӷ�����ɾ��
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
Description	:�������У����������е�����д��buf�з���
Calls		:
Called by	: 
Input		: 
                
Output		: 
Return		: ����ʵ��д��buf�е����ݵĸ���
                
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
Description	:������Ԫ�ص�������
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
Description	: �ж϶����Ƿ���
Calls		:
Called by	: ��
Input		: st_fifo ���нṹ�ĵ�ַ
                
Output		: 
Return		: TRUE ����
                FALSE ��δ��
Others		: 
**********************************************************/
uint08 FIFO_is_full(ST_QUEUE *st_fifo)
{

	/* ���front ֻ�� rearС1������Ϊ���� */
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
Description	: �ж϶����Ƿ��
Calls		:
Called by	: ��
Input		: st_fifo ���нṹ�ĵ�ַ
                
Output		: 
Return		: TRUE �ӿ�
                FALSE ��δ��
Others		: 
**********************************************************/
uint08 FIFO_is_empty(ST_QUEUE *st_fifo)
{
	/* front��rearָ�����ͬһ��λ�ã�����Ϊ�ӿ� */
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
Description	: ��֪�����ж��ٸ�����
Calls		:
Called by	: ��
Input		: st_fifo ���нṹ�ĵ�ַ
                
Output		: 
Return		: ���ݸ���
                
Others		: 
**********************************************************/
uint08 FIFO_data_length(ST_QUEUE* st_fifo)
{
	return (st_fifo->rear - st_fifo->front + st_fifo->FIFO_SIZE) % st_fifo->FIFO_SIZE;
}


/**********************************************************
Function		:FIFO_enter_data
Description	: �������β
Calls		:
Called by	: ��
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
Description	: ��ͷ���ݳ���
Calls		:
Called by	: ��
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
Description	:ȡ�ö�β��Ԫ��;�����ڶ��зǿ�ʱ���������򷵻�ֵ������
Calls		:
Called by	: 
Input		: 
                
Output		: 
Return		: ���ض��ж�βԪ��
                
Others		: �ȵ�����ΪFIFO_is_empty()
**********************************************************/
uint08 FIFO_rear_data(ST_QUEUE *st_fifo)
{	
	return st_fifo->FIFO[st_fifo->rear-1];
}


/**********************************************************
Function	: FIFO_find
Description	: �ڶ������ҵ�valueֵ��Ӧ��index
Calls		:
Called by	: ��
Input		: 
                
Output		: 
Return		: ����index,�����ظ���ʱ��ʾδ�ҵ���ֵ
                
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
Description	: ɾ����β��Ԫ��
Calls		:
Called by	: ��
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
Description	: �������е�����ȡ����indexָʾ��λ��Ϊֹ
Calls		:
Called by	: ��
Input		: 
                
Output		: 
Return		: ����ʵ��ȡ�������ݳ��ȣ�������Ϊ����ʱ��ʾʧ��
                
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

	if(st_fifo->front != index)//ûȡ��indexλ��
	{
		return -1;
	}
	buf[i++] = st_fifo->FIFO[st_fifo->front];
	st_fifo->front = (st_fifo->front+1) % st_fifo->FIFO_SIZE;

	return i;

}



/**********************************************************
Function		: FIFO_get_data
Description	: ��ͷ���ݳ���
Calls		:
Called by	: ��
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




