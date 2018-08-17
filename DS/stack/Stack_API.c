#ifndef __STACK_H__
#define __STACK_H__
#include "ADTDefs.h"
#include "vector.h"
#include<stddef.h>


struct Stack
{
    Vector *m_vector;
};

Stack*  StackCreate( size_t _size, size_t _blockSize);
void    StackDestroy(Stack* _stack);
ADTErr  StackPush(   Stack* _stack, int  _item);
ADTErr  StackPop(    Stack* _stack, int* _item);
ADTErr  StackTop(    Stack* _stack, int* _item);
int     StackIsEmpty(Stack* _stack);

/*  Unit-Test functions  */
void    StackPrint(  Stack *_stack);


#endif
