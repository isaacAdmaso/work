#ifndef __POOL_H__
#define __POOL_H__
#include <stddef.h>

typedef struct Pool Pool;


Pool* Pool_Create(size_t _bufSize,size_t _numOfBufs);

void Pool_Destroy(Pool* _pool);

void* MyMalloc(Pool* _pool);

void MyFree(Pool* _pool,void* _allPtr);

#endif /**__POOL_H__ */