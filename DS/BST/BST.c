#include "BST.h"
#include<stdio.h>
#include<stdlib.h>
#define MAGIC 29384502
#define IS_INVALID(q) (((q) == NULL) || (q)->m_magic != MAGIC)




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
	if(t == NULL)
	{
		return NULL;
	}
	t->m_root = NULL;
	t->m_magic = MAGIC;
	return t;
}

int NodeIsDataFoundHElper(Node* _node,int _data)
{
	if(_node == NULL)
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
	if(IS_INVALID(_tree) || _tree->m_root == NULL)
	{
		return ERR_NOT_EXISTS;
	}
	return NodeIsDataFoundHElper(_tree->m_root, _data);
}

Node* NodeCreate(int _data)
{
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL)
	{
		return NULL;
	}
    newNode->m_data = _data;
    newNode->m_left = newNode->m_right = NULL;
    return newNode;
}	

Node* NodeInsertHelper(Node* _nodeRoot,Node* _dataN,ADTErr* _errAlrdiExist)
{
	if(_nodeRoot == NULL)
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
	if(newNode == NULL)
	{
		return ERR_ALLOCATION_FAILED;
	}
	_tree->m_root=NodeInsertHelper(_tree->m_root,newNode,&ErrAlrdiExist);
	
	return ErrAlrdiExist;
}

void NodePrint(Node* _node,TreeTraverse _mode)
{
	if(_node == NULL)
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
	if(_tree == NULL)
	{
		return;
	}
	NodePrint(_tree->m_root,_traverseMode);
}
	
void NodeDestroyHelpr(Node* _node)
{
	if(_node == NULL)
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
	NodeDestroyHelpr(_tree->m_root);
}

/*
typedef enum
{
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
} TreeTraverse;
#endif
*/

