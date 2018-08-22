#include "LIST.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAGIC 3567978
#define IS_INVALID(l) (((l) == NULL) || l->m_tail.m_item != MAGIC)


typedef struct Node
{
	int m_item;
	struct Node* m_next;
	struct Node* m_prev;
}Node;

struct List_t
{
	Node m_head;
	Node m_tail;
};


List_t* ListCreate()
{
	List_t* l = (List_t*)malloc(sizeof(List_t));
	if(l == NULL)
	{
		return NULL;
	}
	l->m_head.m_next=&(l->m_tail);
	l->m_head.m_prev=NULL;
	l->m_tail.m_item=MAGIC;
	l->m_tail.m_next=NULL;
	l->m_tail.m_prev=&(l->m_head);
	return l;
}
void NodeDestroy(Node *_node)
{
	if (_node == NULL)
	{
		return;
	}
	free(_node);
}


void   ListDestroy(List_t *_list)
{
	Node *cur,*nxt;
	if(IS_INVALID(_list))
	{
		return;
	}
	cur=_list->m_head.m_next;
	nxt=_list->m_head.m_next;
	while(cur!=_list->m_tail.m_prev)
	{
		nxt = cur->m_next;
		free(cur);
		cur=nxt;
	}
	free(_list);
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
	newNode->m_prev=NULL;
	return newNode;
}
/*
ADTErr List_tRemove(List_t *_List_t, int *_item)
{
	Node *head_helder=(Node*)malloc(sizeof(Node));
	if(IS_INVALID(_List_t) || _item == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	if(_List_t->m_head == NULL)
	{
		return ERR_UNDERFLOW;
	}
	head_helder = _List_t->m_head;
	_List_t->m_head = _List_t->m_head->m_next;
	*_item =head_helder->m_item;
	NodeDestroy(head_helder);
	return ERR_OK;
} 
	
ADTErr List_tInsert(List_t *_List_t, int  _item)
{
	Node *tail_helder,*newNode;
	newNode=NodeCreate(_item);
	if(IS_INVALID(_List_t) || newNode == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	if(_List_t->m_head == NULL)
	{
		_List_t->m_head=newNode;
		_List_t->m_tail=newNode;
		return ERR_OK;
	}
	tail_helder=_List_t->m_tail;
	_List_t->m_tail=newNode;
	tail_helder->m_next=_List_t->m_tail;
	return ERR_OK;
}

int  List_tIsEmpty(const List_t *_List_t)
{
	if(IS_INVALID(_List_t))
	{
		return 1;
	}
	return _List_t->m_head==_List_t->m_tail;
}
void List_tPrint(const List_t *_List_t)
{
	Node *cur,*nxt;
	if(IS_INVALID(_List_t))
	{
		return;
	}
	cur=_List_t->m_head;
	nxt=_List_t->m_head;
	printf("(");
	while(cur!=NULL)
	{
		nxt = cur->m_next;
		printf(" %d,",cur->m_item);
		cur=nxt;
	}
	printf(")");
}
	
*/
