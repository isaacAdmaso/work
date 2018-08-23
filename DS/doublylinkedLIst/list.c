#include "LIST.h"
#include<stdio.h>
#include<stdlib.h>
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
	l->m_head.m_item=MAGIC;
	l->m_tail.m_item=MAGIC;
	l->m_tail.m_prev=&(l->m_head);
	l->m_tail.m_next=NULL;
	return l;
}
/*
*/

void   ListDestroy(List_t *_list)
{	
	Node *nodePtrToFree;
	if(IS_INVALID(_list))
	{
		return;
	}	
	nodePtrToFree=(Node*)malloc(sizeof(Node));
	while (_list->m_head.m_next != &(_list->m_tail))
	{
		nodePtrToFree=(_list->m_head.m_next);
		_list->m_head.m_next=_list->m_head.m_next->m_next;
		free(nodePtrToFree);
	}
	free(_list);
}

/*
	
	
	Node *cur,*lst_node,*nxt;
	if(IS_INVALID(_list))
	{
		return;
	}
	if(_list->m_m_head.m_next==&_list->m_tail)
	{
		free(_list);
		return;
	}
	cur = _list->m_m_head.m_next;
	nxt = cur;
	lst_node=&_list->m_tail;
	while(cur!=lst_node)
	{
		nxt=nxt->m_next;
		free(cur);
		cur=nxt;
	}
	free(_list);
}
	
*/
ADTErr NodeCreate(int _data,Node *_node)
{
	Node *newNode;
	if(_node == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}	
	newNode =(Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return ERR_REALLOCATION_FAILED;
	}
	newNode->m_item=_data;
	newNode->m_next=_node->m_next;
	newNode->m_prev=_node;
	newNode->m_next->m_prev=newNode;
	_node->m_next=newNode;
	return ERR_OK;
}
	
	


ADTErr ListPushHead(List_t *_list, int  _item)
{
	if(IS_INVALID(_list))
	{
		return ERR_NOT_INITIALIZED;
	}
	return NodeCreate(_item,&(_list->m_head));
}
	
ADTErr ListPushTail(List_t *_list, int  _item)
{
	if(IS_INVALID(_list))
	{
		return ERR_NOT_INITIALIZED;
	}
	
	return NodeCreate(_item,_list->m_tail.m_prev);
}
		
ADTErr NodeDestroy(Node *_node,int *_item)
{
	Node *dataHelder;
	if (_node == NULL )
	{
		return ERR_NOT_INITIALIZED;
	}
	*_item=_node->m_item;
	dataHelder=_node;
	_node->m_next->m_prev=_node->m_prev;
	_node->m_prev->m_next=_node->m_next;
	free(dataHelder);
	return ERR_OK;
}


ADTErr ListPopHead(List_t *_list, int *_item)
{

	if(IS_INVALID(_list) || _item == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	if(_list->m_head.m_next==&(_list->m_tail))
	{
		return ERR_UNDERFLOW;
	}
	return NodeDestroy(_list->m_head.m_next,_item);
}


/*	
	
	Node* p = data_free;
	if(IS_INVALID(_list) || _item == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	*_item = _list->m_m_head.m_next->m_item;
	data_free=_list->m_m_head.m_next->m.next;
	_list->m_m_head.m_next=_list->m_m_head.m_next->m_next;
	free(data_free);
}
*/
ADTErr ListPopTail(List_t *_list, int *_item)
{

	if(IS_INVALID(_list) || _item == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	if(_list->m_tail.m_prev==&(_list->m_head))
	{
		return ERR_UNDERFLOW;
	}
	return NodeDestroy(_list->m_tail.m_prev,_item);
}

		
size_t ListCountItems(List_t *_list)
{
	Node *p;
	size_t count;
	if(ListIsEmpty(_list))
	{
		return 0;
	}
	for (p =_list->m_head.m_next,count=0;p->m_next != NULL;p=p->m_next,++count)
	{}
	return count;
}


int    ListIsEmpty(const List_t *_list)
{
	if(IS_INVALID(_list))
	{
		return 1;
	}
	return _list->m_head.m_next==&(_list->m_tail);
}

void ListPrint(const List_t *_list)
{
	Node *cur;
	if(IS_INVALID(_list))
	{
		return;
	}
	printf("(");
	cur = _list->m_head.m_next;
	while(cur != &(_list->m_tail))
	{
		printf("%d ,",_list->m_head.m_next->m_item);
		cur=cur->m_next;
	}
	printf(")");
}
		
	
	

/*

	Node* data_free;
	if(IS_INVALID(_list) || _item == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	*_item = _list->m_m_head.m_next->m_item;
	data_free=_list->m_m_head.m_next;
	_list->m_m_head.m_next=_list->m_m_head.m_next->next;
	free(data_free);
*/	
	


/*

ADTErr List_tRemove(List_t *_List_t, int *_item)
{
	Node *m_head_helder=(Node*)malloc(sizeof(Node));
	if(IS_INVALID(_List_t) || _item == NULL)
	{
		return ERR_NOT_INITIALIZED;
	}
	if(_List_t->m_m_head == NULL)
	{
		return ERR_UNDERFLOW;
	}
	m_head_helder = _List_t->m_m_head;
	_List_/t->m_m_head = _List_t->m_m_head.m_next;
	*_item =m_head_helder->m_item;
	NodeDestroy(m_head_helder);
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
	if(_List_t->m_m_head == NULL)
	{
		_List_t->m_m_head=newNode;
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
	return _List_t->m_m_head==_List_t->m_tail;
}
{
	Node *cur,*nxt;
	if(IS_INVALID(_List_t))
	{
		return;
	}
	cur=_List_t->m_m_head;
	nxt=_List_t->m_m_head;
	printf("(");
	while(cur!=NULL)
	{
		nxt = cur->m_next;
		printf(" %d,",cur->m_item);
		cur=nxt;
	}
	printf(")");
}
	


int main(){

	List_t *_List_t;
	int i,val;
	int expected[] = { 0, 1, 2, 3, 4 };
	_List_t = ListCreate();
	for (i = 0; i < 5; ++i)
	{
		ListPushHead(_List_t, i);
		ListPopTail(_List_t, &val);
		printf("%d\n",val);
	}
	ListDestroy(_List_t);
	return 0;
}
*/

