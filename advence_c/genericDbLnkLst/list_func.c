#include "list_functions.h"

				/**********************************
				 * list func using iterFunc only***
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
	if(NULL ==_begin || NULL == _end || NULL == _predicate || NULL == _context)
		return NULL;
	for(;_begin != _end ;_begin = ListItr_Next(_begin))
	{
		if(_predicate(ListItr_Get(_begin) ,_context))
		{
			break;
		}
	}
	return _begin;
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
	for(cur = _begin;cur != _end || _predicate(ListItr_Get(cur) ,_context);cur = ListItr_Next(cur)\
	, ++count)
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
		
	if(NULL == _begin || NULL == _end || NULL == _less)
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
	if(!(NULL == _dest || NULL == _begin || NULL == _end))
	{
		while(_begin != _end)
		{
			if(_begin == _dest)
			{
				_begin = ListItr_Next(_begin);
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
	}
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
				ListItr nextItr,rtItr;

				if(NULL == _destBegin ||NULL == _firstBegin ||NULL == _firstEnd \
				||NULL == _secondBegin ||NULL == _secondEnd)
					return NULL;
				if(NULL == _less)
				{
					_destBegin = ListItr_Splice(_destBegin,_secondBegin,_secondEnd);
					return ListItr_Splice(_destBegin,_firstBegin,_firstEnd);
				}
				if(_firstBegin == _firstEnd )
					return ListItr_Splice(_destBegin,_secondBegin,_secondEnd);
				
				
				if(_secondBegin == _secondEnd)
					return ListItr_Splice(_destBegin,_firstBegin,_firstEnd);

		
				if(_less(ListItr_Get(_firstBegin),ListItr_Get(_secondBegin)))
				{
					nextItr = ListItr_Next(_firstBegin);
					rtItr = ListItr_InsertBefore(_destBegin, ListItr_Remove(_firstBegin));
					nextItr = ListItr_Merge(_destBegin,nextItr,_firstEnd,_secondBegin,_secondEnd,_less);
				}
				else
				{
					nextItr = ListItr_Next(_secondBegin);
					rtItr = ListItr_InsertBefore(_destBegin, ListItr_Remove(_secondBegin));
					nextItr = ListItr_Merge(_destBegin,_firstBegin,_firstEnd,nextItr,_secondEnd,_less);
				}
				return rtItr;

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
	cur = _begin;
	while (cur != _end)
	{
		next = ListItr_Next(cur);
		item = ListItr_Remove(cur);
		List_PushTail(lst,item); 
		cur = next;	
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
	if(NULL == lst || _begin == _end)
		return NULL;
	cur = _begin;
	next = ListItr_Next(cur);
	while (next != _end)
	{
		item = ListItr_Get(cur);
		nxtItm = ListItr_Get(next);
		while(_equals(nxtItm ,item))
		{
			item = ListItr_Remove(cur);
			List_PushTail(lst,item);
			cur = next;	
			next = ListItr_Next(next);
			if(next == _end )
				return lst;
			item = ListItr_Get(cur);
			nxtItm = ListItr_Get(next);
		}
		cur = next;	
		next  = ListItr_Next(next);
	}
	return lst;
}
