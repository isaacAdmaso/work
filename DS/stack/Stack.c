#include "Stack.h"
#include "vector.h"
#include<stdlib.h>
#include<stdio.h>

#define MAGIC 25693478962

/*


  Unit-Test functions  
*/
struct Stack
{
	size_t	m_magic;	/**< Protector*/
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
	newStack->m_magic = MAGIC;
	return newStack;
}
void StackDestroy(Stack* _stack)
{	
	if(_stack != NULL && _stack->m_magic == MAGIC)
	{
		VectorDestroy(_stack->m_vector);
		free(_stack);
	}
}
	
ADTErr  StackPush(   Stack* _stack, int  _item)
{
	if(_stack == NULL ||_stack->m_magic != MAGIC)
	{
		return	ERR_NOT_INITIALIZED;
	}
	return VectorAdd(_stack->m_vector,_item);
}

ADTErr  StackPop(    Stack* _stack, int* _item)
{
	if(_stack == NULL||_stack->m_magic != MAGIC || _item == NULL)
	{
		return	ERR_NOT_INITIALIZED;
	}
	return VectorDelete(_stack->m_vector,_item);
}
	
ADTErr  StackTop(    Stack* _stack, int* _item)
{	
	size_t _numOfItems;
	ADTErr eRR;
 ;
	if(_stack == NULL ||_stack->m_magic != MAGIC || _item == NULL)
	{
		return	ERR_NOT_INITIALIZED;
	}
		VectorItemsNum(_stack->m_vector,&_numOfItems);
		eRR=VectorGet(_stack->m_vector,_numOfItems-1,_item);
		return eRR;
}

int StackIsEmpty(Stack* _stack)
{
	size_t _numOfItems;	
	if(_stack == NULL||_stack->m_magic != MAGIC)
	{
		return	0;
	}
	VectorItemsNum(_stack->m_vector,&_numOfItems);
	if(_numOfItems == 0)
	{	
		return 0;
	}else
	{
	return 1;
	}
}	
void   StackPrint(  Stack *_stack)
{
	if(_stack == NULL ||_stack->m_magic != MAGIC)
	{
		return;
	}
	VectorPrint(_stack->m_vector);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
