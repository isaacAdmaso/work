#include "Queue.h"
#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>

#define MAGIC 3567978
#define IS_INVALID(q) (((q) == NULL) || (q)->m_magic != MAGIC)

struct Queue
{

	size_t	m_magic;		  /**< Protector*/	
    int*    m_items;
    size_t  m_size;
    size_t  m_head;    /* Index of head */
    size_t  m_tail;    /* Index of tail */
    size_t  m_nItems;
};

Queue* QueueCreate(size_t _size)
{
	Queue* newQueue = NULL;
	
	if(_size==0)
	{
		return NULL;
	}
	newQueue = (Queue*)malloc(sizeof(Queue));
	if (newQueue == NULL) 
	{
		return NULL;
	}
	newQueue ->m_items = (int*)malloc((_size+1)*sizeof(int));
	if (newQueue ->m_items == NULL)
	{
		free(newQueue);
		return NULL;
	}
	newQueue->m_magic=MAGIC;
	newQueue->m_size=_size+1;
	newQueue->m_head=0;
	newQueue->m_tail=0;
	newQueue->m_nItems=0;
	return newQueue;
}
	
void   QueueDestroy(Queue *_queue)
{
	if(!IS_INVALID(_queue))
	{	
		_queue->m_magic=0;
		free(_queue->m_items);
		free(_queue);	
	}
}	 

ADTErr QueueInsert(Queue *_queue, int  _item)
{
	if(IS_INVALID(_queue) ||NULL == _queue->m_items) 
	{
		return ERR_NOT_INITIALIZED;
	}
	if(_queue->m_nItems==_queue->m_size-1)
	{
		return ERR_OVERFLOW;
	}
	_queue->m_items[_queue->m_tail]=_item;
	_queue->m_nItems+=1;
	_queue->m_tail=(_queue->m_tail+1)%(_queue->m_size);
	return ERR_OK;
}

ADTErr QueueRemove(Queue *_queue, int *_item)
{
	if(IS_INVALID(_queue) ||NULL == _queue->m_items) 
	{
		return ERR_NOT_INITIALIZED;
	}
	if(_queue->m_nItems==0)
	{
		return ERR_UNDERFLOW;
	}
	*_item=_queue->m_items[_queue->m_head];
	_queue->m_head = (_queue->m_head+1)%_queue->m_size;
	_queue->m_nItems-=1;
	return ERR_OK;
}

int    QueueIsEmpty(const Queue *_queue)
{
	if(IS_INVALID(_queue))
	{
		return 1;
	}
	return _queue->m_nItems == 0;
}
int QueueSize(const Queue *_queue)
{
	if(IS_INVALID(_queue))
	{
		return 0;
	}
	return _queue->m_nItems;
}
void   QueuePrint(const Queue *_queue)
{	
	size_t i,numItems;
	if(IS_INVALID(_queue))
	{
		return ;
	}
	numItems =_queue->m_nItems;
	for(i=0;i<numItems;++i)
	{
		printf("%d,",_queue->m_items[(_queue->m_head+i)%_queue->m_size]);
	}
}
































