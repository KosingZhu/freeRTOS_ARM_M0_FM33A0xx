#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_

#pragma pack(1)
typedef struct
{
	uint08 *FIFO; /* ��ʼ����ʱ����Ҫָ��FIFO��ַ */
	uint16 FIFO_SIZE; /* ��ʼ��ʱҪָ��FIFO����󳤶� */	
	uint08 front; /* ��ͷ */
	uint08 rear; /* ��β */
} ST_QUEUE; 
#pragma pack()





void init_FIFO(ST_QUEUE *st_fifo, uint08* fifo_addr, const uint08 fifo_size);
uint08 FIFO_is_full(ST_QUEUE *st_fifo);
uint08 FIFO_is_empty(ST_QUEUE *st_fifo);
uint08 FIFO_data_length(ST_QUEUE* st_fifo);
uint08 FIFO_enter_data(ST_QUEUE *st_fifo, const uint08 dat);
uint08 FIFO_get_data(ST_QUEUE *st_fifo, uint08 *dat);
uint08 FIFO_pop_data(ST_QUEUE *st_fifo);
uint08 FIFO_top_data(ST_QUEUE *st_fifo, uint08 *dat);
uint08 FIFO_travel(ST_QUEUE *st_fifo, uint08 *buf, uint08 len);
void FIFO_clear(ST_QUEUE *st_fifo);
int16 FIFO_find(ST_QUEUE *st_fifo, uint08 value);
int16 FIFO_getDataToIndex(ST_QUEUE *st_fifo, uint08 *buf, uint08 len, uint08 index);
void FIFO_delete_rear(ST_QUEUE *st_fifo);
uint08 FIFO_rear_data(ST_QUEUE *st_fifo);




#endif

