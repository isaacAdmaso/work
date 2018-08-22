#include "Queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAGIC 3567978
#define IS_INVALID(q) (((q) == NULL) || (q)->m_magic != MAGIC)


typedef struct Node
{
	int m_item;
	struct Node* m_next;
}Node;

struct Queue
{
	int m_magic;
	Node* m_head;
	Node* m_tail;
};


Queue* QueueCreate()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if(q == NULL)
	{
		return NULL;
	}
	q->m_head=NULL;
	q->m_tail=NULL;
	q->m_magic=MAGIC;
	return q;
}

void NodeDestroy(Node *_node)
{
	if (_node == NULL)
	{
		return;
	}
	free(_node);
}

void   QueueDestroy(Queue *_queue)
{
	Node *cur,*nxt;
	if(IS_INVALID(_queue))
	{
		return;
	}
	cur=_queue->m_head;
	nxt=_queue->m_head;
	while(cur!=NULL)
	{
		nxt = cur->m_next;
		free(cur);
		cur=nxt;
	}
	free(_queue);
}
	

Node* NodeCreate(int _data)
{
	Node *newNode =(Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->m_item=_data;
	newNode->m_next=NULL;
	return newNode;
}

ADTErr QueueRemove(Queue *_queue, int *_item)
{
	Node *head_helder=(Node*)malloc(sizeof(Node));
	if(IS_INVALID(_queue) || _item == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	if(_queue->m_head == NULL)
	{
		return ERR_UNDERFLOW;
	}
	head_helder = _queue->m_head;
	_queue->m_head = _queue->m_head->m_next;
	*_item =head_helder->m_item;
	NodeDestroy(head_helder);
	return ERR_OK;
} 
	
ADTErr QueueInsert(Queue *_queue, int  _item)
{
	Node *tail_helder,*newNode;
	newNode=NodeCreate(_item);
	if(IS_INVALID(_queue) || newNode == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	if(_queue->m_head == NULL)
	{
		_queue->m_head=newNode;
		_queue->m_tail=newNode;
		return ERR_OK;
	}
	tail_helder=_queue->m_tail;
	_queue->m_tail=newNode;
	tail_helder->m_next=_queue->m_tail;
	return ERR_OK;
}

int  QueueIsEmpty(const Queue *_queue)
{
	if(IS_INVALID(_queue))
	{
		return 1;
	}
	return _queue->m_head==_queue->m_tail;
}
void QueuePrint(const Queue *_queue)
{
	Node *cur,*nxt;
	if(IS_INVALID(_queue))
	{
		return;
	}
	cur=_queue->m_head;
	nxt=_queue->m_head;
	printf("(");
	while(cur!=NULL)
	{
		nxt = cur->m_next;
		printf(" %d,",cur->m_item);
		cur=nxt;
	}
	printf(")");
}
	

