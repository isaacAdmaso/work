#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
	int m_data;
	Node* m_next;
};


Node* ListCreate(int* _arr, int _n)
{
	Node* node;
	if (_n == 0)
	{
		return NULL;
	}
	node = malloc(sizeof(Node));
	node->m_data = *_arr;
	node->m_next = ListCreate(_arr+1, _n-1);
	return node;
}

void ListPrint(Node* _lst)
{
	while (_lst != NULL)
	{
		printf("%d  ", _lst->m_data);
		_lst = _lst->m_next;
	}
	putchar('\n');
}

Node* ListFlip(Node* _node)
{	
	if(_node == NULL)
	{
		return _node;
	}
	Node *cur,*nxt,*prv;
	prv = NULL;
	cur = _node;
	nxt = NULL;
	while(cur!=NULL)
	{
		nxt = cur->m_next;
		cur->m_next = prv;
		prv = cur;
		cur = nxt;
	}
	return prv;
}

Node* ListFlipRec(Node* _node)
{	
	static Node* newH;
	if(_node->m_next == NULL)
	{
		return _node;
	}
	newH = ListFlipRec(_node->m_next);
	_node->m_next->m_next=_node;
	_node->m_next = NULL;
	return newH;
}
	





int main()
{
	int data[] = {1,2,3,4,5, 6,7,8,9};
	Node* flipped;
	Node* list = ListCreate(data, sizeof(data)/sizeof(int));
	ListPrint(list);
	flipped = ListFlip(list);
	ListPrint(flipped);
	ListPrint(list);
	flipped = ListFlipRec(flipped);
	//ListPrint(flipped);
	ListPrint(list);
	flipped = ListFlipRec(flipped);
	ListPrint(flipped);
	return 0;
}













