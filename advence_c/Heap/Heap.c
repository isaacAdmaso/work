#include<stdlib.h>
#include<stdio.h>
#include "Heap.h"

#define MAGIC 8952214
#define IS_INVALID(H) ((NULL == (H)) /*|| NULL == (H)->m_vec */|| (H)->m_magic != MAGIC)

struct Heap
{
	int m_magic;
	Vector *m_vec;
	size_t m_heap_size;
    LessThanComparator m_compere;
};

typedef struct pair
{
	size_t m_idx;
	void* m_val;
}pair;

static void MaxHeapify(Heap* _heap,size_t _index)
{
	pair leftC,rightC,parent,*largest;

	leftC.m_idx = 2*_index+1;
	rightC.m_idx = 2*_index+2;
	parent.m_idx = _index;
	Vector_Get(_heap->m_vec,parent.m_idx,&(parent.m_val));

	if(leftC.m_idx < _heap->m_heap_size)
	{
		Vector_Get(_heap->m_vec,leftC.m_idx,&leftC.m_val);
		if(_heap->m_compere(parent.m_val,leftC.m_val))
		{
			largest = &leftC;
		}else
		{
			largest = &parent;
		}
	}else 
	{
		largest = &parent;
	}
	if(rightC.m_idx < _heap->m_heap_size)
	{
		Vector_Get(_heap->m_vec,rightC.m_idx,&rightC.m_val);
		if(_heap->m_compere(leftC.m_val,rightC.m_val) && _heap->m_compere(parent.m_val,rightC.m_val))
		{
			largest = &rightC;
		}
	}
	if (largest != &parent)
	{
		Vector_Get(_heap->m_vec,largest->m_idx,&(largest->m_val));
		Vector_Set(_heap->m_vec,parent.m_idx,largest->m_val);
		Vector_Set(_heap->m_vec,largest->m_idx,parent.m_val);
		MaxHeapify(_heap,largest->m_idx);
	}
}

void HeapifyUp(Heap* _heap,size_t _index)
{
	pair _idxValP,parent;

	parent.m_idx = (_index - 1)/2;
	_idxValP.m_idx = _index;
	if(0 <= _index && _index < _heap->m_heap_size)
	{
		Vector_Get(_heap->m_vec,parent.m_idx,&(parent.m_val));
		Vector_Get(_heap->m_vec,_idxValP.m_idx,&(_idxValP.m_val));

		if(_heap->m_compere(parent.m_val,_idxValP.m_val))
		{
			Vector_Set(_heap->m_vec,parent.m_idx,_idxValP.m_val);
			Vector_Set(_heap->m_vec,_idxValP.m_idx,parent.m_val);
			HeapifyUp(_heap,parent.m_idx);
		}
	} 
}		
/**  
 * @brief Apply a heap policy over a Vector container.  
 * @param[in] _vector - Vector that holds the elements, must be initialized
 * @return Heap * - on success
 * @retval NULL on fail 
 *
 * @warning allocating and freeing the underlying vector is user responsibility. 
 * as long as vector is under the heap control, user should not access the vector directly
 */	 		
Heap* Heap_Build(Vector* _vector,LessThanComparator _pfLess)
{
	int i;
	Heap* heap = NULL;

	if(NULL == _vector || NULL == _pfLess)
	{
		return NULL;
	}
	heap = (Heap*)malloc(sizeof(Heap));
	heap->m_vec = _vector;
	heap->m_heap_size = Vector_Size(_vector);
	heap->m_compere = _pfLess;
	for(i = (heap->m_heap_size -1)/2; i >= 0; --i)
	{	
		MaxHeapify(heap,i);
	}
	heap->m_magic = MAGIC;
	return heap;
}
/**  
 * @brief Deallocate a previously allocated heap
 * Frees the heap but not the underlying vector  
 * @param[in] _heap - Heap to be deallocated.  On success will be nulled.
 * @return Underlying vector
 */
Vector* Heap_Destroy(Heap** _heap)
{
	Vector* vec = NULL;
	
	if(_heap == NULL)
	{
		return NULL;
	}
	if(!IS_INVALID(*_heap))
	{
		(*_heap)->m_magic = -1;
		vec = (*_heap)->m_vec;
		free(*_heap);
	}
	return vec;
}

