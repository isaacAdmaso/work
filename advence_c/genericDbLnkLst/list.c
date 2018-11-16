#include "list_itr.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define MAGIC (void*)0xDEADBEEF
#define IS_INVALID(l) (((l) == NULL) || (l)->m_head.m_item != MAGIC)


typedef struct Node
{
	void* m_item;
	struct Node* m_next;
	struct Node* m_prev;
}Node;

struct List
{
	Node m_head;
	Node m_tail;
};


/** 
 * @brief Create a list
 * 
 * @returns a pointer to the created list.
 * @retval NULL on failure due to allocation failure
 */
List* List_Create(void)
{
	List* l = (List*)malloc(sizeof(List));
	if(!l)
	{
		return NULL;
	}
	l->m_tail.m_item = NULL;
	l->m_head.m_next = &(l->m_tail);
	l->m_head.m_prev = NULL;
	l->m_tail.m_prev = &(l->m_head);
	l->m_tail.m_next = NULL;
	l->m_head.m_item = MAGIC;
	return l;
}
/**
 * @brief add a node after _node (insert after)
 * 
 * @param _node 
 * @param _data 
 * @return List_Result LIST_ALLOCATION_ERROR if malloc fail LIST_SUCCESS in success
 */
static List_Result NodeCreate(Node *_node, void* _data)
{
	Node *newNode;
		
	newNode =(Node*)malloc(sizeof(Node));
	if (!newNode)
	{
		return LIST_ALLOCATION_ERROR;
	}
	newNode->m_item = _data;
	newNode->m_next = _node->m_next;
	newNode->m_prev = _node;
	newNode->m_next->m_prev = newNode;
	_node->m_next = newNode;
	return LIST_SUCCESS;
}
/**
 * @brief destroy node
 * 
 * @param _node 
 * @param _data 
 * @return List_Result 
 */
static List_Result NodeDestroy(Node *_node,void** _data)
{
	Node *dataHolder;

	if( !_data || !_node )
	{
		return LIST_NULL_ELEMENT_ERROR;
	}

	*_data = _node->m_item;
	dataHolder = _node;
	_node->m_next->m_prev = _node->m_prev;
	_node->m_prev->m_next = _node->m_next;
	free(dataHolder);
	return LIST_SUCCESS;
}
/** 
 * @brief Add element to head of list
 * @details time complexity: O(1).
 *
 * @params _list A previously created List ADT returned via ListCreate
 * @params _item An item to add to the list
 * @returns error code
 * @retval LIST_SUCCESS on success
 * @retval LIST_UNINITIALIZED_ERROR if the list is not initialized
 * @retval LIST_UNINITIALIZED_ERROR  if _item is NULL
 * @retval LIST_ALLOCATION_ERROR on memory allocation failure
 */
List_Result List_PushHead(List* _list, void* _item)
{
	
	if(IS_INVALID(_list) || NULL == _item )
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	return NodeCreate(&(_list->m_head), _item);
}
/** 
 * @brief Add element to the list's tail
 * @details time complexity O(1).
 *
 * @params _list 
 * @params _data
 * @returns 
 * @retval 
 * @retval 
 */
List_Result List_PushTail(List* _list, void* _item)
{
	if(IS_INVALID(_list) || !_item)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	
	return NodeCreate(_list->m_tail.m_prev,_item);
}

/** @brief Remove element from list's head
 *  @details if successfull, stores a pointer to the removed item in _item
 *  time complexity O(1).
 *
 * @params _list : A previously created List ADT returned via ListCreate
 * @params _pItem: To store a pointer to the removed item in
 * @returns 
 * @retval 
 */
List_Result List_PopHead(List* _list, void** _pItem)
{
	if(IS_INVALID(_list) || !_pItem )
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if(_list->m_head.m_next == &(_list->m_tail))
	{
		return LIST_UNDERFLOW_ERROR;
	}
	return NodeDestroy(_list->m_head.m_next,_pItem);
}

/** @brief Remove element from list's tail
 *  @details time complexity O(1).
 *
 * @params 
 * @returns
 * @retval 
 */
List_Result List_PopTail(List* _list, void** _pItem)
{

	if(IS_INVALID(_list) || !_pItem)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if(_list->m_tail.m_prev == &(_list->m_head))
	{
		return LIST_UNDERFLOW_ERROR;
	}
	return NodeDestroy(_list->m_tail.m_prev,_pItem);
}

/** @brief Get number of elements in the list
 * Average time complexity O(n).
 *
 * @params _list : A previously created List ADT returned via ListCreate
 */
