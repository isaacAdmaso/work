#include "Vector.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define MAGIC 192837465
#define IS_INVALID(v) ((NULL == (v)) || (v)->m_magic != MAGIC)


struct Vector
{
	size_t	  m_magic;		    /**< Protector*/
    void**    m_items;          /**< The items  */	
    size_t    m_originalSize;   /**< original allocated space for items */
    size_t    m_allocatedSize;  /**< actual allocated space for items	*/
    size_t    m_nItems; 	      /**< actual number of items */
    size_t    m_blockSize;	  /**< the chunk size to be allocated when no space*/
};
/**  
 * @brief Dynamically create a new vector object of given capacity and  
 * @param[in] _initialCapacity - initial capacity, number of elements that can be stored initially
 * @param[in] _blockSize - the vector will grow or shrink on demand by this size 
 * @return Vector * - on success / NULL on fail 
 */
Vector* Vector_Create(size_t _initialCapacity, size_t _blockSize)
{	
	Vector* newVector = NULL;
	
	if(_initialCapacity == 0 )
	{
		return NULL;
	}
	newVector = malloc(sizeof(Vector));
	if (NULL == newVector) 
	{
		return NULL;
	}
	newVector ->m_items = (void**)malloc(_initialCapacity*sizeof(void*));
	if (NULL == newVector->m_items)
	{
		free(newVector);
		return NULL;
	}

	newVector->m_allocatedSize = _initialCapacity;
	newVector->m_originalSize = _initialCapacity;
	newVector->m_blockSize = _blockSize;
	newVector->m_nItems = 0;
	newVector->m_magic = MAGIC;

	return newVector;
}

static Vector_Result Vector_Resize(Vector *_vector, int _resize)
{
    void** reAllocItems = NULL;
	
	if(_vector->m_blockSize == 0)
	{
		return VECTOR_OVERFLOW;
	}
	reAllocItems = realloc(_vector->m_items,(_resize)*sizeof(void*));

	if(reAllocItems==NULL)
	{
		return VECTOR_REALLOCATION_FAILED;
	}
	_vector->m_items = reAllocItems;
	_vector->m_allocatedSize = _resize ;
	return VECTOR_SUCCESS;
}
/**  
 * @brief Add an Item to the back of the Vector.  
 * @param[in] _vector - Vector to append integer to.
 * @param[in] _item - Item to add.
 * @return success or error code 
 * @retval VECTOR_SUCCESS on success 
 * @retval VECTOR_UNINITIALIZED_ERROR if not initialized
 * @retval VECTOR_OVERFLOW if blocksize == 0
 * @retval VECTOR_REALLOCATION_FAILED for memory problem
 */

Vector_Result Vector_Append(Vector* _vector, void* _item)
{
    Vector_Result error = VECTOR_SUCCESS;
	int resize = 0;
    if(IS_INVALID(_vector) || NULL == _item)
    {
        return VECTOR_UNINITIALIZED_ERROR;
    }

	if(_vector->m_nItems==_vector->m_allocatedSize)
	{
		resize = _vector->m_allocatedSize + _vector->m_blockSize;
		error = Vector_Resize(_vector,resize);
		if(error != VECTOR_SUCCESS)
			return error;
	}
	_vector->m_items[_vector->m_nItems++] = _item;
	return VECTOR_SUCCESS;
}
/**  
 * @brief Get the number of actual items currently in the vector.
 * @param[in] _vector - Vector to use.
 * @return  number of items on success 0 if vector is empty or invalid			
 */
size_t Vector_Size(const Vector* _vector)
{
	if(IS_INVALID(_vector)) 
	{
		return 0;
	}
	return _vector->m_nItems;
}
/**  
 * @brief Get the current capacity of the  vector.
 * @param[in] _vector - Vector to use.
 * @return  capacity of vector			
 */
size_t Vector_Capacity(const Vector* _vector)
{
    if(IS_INVALID(_vector)) 
	{
		return 0;
	}
	return _vector->m_allocatedSize;
}

/**  
 * @brief Dynamically deallocate a previously allocated vector  
 * @param[in] _vector - Vector to be deallocated.
 * @params[in] _elementDestroy : A function pointer to be used to destroy all elements in the vector
 *             or a null if no such destroy is required
 * @return void
 */
void Vector_Destroy(Vector** _vector, void (*_elementDestroy)(void* _item))
{
    int i;
	if(NULL != _vector)
	{
		if(IS_INVALID(*_vector))
		{
			return;
		}
		(*_vector)->m_magic = 0;
        for(i = 0; i < (*_vector)->m_nItems;++i)
        {
            _elementDestroy((*_vector)->m_items[i]);
        }
	 	free((*_vector)->m_items);
		free(*_vector);	
	}
}

/**  
 * @brief Delete an Element from the back of the Vector.  
 * @param[in] _vector - Vector to delete integer from.
 * @param[out] _pValue - pointer to variable that will receive deleted item value
 * @return success or error code 
 * @retval VECTOR_SUCCESS on success 
 * @retval VECTOR_UNINITIALIZED_ERROR if vector or _pValue is NULL 
 * @retval VECTOR_UNDERFLOW if vector is empty
 * @warning _item can't be null. this will be assertion violation
 */
