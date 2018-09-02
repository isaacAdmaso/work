#include "BST.h"
#include<stdio.h>
#include<stdlib.h>
#define MAGIC 29384502
#define IS_INVALID(T) (((T) == NULL) || (T)->m_magic != MAGIC)




typedef struct Node
{
    int     m_data;
    struct Node*   m_left;
    struct Node*   m_right;
}Node;

struct Tree
{
	int     m_magic;
    Node*   m_root;
};
 
Tree*   TreeCreate()
{
	Tree* t;
	
	t = (Tree*)malloc(sizeof(Tree));
	if(NULL == t)
	{
		return NULL;
	}
	t->m_root = NULL;
	t->m_magic = MAGIC;
	return t;
}

int NodeIsDataFoundHElper(Node* _node,int _data)
{
	if(NULL == _node)
	{
		return ERR_NOT_EXISTS;
	}
	if(_data == _node->m_data)
	{
		return ERR_OK;
	}
	return (_data > _node->m_data) ? NodeIsDataFoundHElper(
	_node->m_right, _data) : NodeIsDataFoundHElper(
	_node->m_left, _data);
}

int TreeIsDataFound(const Tree* _tree, int _data)
{
	if(IS_INVALID(_tree) || NULL == _tree->m_root)
	{
		return ERR_NOT_INITIALIZED;
	}
	return NodeIsDataFoundHElper(_tree->m_root, _data);
}

static Node* NodeCreate(int _data)
{
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	if(NULL == newNode)
	{
		return NULL;
	}
    newNode->m_data = _data;
    newNode->m_left = newNode->m_right = NULL;
    return newNode;
}	

static Node* NodeInsertHelper(Node* _nodeRoot,Node* _dataN,ADTErr* _errAlrdiExist)
{
	if(NULL == _nodeRoot)
	{
		return _dataN;
	}
	if(_dataN->m_data > _nodeRoot->m_data)
	{
		_nodeRoot->m_right=NodeInsertHelper(_nodeRoot->m_right,_dataN,_errAlrdiExist);
	}
	else if(_dataN->m_data < _nodeRoot->m_data)
	{
		_nodeRoot->m_left=NodeInsertHelper(_nodeRoot->m_left,_dataN,_errAlrdiExist);
	}
	if(_dataN->m_data == _nodeRoot->m_data)
	{
		*_errAlrdiExist = ERR_ALREADY_EXISTS;
		return _nodeRoot;
	}
	return _nodeRoot;
}


ADTErr  TreeInsert(Tree* _tree, int _data)
{
	ADTErr ErrAlrdiExist=ERR_OK;
	Node *newNode;	
	if(IS_INVALID(_tree))
	{
		return ERR_NOT_INITIALIZED;
	}
	newNode = NodeCreate(_data);
	if(NULL == newNode)
	{
		return ERR_ALLOCATION_FAILED;
	}
	_tree->m_root=NodeInsertHelper(_tree->m_root,newNode,&ErrAlrdiExist);
	
	return ErrAlrdiExist;
}

static void NodePrint(Node* _node,TreeTraverse _mode)
{
	if(NULL == _node)
	{
		return;
	}
	switch(_mode)
	{
		case(PRE_ORDER):
			printf("%d ",_node->m_data);
			NodePrint(_node->m_left,_mode);
			NodePrint(_node->m_right,_mode);
			break;
		case(IN_ORDER):
			NodePrint(_node->m_left,_mode);
			printf("%d ",_node->m_data);
			NodePrint(_node->m_right,_mode);
			break;
		case(POST_ORDER):
			NodePrint(_node->m_left,_mode);
			NodePrint(_node->m_right,_mode);
			printf("%d ",_node->m_data);
			break;				
		default:
			break;
	}
} 		
		
void  TreePrint(const Tree* _tree, TreeTraverse _traverseMode)
{
	if(NULL == _tree)
	{
		return;
	}
	NodePrint(_tree->m_root,_traverseMode);
}
	
void NodeDestroyHelpr(Node* _node)
{
	if(NULL == _node)
	{
		return;
	}
	NodeDestroyHelpr(_node->m_left);
	NodeDestroyHelpr(_node->m_right);
	free(_node);
}
	
	


void  TreeDestroy(Tree* _tree)
{
	if(IS_INVALID(_tree))
	{
		return ;
	}
	_tree->m_magic = -1;
	NodeDestroyHelpr(_tree->m_root);
	free(_tree);
}

/*
int main()
{
	Tree* t = TreeCreate();
	int data[] = {1,2,3,4,5, 6,7,8,9};
	for(int i=0;i<9;++i)
	{
		TreeInsert(t,i);
	}
	for(int i=0;i<20;++i)
	{
		TreeIsDataFound(if(t,i))
		{
			TreeInsert(t,i);
		}
	}
	TreePrint(t,PRE_ORDER);
	printf("\n\n");
	
	TreePrint(t,IN_ORDER);
	printf("\n\n");
	
	TreePrint(t,POST_ORDER);
}
*/
	