size_t List_Size(const List* _list)
{
	Node *p;
	size_t count;

	if(IS_INVALID(_list))
		return 0;
	
	for (p =_list->m_head.m_next,count=0;p->m_next;p = p->m_next,++count)
	{}
	return count;
}

/** 
 * @brief Destroy list
 * @details Destroys the list completely 
 *          optionally destroys elements using user provided function
 *
 * @params[in] _pList : A pointer to previously created List returned via ListCreate
 *					   on completion *_pList will be null
 * @params[in] _elementDestroy : A function pointer to be used to destroy elements inserted into the list
 *             or a null if no such destroy is required
 */
void List_Destroy(List** _pList, void (*_elementDestroy)(void* _item))
{
	Node *nodePtrToFree;
	if(!_pList || IS_INVALID(*_pList))
	{
		return;
	}
	(*_pList)->m_head.m_item = NULL;
	while ((*_pList)->m_head.m_next != &((*_pList)->m_tail))
	{
		nodePtrToFree = (*_pList)->m_head.m_next;
		if(_elementDestroy)
		{
			_elementDestroy(nodePtrToFree->m_item);
		}
		(*_pList)->m_head.m_next=(*_pList)->m_head.m_next->m_next;
		free(nodePtrToFree);
	}
	free((*_pList));
}


/** 
 * @brief Get iterator to the list's beginning
 *
 * @params _list : list to return begin iterator, pointing at first element
 *                 or at the end if list is empty
 * @return iterator pointing at the list's beginning
 */
ListItr ListItr_Begin(const List* _list)
{
	if(IS_INVALID(_list))
	{
		return NULL;
	}
	return (ListItr)_list->m_head.m_next;
}

/** 
 * @brief Get itertator to the list end
 *
 * @params _list : list to return end iterator
 * @return an iterator pointing at the list's end
 */
ListItr ListItr_End(const List* _list)
{
	if(IS_INVALID(_list))
	{
		return NULL;
	}
	return (ListItr)&(_list->m_tail);

}
/** 
 * @brief retruns none zero if _a and _b iterators refer to same node
 * @warning might be implemented as a macro
 */
int ListItr_Equals(const ListItr _a, const ListItr _b)
{
	Node *_aNode = (Node*)_a,*_bNode = (Node*)_b;
	
	return _aNode == _bNode;
}
/** 
 * @brief Get itertator to the next element from a given iterator
 * @warning if _itr is end iterator it will be returned
 */
ListItr ListItr_Next(ListItr _itr)
{
	Node* node = (Node*)_itr;

	if(!node)
		return NULL;
	return (ListItr)node->m_next;
}
/** 
 * @brief Get itertator to the previous element
 * @warning if _itr is begin iterator it will be returned
 */
ListItr ListItr_Prev(ListItr _itr)
{
	Node* node = (Node*)_itr;

	if( !node || !(node->m_prev) )
		return NULL;
	
	return (ListItr)node->m_prev;
}

/** 
 * @brief Get data from the list node the iterator is pointing to
 *
 * @params _itr : A list iterator
 * @return the data the iterator is pointing at or NULL if pointing to the end
 */
void* ListItr_Get(ListItr _itr)
{
	Node* node = (Node*)_itr;

	if( !node)
		return NULL;
	return node->m_item;
}

/** 
 * @brief Set data at the node where the iterator is pointing at
 * @return the data from the node to be changed
 */
void* ListItr_Set(ListItr _itr, void* _element)
{
	Node *node = (Node*)_itr;
	void* itemR = NULL;

	if( !node || !_element)
		return NULL;
	itemR = node->m_item;
	node->m_item = _element;

	return itemR;
}

/** 
 * @brief Inserts a new node before node the iterator is pointing at
 * @return an iterator pointing at the element inserted or NULL on error
 */
ListItr ListItr_InsertBefore(ListItr _itr, void* _element)
{
	Node* node = (Node*)_itr;
	List_Result  error = LIST_UNINITIALIZED_ERROR;

	if( !node || !_element || !node->m_prev)
		return NULL;
	error = NodeCreate(node->m_prev,_element);
	if(LIST_SUCCESS != error)
		return NULL;
	return (ListItr)node->m_prev;
}

/** 
 * @brief Removes the node the iterator is pointing at
 *
 * @params _itr : A list iterator
 * @return the removed data
 */
void* ListItr_Remove(ListItr _itr)
{
	Node* node = (Node*)_itr;
	void *item = NULL;
	List_Result error = LIST_UNINITIALIZED_ERROR;

	if(!node || !(node->m_next))
		return NULL;
	error = NodeDestroy(node,&item);
	if(LIST_SUCCESS != error)
		return NULL;
	return item;
}