/**  
 * @brief Add an element to the Heap preserving heap property.  
 * @param[in] _heap - Heap to insert element to.
 * @param[in] _element - Element to insert. can't be null
 * @return success or error code 
 * @retval HEAP_OK  on success
 * @retval HEAP_NOT_INITIALIZED  error, heap not initilized
 * @retval HEAP_REALLOCATION_FAILED error, heap could not reallocate underlying vector 
 */
Heap_Result Heap_Insert(Heap* _heap, void* _element)
{
	size_t itemNum;
	Vector_Result error = VECTOR_SUCCESS;

	if(IS_INVALID(_heap))
	{
		return HEAP_NOT_INITIALIZED;
	}
	error = Vector_Append(_heap->m_vec,_element);
	if(error != VECTOR_SUCCESS)
	{
		return HEAP_REALLOCATION_FAILED;
	}
	itemNum = Vector_Size(_heap->m_vec);
	HeapifyUp(_heap,itemNum-1);
	++(_heap->m_heap_size);
	return HEAP_SUCCESS;
	
}
	
/**  
 * @brief Peek at element on top of heap without extracting it.  
 * @param[in] _heap - Heap to peek at.
 * @return pointer to element, can be null if heap is empty or on error
 */
const void* Heap_Peek(const Heap* _heap)
{
	void* element = NULL;

	if(IS_INVALID(_heap))
	{
		return NULL;
	}
	if(_heap->m_heap_size == 0)
	{
		return NULL;
	}
	Vector_Get(_heap->m_vec,0,&element);
	return element;
}
	
/**  
 * @brief Extract element on top of heap and remove it.  
 * @param[in] _heap - Heap to extract from.
 * @return pointer to element, can be null if heap is empty. 
 */
void* Heap_Extract(Heap* _heap)
{
	int i;
	void *temp_last ,*test,*element;

	if(IS_INVALID(_heap))
	{
		return NULL;
	}
	if(_heap->m_heap_size == 0)
	{
		return NULL;
	}
	Vector_Get(_heap->m_vec,_heap->m_heap_size-1,&temp_last);
	Vector_Get(_heap->m_vec,0,&element);
	Vector_Set(_heap->m_vec,0,temp_last);
	Vector_Remove(_heap->m_vec,&test);
	--(_heap->m_heap_size);
	for(i = _heap->m_heap_size/2; i >= 0; --i)
	{	
		MaxHeapify(_heap,i);
	}
	return element;
}

/**  
 * @brief Get the current size (number of elements) in the heap.  
 * @param[in] _heap - the Heap.
 * @return number of elements or zero if empty. 
 */
size_t Heap_Size(const Heap* _heap)
{
	if(IS_INVALID(_heap))
	{
		return -1;
	}
	return _heap->m_heap_size;
} 

/**  
 * @brief Iterate over all elements  in the heap from top to bottom.
 * @details The user provided ActionFunction _act will be called for each element. 
 * iteration will stop at the first element wehere _act(e) returns zero
 * @param[in] _heap - Heap to iterate over.
 * @param[in] _act - User provided function pointer to be invoked for each element
 * @returns number of times the user functions was invoked
 */
size_t Heap_ForEach(const Heap* _heap,ActionFunction _act, void* _context)
{
	if(IS_INVALID(_heap) || NULL == _act)
	{
		return 0;
	}
	return Vector_ForEach(_heap->m_vec, _act, _context);
}
/**  
 * @brief Sort a given vector of elments using a heap sort.
 * @param[in] _vector - vector to sort.
 * @param[in] _pfLess
 */
/*
void Heap_Sort(Vector* _vec, LessThanComparator _pfLess)

void HeapPrint(const Heap* _heap)
{
	if(IS_INVALID(_heap))
	{
		return ;
	}
	VectorPrint(_heap->m_vec);
}
int main(){
	int  i;
	int arr[]={1,2,3,4,5,36,77,81,29,120};
	Vector *v=VectorCreate(2,2);
	Heap *h;
	for (i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
	{
		VectorAdd(v,arr[i]);
	}
	h = HeapBuild(v);
	HeapPrint(h);
	return 0;
}
*/
























