#include "../../include/Queue.h"
#define MAGIC 3567978
#define IS_INVALID(q) (((q) == NULL) || (q)->m_magic != MAGIC)


struct Queue
{
	int m_magic;
	List* m_list;
};


Queue* Queue_Create(void)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if(q == NULL)
	{
		return NULL;
	}
	q->m_list = List_Create();
	if(NULL == q->m_list)
	{
		free(q);
		return NULL;
	}
	q->m_magic=MAGIC;
	return q;
}


void   Queue_Destroy(Queue *_queue, void (*_elementDestroy)(void* _item))
{
	if(IS_INVALID(_queue))
	{
		return;
	}
	_queue->m_magic = 0;
	List_Destroy(&(_queue->m_list),_elementDestroy);
	free(_queue);
}
	

Queue_Result Queue_Remove(Queue *_queue, void **_item)
{
	if(IS_INVALID(_queue) || _item == NULL)
	{
		return QUEUE_NOT_INITIALIZED;
	}
	if(List_Size(_queue->m_list) == 0)
	{
		return QUEUE_UNDERFLOW;
	}
	List_PopHead(_queue->m_list,_item);
	return QUEUE_SUCCESS;
} 

Queue_Result Queue_Insert(Queue *_queue, void*  _item)
{
	if(IS_INVALID(_queue) || _item == NULL)
	{
		return QUEUE_NOT_INITIALIZED;
	}
	List_PushTail(_queue->m_list,_item);
	return QUEUE_SUCCESS;
}

size_t  Queue_IsEmpty(const Queue *_queue)
{
	if(IS_INVALID(_queue))
	{
		return 0;
	}
	return List_Size(_queue->m_list) == 0;
}
