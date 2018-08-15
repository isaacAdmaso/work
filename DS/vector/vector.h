#ifndef VECTOR_H
#define VECTOR_H
#include<stddef.h>
#include "ADTDefs.h"
typedef struct Vector Vector;

Vector* VectorCreate(size_t _initialSize, size_t _extensionBblockSize);
void    VectorDestroy(Vector* _vector);
 
ADTErr  VectorAdd(Vector *_vector,  int  _item); /* Add item to end. */
ADTErr  VectorDelete(Vector *_vector,  int* _item); /* Remove from end. */

ADTErr  VectorGet(const Vector *_vector, size_t _index, int *_item);
ADTErr  VectorSet(Vector *_vector, size_t _index, int  _item);
ADTErr  VectorItemsNum(const Vector *_vector, size_t* _numOfItems);

/*  Unit-Test functions  */
void    VectorPrint(const Vector *_vector);
#endif
