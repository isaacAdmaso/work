#include "Stack_API.h"
#include "vector.h"
#include<stdlib.h>
#include<stdio.h>



/*


  Unit-Test functions  
*/
struct Stack
{
	//size_t	m_magic;	/**< Protector*/
    Vector *m_vector;   /**< The ADT */
};

Stack*  StackCreate( size_t _size, size_t _blockSize)
{
	Stack* newStack = NULL;
	newStack = (Stack*)malloc(sizeof(Stack));
	if (newStack == NULL)
	{
		return NULL;
	}
	newStack ->m_vector = VectorCreate(_size,_blockSize);
	if (newStack ->m_vector == NULL)
	{
		free(newStack);
		return NULL;
	}
	return newStack;
}
void StackDestroy(Stack* _stack)
{	
	if(_stack != NULL )
	{
		VectorDestroy(_stack->m_vector);
		free(_stack);
	}
}
	
ADTErr  StackPush(   Stack* _stack, int  _item)
{
	if(_stack == NULL)
	{
		return	ERR_NOT_INITIALIZED;
	}
	return VectorAdd(_stack->m_vector,_item);
}

ADTErr  StackPop(    Stack* _stack, int* _item)
{
	if(_stack == NULL || _item == NULL)
	{
		return	ERR_NOT_INITIALIZED;
	}
	return VectorDelete(_stack->m_vector,_item);
}
	
ADTErr  StackTop(    Stack* _stack, int* _item)
{	
	int FlagLikeMagic;
	if(_stack == NULL || _item == NULL)
	{
		return	ERR_NOT_INITIALIZED;
	}
		FlagLikeMagic=StackPop(_stack,_item);
		StackPush(_stack,*_item);
		return FlagLikeMagic;
}

/*		
		size_t _numOfItems;
		VectorItemsNum(_stack->m_vector,&_numOfItems);
		VectorGet(_stack->m_vector,_numOfItems-1,_item);
*/
int StackIsEmpty(Stack* _stack)
{
	if(_stack == NULL)
	{
		return	ERR_NOT_INITIALIZED;
	}

	size_t _numOfItems;	
	VectorItemsNum(_stack->m_vector,&_numOfItems);	
	return (_numOfItems == 0);
}	
void   StackPrint(  Stack *_stack)
{
	if(_stack == NULL)
	{
		return;
	}
	VectorPrint(_stack->m_vector);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
