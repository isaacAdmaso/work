#ifndef __STACK_H__
#define __STACK_H__
#include "vector.h"
#include "ADTDefs.h"
#include<stddef.h>

typedef struct Stack Stack;

Stack*  StackCreate( size_t _size, size_t _blockSize);
void    StackDestroy(Stack* _stack);
ADTErr  StackPush(   Stack* _stack, int  _item);  /* Add item to end. */
ADTErr  StackPop(    Stack* _stack, int* _item);/* Remove from end. */
ADTErr  StackTop(    Stack* _stack, int* _item);/* Return value from end. */
int     StackIsEmpty(Stack* _stack);

/*  Unit-Test functions  */
void    StackPrint(  Stack *_stack);

#endif