Vector_Result Vector_Remove(Vector* _vector, void** _pValue)
{
	
    if(IS_INVALID(_vector) || NULL == _pValue)
    {
        return VECTOR_UNINITIALIZED_ERROR;
    }
    if(0 == _vector->m_nItems)
    {
        return VECTOR_UNDERFLOW;
    }
    *_pValue = _vector->m_items[--(_vector->m_nItems)];
    assert(NULL != *_pValue);
    if(_vector->m_allocatedSize > _vector->m_originalSize)
	{
		if(_vector->m_allocatedSize >= (_vector->m_nItems + 2*_vector->m_blockSize))
		{
			_vector->m_items=(void**)realloc((void*)_vector->m_items,(_vector->m_allocatedSize - _vector->m_blockSize)*sizeof(void*));
            _vector->m_allocatedSize -= _vector->m_blockSize;
		}
	}
	return VECTOR_SUCCESS;
}

/**  
 * @brief Get value of item at specific index from the the Vector 
 * @param[in] _vector - Vector to use.
 * @param[in] _index - index of item to get value from. the index of first elemnt is 1
 * @param[out] _pValue - pointer to variable that will recieve the item's value.
 * @return success or error code 
 * @retval VECTOR_SUCCESS on success 
 * @retval VECTOR_UNINITIALIZED_ERROR if vector or _pValue is NULL 
 * @retval VECTOR_INDEX_OUT_OF_BOUNDS_ERROR for wrong _index
 * @retval VECTOR_UNDERFLOW  if vector is empty
 */
Vector_Result Vector_Get(const Vector* _vector, size_t _index, void** _pValue)
{
    if(IS_INVALID(_vector) || NULL == _pValue) 
	{
		return VECTOR_UNINITIALIZED_ERROR;
	}
	if(_index >= _vector->m_nItems)
	{
		return VECTOR_INDEX_OUT_OF_BOUNDS_ERROR;
	}
	if(_vector->m_nItems == 0)
	{
		return VECTOR_UNDERFLOW;
	}
	*_pValue = _vector->m_items[_index];
    assert(NULL != *_pValue);
	return VECTOR_SUCCESS;
}
/**  
 * @brief Set an item at specific index to a new value.
 * @param[in] _vector - Vector to use.
 * @param[in] _index - index  of an existing item.
 * @param[in] _value - new value to set.
 * @return success or error code 
 * @retval VECTOR_SUCCESS on success 
 * @retval VECTOR_UNINITIALIZED_ERROR if vector or _pValue is NULL 
 * @retval VECTOR_INDEX_OUT_OF_BOUNDS_ERROR for wrong _index
 * @retval VECTOR_UNDERFLOW  if vector is empty */
Vector_Result Vector_Set(Vector* _vector, size_t _index, void*  _value)
{
    if(IS_INVALID(_vector) || NULL == _value)
	{
		return VECTOR_UNINITIALIZED_ERROR;
	}
	if(_index >= _vector->m_nItems)
	{
		return VECTOR_UNDERFLOW;
	}
	_vector->m_items[_index]=_value;

	return VECTOR_SUCCESS;
}

/**  
 * @brief Iterate over all elements in the vector.
 * @details The user provided _action function will be called for each element
 *          if _action return a zero for an element the iteration will stop.  
 * @param[in] _vector - vector to iterate over.
 * @param[in] _action - User provided function pointer to be invoked for each element
 * @param[in] _context - User provided context, will be sent to _action
 * @returns number of times the user functions was invoked
 * equevallent to:
 *      for(i = 1; i < Vector_Size(v); ++i){
 *             Vector_Get(v, i, &elem);
 *             if(_action(elem, i, _context) == 0)
 *					break;	
 *      }
 *		return i;
 */
size_t Vector_ForEach(const Vector* _vector, VectorElementAction _action, void* _context)
{
    void *elem = malloc(sizeof(void*));
    size_t i;

    if(IS_INVALID(_vector) || NULL == _context || NULL == elem)
    {
        return 0;
    }
    assert(NULL != _action);
    for(i = 0;i < _vector->m_nItems;++i)
    {
        Vector_Get(_vector,i,&elem);
        if(_action(elem,i,_context) == 0)
            break;
    }
    free(elem);
    return i;
}



void Vector_Print(const Vector* _vec)
{
	int i ,*itemptr ;
	printf("\n");
	for(i = 0;i < _vec->m_nItems;++i)
	{
		itemptr = (_vec->m_items[i]);
		printf("%d ,",*itemptr);
	}
	printf("\n");
}
/*
void Vector_Prstr(const Vector* _vec)
{
	int i;
	char* itemPtr ;
	printf("\n");
	for(i = 0;i < _vec->m_nItems;++i)
	{
		itemPtr = (char*)(_vec->m_items[i]);
		printf("%s ,",itemPtr);
	}
	printf("\n");
}

*/


	
