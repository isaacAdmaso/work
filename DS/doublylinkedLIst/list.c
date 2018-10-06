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

void   ListDestroy(List_t *_list)
{	
	Node *nodePtrToFree;
	if(IS_INVALID(_list))
	{
		return;
	}
	_list->m_head.m_item = 0;
	_list->m_tail.m_item = 0;
	while (_list->m_head.m_next != &(_list->m_tail))
	{
		nodePtrToFree=(_list->m_head.m_next);
		_list->m_head.m_next=_list->m_head.m_next->m_next;
		free(nodePtrToFree);
	}
	free(_list);
}

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


int	ListIsEmpty(const List_t *_list)
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
		printf("%d ,",cur->m_item);
		cur=cur->m_next;
	}
	printf(")");
}
/*		
	
int main()
{
	List_t *l,*m;
	int val,i,arr[]={1,2,3,3,4,5,56,7,6,3,4,2,34,45,56,0,577,3,8,53};
	l=ListCreate();
	m=ListCreate();
	for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
	{
		ListPushHead(l,i);
		ListPushTail(l,-i);
		printf("%lu\n",ListCountItems(l));
	}
	for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
	{
		ListPushHead(m,arr[i]);
		ListPushTail(m,arr[i]);
		printf("%lu\n",ListCountItems(m));
	}
	for(i=0;i<2*sizeof(arr)/sizeof(arr[0]);++i)
	{
		ListPopHead(l,&val);
		printf("%d\n",val);

		ListPopTail(m,&val);
		printf("%d\n",val);

	}
	ListPrint(l);
	if(ListIsEmpty)
	{
	printf("\n");
	}
	ListPrint(m);
	return 0;
}
*/
	










