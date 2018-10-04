#include "bin_tree.h"
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>

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
	return t;
}


static Node* BSTreeItr_Begin_Rec(Node* _node)
{
    if( NULL == _node->m_left)
    {
        return _node;
    }
    return BSTreeItr_Begin_Rec(_node->m_left);
}
/** 
 * @brief Get an in-order iterator to the tree's begin 
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
        return (BSTreeItr)&_tree->m_root;
    }
    return (BSTreeItr)BSTreeItr_Begin_Rec(_tree->m_root.m_left);
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

static Node* NodeInsertHelper(Node* _node,Node* _dataN,LessComparator _less)
{
	Node* rtNode;

	if(NULL == _node )
    {
        
        return _dataN;
    }
    if(_less( _node->m_data,_dataN->m_data))
	{
		rtNode = NodeInsertHelper(_node->m_right,_dataN,_less);
		_node->m_right = rtNode;
		rtNode->m_parent = _node;
	}
	else if(_less(_dataN->m_data , _node->m_data))
	{
		rtNode = NodeInsertHelper(_node->m_left,_dataN,_less);
		_node->m_left = rtNode;
		rtNode->m_parent = _node;
	}
	else
	{
		return NULL;

	} 
	return rtNode;
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
	if(_tree->m_root.m_left == NULL)
	{
		_tree->m_root.m_left = newNode;
		newNode->m_parent = _tree->m_root.m_left;
	}
    newItr = (BSTreeItr)NodeInsertHelper(_tree->m_root.m_left,newNode,_tree->m_compere);
	return  (NULL == newItr) ? (BSTreeItr)&_tree->m_root : newItr;
}





static void NodeDestroyHelpr(Node* _node, void (*_destroyer)(void*))
{
	if(NULL == _node)
	{
		return;
	}
	NodeDestroyHelpr(_node->m_left,_destroyer);
	NodeDestroyHelpr(_node->m_right,_destroyer);
	if(NULL != _destroyer)
	{
		_destroyer(_node->m_data);
	}
	free(_node);
}
	

/** 
 * @brief Destroy tree
 * Destroys the tree, freeing the memory.
 * If supplied with non-NULL destroyer function, frees items in tree.
 * Average time complexity: O(1)..O(n) (depends on memory freeing)
 *
 * @params _tree : A previously created Tree ADT returned via BSTreeCreate
 * @params _destroyer : A function to destroy the data in the tree (may be NULL if unnecessary)
 */
void  BSTree_Destroy(BSTree* _tree, void (*_destroyer)(void*))
{
	if(IS_INVALID(_tree))
	{
		return ;
	}
	_tree->m_root.m_data = NULL;
	NodeDestroyHelpr(_tree->m_root.m_left, _destroyer);
	free(_tree);
}


/** 
 * @brief Compare two iterators
 *
 * @param _a, _b : Iterators to compare
 * @return : 0 if are not the same 
 *           any none zero value if iterators are the same
 */
int BSTreeItr_Equals(BSTreeItr _a, BSTreeItr _b)
{
	Node *_aNode = (Node*)_a,*_bNode = (Node*)_b;
	
    assert(NULL != _a && NULL != _b); 
	return _aNode == _bNode;
}


static Node* first_Has_Right(Node* _node,Node* _chkN)
{
	if(_chkN == _node->m_left || _node->m_parent == NULL)
	{
		return _node;
	}
	return  first_Has_Right(_node->m_parent,_node);
}
/** 
 * @brief Get iterator to the next element from current iterator
 * complexity: O(?)
 *
 * @params _it : A tree iterator
 * @returns an iterator pointing at the next element after _it or end iterator.
 */
BSTreeItr BSTreeItr_Next(BSTreeItr _it)
{
	Node* node = (Node*)_it;
	
	if(node->m_right != NULL)
	{
		return (BSTreeItr)BSTreeItr_Begin_Rec(node->m_right);
	}
	else 
	{
		return (BSTreeItr)first_Has_Right(node->m_parent,node);
	}
}


static BSTreeItr Has_Left_Rec(Node* _node)
{
    if( NULL == _node->m_right)
    {
        return (BSTreeItr)_node;
    }
    return Has_Left_Rec(_node->m_right);
}

static BSTreeItr Dont_Hv_Left_Rec(Node* _node,Node* _chkN)
{

	if(_chkN == _node->m_right || _node->m_parent == NULL)
	{
		return (BSTreeItr) _node;
	}
	return  Dont_Hv_Left_Rec(_node->m_parent,_node);
}
/** 
 * @brief Get iterator to the previous element from current iterator
 *
 * @param _it : A tree iterator
 * @return an iterator pointing at the previous element
 * or to the beginning if _it points to the beginning
*/
BSTreeItr BSTreeItr_Prev(BSTreeItr _it)
{
	Node* node = (Node*)_it;
	
	if(node->m_left != NULL)
	{
		return Has_Left_Rec(node->m_left);
	}
	else 
	{
		return Dont_Hv_Left_Rec(node->m_parent,node);
	}
}

/** 
 * @brief Removes element from tree
 * @details Remove element pointed to by _it and rearranges the tree so that it maintains binary search tree arrangement
 * Average/Worst time complexity O(?).
 *
 * @param _it : A tree iterator
 * @return removed item or null on failure
 */
void* BSTreeItr_Remove(BSTreeItr _it)
{
	Node* node = (Node*)_it;
	void* item = NULL;
	Node* nFree = NULL;

	if(NULL == node || NULL == node->m_parent )
	{
		return NULL;
	}
	if(NULL == node->m_left && NULL == node->m_right)
	{
		item = node->m_data;
		free(node);
	}
	else if(NULL == node->m_left)
	{
		nFree = node->m_right;
		nFree->m_parent = node->m_parent;
		item = node->m_data;
		free(node);
	}
	else if (NULL == node->m_right)
	{
		nFree = node->m_left;
		nFree->m_parent = node->m_parent;
		item = node->m_data;
		free(node);
	}
	else
	{
		nFree = BSTreeItr_Begin_Rec(node->m_right);
		item = node->m_data;
		node->m_data = nFree->m_data;
		free(nFree);	
	}
	return item;
}


/*
BSTreeItr NodeIsDataFoundHElper(Node* _node, PredicateFunction _predicate, void* _context)
{
	if(NULL == _node)
	{
		return NULL;
	}
	if(!_predicate(_context ,_node->m_data))
	{
		return (BSTreeItr)_node;
	}
	return NodeIsDataFoundHElper(_node->m_left,_predicate,_context) || NodeIsDataFoundHElper(_node->m_right,_predicate,_context);
}

 * @brief Search the first element for which the given predicate returns 0
 * iterating using in-order manner over elements
 * O(k * n) where O(k) is the time complexity of the predicate
 *
 * @param _tree : A previously created Tree ADT returned via BSTreeCreate
 * @param _predicate : Predicate function
 * @param _params : Predicate parameters
 * @return an iterator pointing to the first data found, to end of tree if not found or NULL on NULL input
 *//*
BSTreeItr BSTree_FindFirst(const BSTree* _tree, PredicateFunction _predicate, void* _context)
{
	if(IS_INVALID(_tree) || NULL == _context)
	{
		return NULL;
	}
	return NodeIsDataFoundHElper(_tree->m_root, _data);
}
*/

/*
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
	

*/









