#include "ADTDefs.h"
#include "vector.h"
#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>
struct Vector
{
    int*    m_items;          /**< The items */	
    size_t  m_originalSize;   /**< original allocated space for items */
    size_t  m_allocatedSize;  /**< actual allocated space for items	*/
    size_t  m_nItems; 	      /**< actual number of items */
    size_t  m_blockSize;	  /**< the chunk size to be allocated when no space*/
};

Vector* VectorCreate(size_t _initialSize, size_t _extensionBblockSize)
{	
	if(_initialSize ==0 && _extensionBblockSize==0)
	{
		return NULL;
	}
	Vector* newVector = 0;
	newVector = (Vector*)malloc(sizeof(Vector));
	if (newVector == NULL) 
	{
		return NULL;
	}
	newVector ->m_items = (int*)malloc(_initialSize*sizeof(int));
	if (newVector ->m_items == NULL)
	{
		free(newVector);
		return NULL;
	}

	newVector ->m_allocatedSize = _initialSize;
	newVector ->m_originalSize = _initialSize;
	newVector ->m_blockSize=_extensionBblockSize;
	newVector ->m_nItems=0;
	return newVector;
}
	
void  VectorDestroy(Vector* _vector)
{
	if(_vector!=NULL)
	{
	 	free(_vector->m_items);
		free(_vector);	
	}
}	 

ADTErr  VectorGet(const Vector* _vector, size_t _index, int *_item)
{
	if(_vector == NULL ) 
	{
		return ERR_NOT_INITIALIZED;
	}
	if(_index > _vector->m_nItems)
	{
		return ERR_WRONG_INDEX;
	}
	*_item = _vector->m_items[_index];
	return ERR_OK;
		
}	

ADTErr  VectorSet(Vector *_vector, size_t _index, int  _item)
{
	if(_vector == NULL )
	{
		return ERR_NOT_INITIALIZED;
	}
	if(_index<0 || _index > _vector->m_nItems)
	{
		return ERR_WRONG_INDEX;
	}
	 _vector->m_items[_index]=_item;
}

ADTErr  VectorItemsNum(const Vector *_vector, size_t* _numOfItems)
{
	if(_vector == NULL || _numOfItems == NULL ) 
	{
		return ERR_NOT_INITIALIZED;
	}
	*_numOfItems = _vector->m_nItems;
}

void    VectorPrint(const Vector *_vector)
{	
	int i;
	if(_vector == NULL ) 
	{
		return ;
	}
	for (i=0;i<_vector->m_nItems;++i)
	{
		printf("%d, ",_vector->m_items[i]);
	}
}


	
ADTErr  VectorAdd(Vector *_vector,  int  _item)
{	
	int* reAllocItems= NULL;
	if(_vector == NULL) 
	{
		return ERR_NOT_INITIALIZED;
	}
	if(_vector->m_nItems==_vector->m_allocatedSize)
	{
		if(_vector->m_blockSize == 0)
		{
			return ERR_OVERFLOW;
		}
		reAllocItems = (int*)realloc(_vector->m_items,(_vector->m_allocatedSize + _vector->m_blockSize)*sizeof(int));
	
		if(reAllocItems==NULL)
		{
			return ERR_REALLOCATION_FAILED;
		}
		_vector->m_items=reAllocItems;
		_vector->m_allocatedSize+=_vector->m_blockSize;
		
	}
	_vector->m_items[_vector->m_nItems++]=_item;
	return ERR_OK;
}

ADTErr  VectorDelete(Vector *_vector,  int* _item)
{	
	if(_vector == NULL ) 
	{
		return ERR_NOT_INITIALIZED;
	}
	if(_vector->m_nItems == 0)
	{
		return ERR_UNDERFLOW;
	}
	*_item=_vector->m_items[--_vector->m_nItems];
	
	if(_vector->m_allocatedSize > _vector->m_originalSize)
	{
		if(_vector->m_allocatedSize == (_vector->m_nItems + 2*_vector->m_blockSize))
		{
			_vector->m_items=(Vector *)realloc(_vector->m_items,(_vector->m_allocatedSize - _vector->m_blockSize)*sizeof(int));
		}
	}
	return ERR_OK;
}


	
	
	
	
	
	
	
