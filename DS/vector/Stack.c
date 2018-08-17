#include "Stack_API.h"
#include<stdlib.h>
#include<stdio.h>


/*
Stack*  StackCreate( size_t _size, size_t _blockSize);
void    StackDestroy(Stack* _stack);
ADTErr  StackPush(   Stack* _stack, int  _item);
ADTErr  StackPop(    Stack* _stack, int* _item);
ADTErr  StackTop(    Stack* _stack, int* _item);
int     StackIsEmpty(Stack* _stack);

  Unit-Test functions  
void    StackPrint(  Stack *_stack);
*/
struct 
{
    Vector *m_vector;
}Stack;

Stack*  StackCreate( size_t _size, size_t _blockSize)
{
	Stack* newStack = NULL;
	newStack = (Stack*)malloc(sizeof(Stack));
	if (newStrack == NULL)
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
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
