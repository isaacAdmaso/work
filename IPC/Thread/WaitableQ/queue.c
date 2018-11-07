#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif 
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>


#include "list.h"
#include "Queue.h"
#define MAGIC 3567978123
#define IS_INVALID(q) (((q) == NULL) || (q)->m_magic != MAGIC)

struct Queue
{

	size_t	m_magic;		  /**< Protector*/	
    int*    m_items;
    size_t  m_size;
    size_t  m_head;    /* Index of head */
    size_t  m_tail;    /* Index of tail */
    size_t  m_nItems;
	sem_t m_empty;
	sem_t m_full;
    pthread_mutex_t m_myMutex;
	List* m_cancelThrQ;
};


static void QueueInit(Queue* _newQueue,size_t _size)
{
	_newQueue->m_size=_size + 1;
	_newQueue->m_head=0;
	_newQueue->m_tail=0;
	_newQueue->m_nItems=0;
	_newQueue->m_magic=MAGIC;
}

Queue* QueueCreate(size_t _size)
{
	Queue* newQueue = NULL;
	
	if(!_size)
	{
		return NULL;
	}
	newQueue = (Queue*)malloc(sizeof(Queue));
	if (newQueue == NULL) 
	{
		return NULL;
	}
	newQueue ->m_items = (int*)malloc((_size + 1)*sizeof(int));
	if (newQueue ->m_items == NULL)
	{
		free(newQueue);
		return NULL;
	}
	if(pthread_mutex_init(&(newQueue->m_myMutex),NULL))
	{
		free(newQueue ->m_items);
		free(newQueue);
		return NULL;	
	}
	if(sem_init(&(newQueue->m_empty), 0, _size))
    {
        free(newQueue ->m_items);
		free(newQueue);
		return NULL;	
    }
	if(sem_init(&(newQueue->m_full), 0, 0))
    {
        free(newQueue ->m_items);
		free(newQueue);
		return NULL;
    }
	if(!(newQueue->m_cancelThrQ = List_Create()))
	{
		free(newQueue ->m_items);
		free(newQueue);
		return NULL;
	}
	QueueInit(newQueue,_size);	
	return newQueue;
}
	
void   QueueDestroy(Queue *_queue)
{
	if(!IS_INVALID(_queue))
	{	
		_queue->m_magic=0;
		free(_queue->m_items);
		List_Destroy(&(_queue->m_cancelThrQ),NULL);
		free(_queue);	
	}
}	 

ADTErr QueueInsert(Queue *_queue, int  _item)
{
	if(IS_INVALID(_queue) ||NULL == _queue->m_items) 
	{
		return ERR_NOT_INITIALIZED;
	}
	sem_wait(&(_queue->m_empty));
	pthread_mutex_lock(&(_queue->m_myMutex));
	_queue->m_items[_queue->m_tail]=_item;
	_queue->m_nItems+=1;
	_queue->m_tail=(_queue->m_tail+1)%(_queue->m_size);
	pthread_mutex_unlock(&(_queue->m_myMutex));
	sem_post(&(_queue->m_full));
	return ERR_OK;
}

ADTErr QueueRemove(Queue *_queue, int *_item)
{
	if(IS_INVALID(_queue) ||NULL == _queue->m_items) 
	{
		return ERR_NOT_INITIALIZED;
	}
	sem_wait(&(_queue->m_full));
	pthread_mutex_lock(&(_queue->m_myMutex));
	*_item=_queue->m_items[_queue->m_head];
	_queue->m_head = (_queue->m_head+1)%_queue->m_size;
	_queue->m_nItems-=1;
	pthread_mutex_unlock(&(_queue->m_myMutex));
	sem_post(&(_queue->m_empty));
	return ERR_OK;
}

int    QueueIsEmpty(const Queue *_queue)
{
	if(IS_INVALID(_queue))
	{
		return 1;
	}
	return _queue->m_nItems==0;
}
void   QueuePrint(const Queue *_queue)
{	
	size_t i,numItems=_queue->m_nItems;
	if(IS_INVALID(_queue))
	{
		return ;
	}

	for(i=0;i<numItems;++i)
	{
		printf("%d,",_queue->m_items[(_queue->m_head+i)%_queue->m_size]);
	}
}
































