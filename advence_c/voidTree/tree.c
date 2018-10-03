#include "bin_tree.h"
#include<stdio.h>
#include<stdlib.h>

#define MAGIC (void*)0xDEADBEEF
#define IS_INVALID(T) (((T) == NULL) || (T)->m_root.m_data != MAGIC)




typedef struct Node
{
    void*     m_data;
    struct Node*   m_left;
    struct Node*   m_right;
    struct Node*   m_parent;
}Node;

struct BSTree
{
    Node   m_root;
    LessComparator m_compere;
};

/** 
 * @brief Create a binary search tree
 * Creates an empty binary search tree with sentinel
 * 
 * @param _less: A comparison function 
 *				that returns true (none zero value) if x < y 
 *				and false (zero) otherwise.
 * @return a pointer to the newly created tree.
 * @retval NULL on failure due to allocation failure or NULL function pointer given
 */
BSTree* BSTree_Create(LessComparator _less)
{
	BSTree* t;
	
	t = (BSTree*)calloc(1,sizeof(BSTree));
	if(NULL == t)
	{
		return NULL;
	}
	t->m_compere = _less;
	t->m_root.m_data = MAGIC;
    t->m_root.m_left = NULL;
	return t;
}


static BSTreeItr BSTreeItr_Begin_Rec(Node* _node)
{
    if( NULL == _node->m_left)
    {
        return (BSTreeItr)_node;
    }
    return BSTreeItr_Begin_Rec(_node->m_left);
}
/** 
 * @brief Get an in-order itertator to the tree's begin 
 *
 * @param _tree : tree to create iterator from
 * @return an iterator pointing at the tree's begin or end if tree is empty 
 */
BSTreeItr BSTreeItr_Begin(const BSTree* _tree)
{
    if(IS_INVALID(_tree))
    {
        return NULL;
    }
    if(_tree->m_root.m_left == NULL)
    {
        return (BSTreeItr)_tree->m_root.m_left;
    }
    return BSTreeItr_Begin_Rec(_tree->m_root.m_left);
}
/** 
 * @brief Get itertator to the tree's end (in order)
 *
 * @param _tree : tree to create iterator from
 * @return an iterator pointing at the tree's end
 */
BSTreeItr BSTreeItr_End(const BSTree* _tree)
{
    if(IS_INVALID(_tree))
    {
        return NULL;
    }
    return (BSTreeItr)&_tree->m_root;
}


static Node* NodeCreate(void* _data)
{
	Node* newNode;

	newNode = (Node*)calloc(1,sizeof(Node));
	if(NULL == newNode)
	{
		return NULL;
	}
    newNode->m_data = _data;
    return newNode;
}	

static Node* NodeInsertHelper(Node* _root,Node* _dataN,LessComparator _less)
{
	if(NULL == _root->m_left )
    {
        
        return _dataN;
    }
    
	if(_less( _root->m_data,_dataN->m_data))
	{
		_root->m_right = NodeInsertHelper(_root->m_right,_dataN,_less);
	}
	else if(_less(_dataN->m_data , _root->m_data))
	{
		_root->m_left = NodeInsertHelper(_root->m_left,_dataN,_less);
	}
	else
	{
		return NULL;
	}
	return _root;
}
/** 

 * @brief Add an element to tree if it'snot already there
 * Insert element to binary tree, using the tree's comparison function
 * Average time complexity O(log n).
 * Worst: O(n)
 *
 * @param _tree : A previously created Tree ADT returned via BSTreeCreate
 * @param _item: An item to add to the tree
 * @return iterator pointing to the item added or iterator to end on failure
 * @warning don't allow duplicates
 */

BSTreeItr BSTree_Insert(BSTree* _tree, void* _item)
{
    BSTreeItr newItr = NULL;
	Node *newNode;	

	if(IS_INVALID(_tree))
	{
		return newItr;
	}
	newNode = NodeCreate(_item);
	if(NULL == newNode)
	{
		return (BSTreeItr)&_tree->m_root;
	}
    newItr = (BSTreeItr)NodeInsertHelper(_tree->m_root.m_left,newNode,_tree->m_compere);
	return  (NULL == newItr) ? (BSTreeItr)&_tree->m_root : newItr;
}



/*
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

*/









