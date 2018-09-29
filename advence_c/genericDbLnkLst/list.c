#include "list_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAGIC 918312938
#define IS_INVALID(l) (((l) == NULL) || (l)->m_magic != MAGIC)


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
    size_t m_magic;
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
	if(NULL == l)
	{
		return NULL;
	}
	l->m_head.m_next = &(l->m_tail);
	l->m_head.m_prev = NULL;
	l->m_tail.m_prev = &(l->m_head);
	l->m_tail.m_next = NULL;
    l->m_magic = MAGIC;
	return l;
}
/**
 * @brief add a node after _node
 * 
 * @param _node 
 * @param _data 
 * @return List_Result LIST_ALLOCATION_ERROR if malloc fail LIST_SUCCESS in success
 */
static List_Result NodeCreate(Node *_node, void* _data)
{
	Node *newNode;
		
	newNode =(Node*)malloc(sizeof(Node));
	if (newNode == NULL)
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

	if( NULL == *_data)
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
 * @retval LIST_NULL_ELEMENT_ERROR  if _item is NULL
 * @retval LIST_ALLOCATION_ERROR on memory allocation failure
 */
List_Result List_PushHead(List* _list, void* _item)
{
	
	if(IS_INVALID(_list) || NULL == _item)
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
	if(IS_INVALID(_list) || NULL == _item)
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
	if(IS_INVALID(_list) || _pItem == NULL )
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if(_list->m_head.m_next==&(_list->m_tail))
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

	if(IS_INVALID(_list) || _pItem == NULL)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if(_list->m_tail.m_prev==&(_list->m_head))
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
	
	for (p =_list->m_head.m_next,count=0;p->m_next != NULL;p=p->m_next,++count)
	{}
	return count;
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

	if( NULL == _a || NULL == _b)
		return -1;
	
	return _aNode->m_item == _bNode->m_item;
}
/** 
 * @brief Get itertator to the next element from a given iterator
 * @warning if _itr is end iterator it will be returned
 */
ListItr ListItr_Next(ListItr _itr)
{
	Node* node = (Node*)_itr;

	if( NULL == _itr)
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

	if( NULL == _itr)
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

	if( NULL == _itr)
		return NULL;
	return node->m_item;
}

/** 
 * @brief Set data at the node where the iterator is pointing at
 * @return the data from the node to be changed
 */
void* ListItr_Set(ListItr _itr, void* _element)
{
	Node *node;
	void* itemR = NULL;

	if( NULL == _itr || NULL == _element)
		return NULL;
	node = (Node*)_itr;
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

	if( NULL == _itr || NULL == _element || NULL == node->m_prev)
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
	Node* node;
	void *item = NULL;
	List_Result error = LIST_UNINITIALIZED_ERROR;

	if(NULL == _itr)
		return NULL;
	node = (Node*)_itr;
	error = NodeDestroy(node,&item);
	if(LIST_SUCCESS != error)
		return NULL;
	return item;
}
				/**********************************
				 * list func using iterFunc only***
				 * ********************************
				 **********************************/
/** 
 * @brief Finds the first element in a range satsifying a predicate
 * @details find the element for which the predicate reuturns a non zero value
 *  in the half open range [begin..end)
 *
 * @param _begin : start search from here
 * @param _end : end search here - not included
 * @param _predicate : Predicate function
 * @param _context : context to be passed to the predicate
 * @return an iterator pointing to the first node with data found or to _end if not
 * 
 */
ListItr ListItr_FindFirst(ListItr _begin, ListItr _end, PredicateFunction _predicate, void* _context)
{
	ListItr cur;

	if(NULL ==_begin || NULL == _end || NULL == _predicate || NULL == _context)
		return NULL;
	cur = _begin;
	for(cur = _begin;cur != _end || _predicate(ListItr_Get(cur) ,_context);cur = ListItr_Next(cur));
	return cur;
}


/** 
 * @brief count elements in a sub list satisfying predicate
 * @details find the element for which the predicate reuturns a non zero value
 *  in the half open range [begin..end)
 *
 * @param _begin : start search from here
 * @param _end : end search here - not included
 * @param _predicate : Predicate function
 * @param _context : context to be passed to the predicate
 * @return count of all elements e where _predicate(e, _context) != 0
 */
size_t ListItr_CountIf(ListItr _begin, ListItr _end, PredicateFunction _predicate, void* _context)
{
	ListItr cur;
	size_t count = 0;

	if(NULL ==_begin || NULL == _end || NULL == _predicate || NULL == _context)
		return count;
	for(cur = _begin;cur != _end || _predicate(ListItr_Get(cur) ,_context);cur = ListItr_Next(cur), ++count)
	{}
	
	return count;
}


/** 
 * @brief execute an action for all elements in a half open range
 * @details call -action for each element in the range [begin..end)
 * iteration will stop if Action function returns 0 for an element
 *
 * @param _begin: A list iterator to start operations from
 * @param _end : A list iterator to end operations on
 * @param _Action : user provided action function
 * @param _context : Parameters for the function
 * @return ListItr to the element where the iteration stoped. this might be end iterator
 */
ListItr ListItr_ForEach(ListItr _begin, ListItr _end, ListActionFunction _action, void* _context)
{
	ListItr cur;
	void* _item;

	if(NULL ==_begin || NULL == _end || NULL == _action)
		return NULL;
	cur = _begin;
	while(cur != _end)
	{
		_item = ListItr_Get(cur);
		_action(_item , _context);
		cur = ListItr_Next(cur);
	}
	return cur;
}

/** 
 * @brief Sorts a sublist in place using the bubble sort algorithm
 * Complexity O(?)
 *
 * @params _begin : Iterator to sublist start
 * @params _end : Iterator to sublist end
 * @params _less : less compare function
 * 
 */
void ListItr_Sort(ListItr _begin, ListItr _end, LessFunction _less)
{
	int swap;
	ListItr itr,jtr,prvItem;
	void* item;
	void* prvitm;
		
	if(NULL ==_begin || NULL == _end || NULL == _less)
		return;

	for(itr = _begin;itr != _end ;itr = ListItr_Next(itr))
	{
		swap = 0;

		for(jtr = ListItr_Prev( _end); jtr != itr ;jtr = ListItr_Prev(jtr))
		{
			prvItem = ListItr_Prev(jtr);
			prvitm = ListItr_Get(prvItem);
			item = ListItr_Get(jtr);

			if(_less(item,prvitm))	
			{
				ListItr_Set(jtr,prvitm);
				ListItr_Set(prvItem,item);
				swap = 1;
			}
		}
		if(swap == 0)
		{
			break;
		}
	}
}

/** 
 * @brief Splice all element from [_begin.._end) into _dst
 * @details remove all elements from the half open range [_begin.._end)
 * and insert them before _dest
 * O(n)
 *
 * @warning The function assumes that : 
 *  _begin and _end are in the correct order and on the same list
 *  _dest is not between them
 * Otherwise behavior is undefined
 * all three iterators can belong to same list
 */
ListItr ListItr_Splice(ListItr _dest, ListItr _begin, ListItr _end)
{
	ListItr tempV;
	void* temItm;
	int count = 0;


	while(_begin != _end)
	{
		if(_begin == _dest)
		{
			count = 0;
			continue;
		}
		tempV = ListItr_Next(_begin);
		temItm = ListItr_Remove(_begin);
		ListItr_InsertBefore(_dest,temItm);
		_begin = tempV;
		++count;
	}
	for(; count > 0;--count,_dest = ListItr_Prev(_dest))
	{}
	return _dest;
}

/** 
 * @brief Merges two given sub lists into destination 
 * @details Merge elements from two sub lists defined by [_firstbegin.._firstEnd)
 * and [_secondBegin.._secondEnd) in optionaly sorted order using _less function.
 * merged elements will be inserted before _destBegin
 * if a _less function is provided then merge will be sorted
 * 
 * @warning this will removes all merged items from source ranges.
 * O(n)
 *  
 */
ListItr ListItr_Merge(ListItr _destBegin, ListItr _firstBegin, ListItr _firstEnd,
			ListItr _secondBegin, ListItr _secondEnd, LessFunction _less)
			{
				ListItr nextItr;


				if(NULL == _less)
				{
					_destBegin = ListItr_Splice(_destBegin,_firstBegin,_firstEnd);
					return ListItr_Splice(_destBegin,_secondBegin,_secondEnd);
				}
				if(_firstBegin == _firstEnd)
					return ListItr_Prev(_firstBegin);
				
				if(_secondBegin == _secondEnd)
					return ListItr_Prev(_secondBegin);

				if(_less(_firstBegin,_secondBegin))
				{
					nextItr = ListItr_Next(_firstBegin);
					ListItr_Splice(_destBegin,_firstBegin,nextItr);
					nextItr = ListItr_Merge(_destBegin,nextItr,_firstEnd,_secondBegin,_secondEnd,_less);
				}
				else
				{
					nextItr = ListItr_Next(_secondBegin);
					ListItr_Splice(_destBegin,_secondBegin,nextItr);	
					nextItr = ListItr_Merge(_destBegin,_firstBegin,_firstEnd,nextItr,_secondEnd,_less);
				}
				return nextItr;

			}

/** 
 * @brief Removes a sublist [_begin.._end) from a list and creates a new list
 * with all removed items.
 * O(?)
 *
 */
List* ListItr_Cut(ListItr _begin, ListItr _end)
{
	List *lst = NULL;
	ListItr cur,next;
	void* item;

	lst = List_Create();
	next = cur = _begin;
	while (next != _end)
	{
		item = ListItr_Remove(cur);
		List_PushTail(lst,item); 
		cur = ListItr_Next(next);	
		next = ListItr_Next(next);
	}
	return lst;
}

/** 
 * @brief Removes all duplicate elements from a sorted sublist [_begin.._end) 
 * and rertun a new list with all removed items.
 * O(?)
 * post condition: [_begin.._end) contains only unique elements
 */
List* ListItr_Unique(ListItr _begin, ListItr _end, EqualsFunction _equals)
{
	List *lst = NULL;
	ListItr cur,next;
	void *item,*nxtItm;

	lst = List_Create();
	cur = _begin;
	while (cur != _end)
	{
		next = ListItr_Next(cur);
		item = ListItr_Get(cur);
		nxtItm = ListItr_Get(next);
		while(_equals(nxtItm ,item))
		{
			item = ListItr_Remove(cur);
			List_PushTail(lst,item);
			cur = next;	
			next = ListItr_Next(cur);
			item = ListItr_Get(cur);
			nxtItm = ListItr_Get(next);
		}
		cur = next;	
	}
	return lst;
}



            /**dbg print*/
int ListDoFncForAll(const List* _lst ,void* _itemPtr,ListActionFunction _fnc,void* _testItm)
{
	Node *cur;
	int nItr = 0;

	if(NULL == _lst || NULL == _itemPtr || NULL == _fnc)
		return -1; 
	cur = _lst->m_head.m_next;
	while(cur != &(_lst->m_tail))
	{	
		_itemPtr = cur->m_item;
		cur = cur->m_next;
		if(!_fnc(_itemPtr,_testItm))
			break;
		++nItr;
	}
	return nItr;
}



void List_Print(const List* _list)
{
	Node *cur;
	int i ,*itemptr ;
	i = 8;
	itemptr = &i;
	
	cur = _list->m_head.m_next;
	printf("\n(");
	while(cur != &(_list->m_tail))
	{	
		itemptr = (cur->m_item);
		printf("%d ,",*itemptr);
		cur = cur->m_next;
	}
	printf(")\n");
}


int StrPrt(void* _itm,void* _null)
{
	char* s = (char*)_itm;
	return printf(" %s ,",s);
}


void List_Prstr(const List* _list)
{
	ListItr curS,curE;
	curS = ListItr_Begin(_list);
	curE = ListItr_End(_list);

	printf("\n(");
	ListItr_ForEach(curS,curE,StrPrt,NULL);
	printf(")\n");
}

int List_Prpep(const List* _list)
{
	int num = 0;
	Person p = {123,1234,"qwer"};
	Person *itemptr;

	itemptr = &p;
	printf("\n(");
	num = ListDoFncForAll(_list,(void*)itemptr,Person_print,NULL);
	printf(")\n");
	return num;
}






