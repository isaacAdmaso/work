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


#include "Queue.h"
#define MAGIC 3567978123
#define IS_INVALID(q) (((q) == NULL) || (q)->m_magic != MAGIC)
static const char ECHO_PRODUCER_FIN[]	="\ngoodbye from thread #%ld \n";


struct Queue
{

	size_t	m_magic;		  /**< Protector*/	
    int*    m_items;
    size_t  m_head;    /* Index of head */
    size_t  m_tail;    /* Index of tail */
    size_t  m_nItems;
    pthread_mutex_t m_myMutex;
	pthread_cond_t m_cond;
	size_t m_predicate;
	size_t m_size;

};

/*
static void Locker(Queue* _queue,int _predicate)
{
	pthread_mutex_lock(&(_queue->m_myMutex));
	while(!IS_INVALID(_queue) && (!(_queue->m_R_predicate >= (_queue->m_size - 1))))
	{
		pthread_cond_wait(&(_queue->m_cond), &(_queue->m_myMutex));
	}
	++(_queue->m_predicate);
}
static void UnLock(Queue* _queue)
{
	--(_queue->m_predicate);
	pthread_cond_broadcast(&(_queue->m_cond));
    pthread_mutex_unlock(&(_queue->m_myMutex)); 
}
*/
static void QueueInit(Queue* _newQueue,size_t _size)
{
	_newQueue->m_size =_size;
	_newQueue->m_head = 0;
	_newQueue->m_tail = 0;
	_newQueue->m_nItems = 0;
	_newQueue->m_predicate = 0;
	_newQueue->m_magic = MAGIC;
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
	if(pthread_cond_init(&(newQueue->m_cond),NULL))
	{
		fprintf(stderr, "\nError init of cond\n");
		return NULL;
	}
	QueueInit(newQueue,_size + 1);	
	return newQueue;
}
	
void   QueueDestroy(Queue *_queue)
{
	if(!IS_INVALID(_queue))
	{	
		_queue->m_magic = 0;
		free(_queue->m_items);
		while(_queue->m_predicate > 0)
		{
			pthread_cond_broadcast(&(_queue->m_cond));
	        fprintf(stdout,ECHO_PRODUCER_FIN,pthread_self());
		}
		free(_queue);	
	}
}	 

ADTErr QueueInsert(Queue *_queue, int  _item)
{
	if(IS_INVALID(_queue) ||NULL == _queue->m_items) 
	{
		return ERR_NOT_INITIALIZED;
	}
	/*	Syncronizing
	Locker(_queue);
	*/
	while(!(_queue->m_predicate < _queue->m_size)|| !IS_INVALID(_queue))
	{
		pthread_cond_wait(&(_queue->m_cond), &(_queue->m_myMutex));
	}
	pthread_mutex_lock(&(_queue->m_myMutex));

	/** Logic*/
	_queue->m_items[_queue->m_tail]=_item;
	_queue->m_nItems+=1;
	_queue->m_tail=(_queue->m_tail+1)%(_queue->m_size);

	/* Syncronizing
	UnLock(_queue);
	*/
	++(_queue->m_predicate);
    pthread_mutex_unlock(&(_queue->m_myMutex)); 
	pthread_cond_broadcast(&(_queue->m_cond));

	return ERR_OK;
}

ADTErr QueueRemove(Queue *_queue, int *_item)
{
	if(IS_INVALID(_queue) ||NULL == _queue->m_items) 
	{
		return ERR_NOT_INITIALIZED;
	}
	
	while((!((_queue->m_predicate) && (_queue->m_predicate < _queue->m_size))|| !IS_INVALID(_queue)))
	{
		pthread_cond_wait(&(_queue->m_cond), &(_queue->m_myMutex));
	}
	pthread_mutex_lock(&(_queue->m_myMutex));
	/**

	Locker(_queue);
	 */
	*_item=_queue->m_items[_queue->m_head];
	_queue->m_head = (_queue->m_head+1)%_queue->m_size;
	_queue->m_nItems-=1;
	++(_queue->m_predicate);
    pthread_mutex_unlock(&(_queue->m_myMutex)); 
	pthread_cond_broadcast(&(_queue->m_cond));
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
































