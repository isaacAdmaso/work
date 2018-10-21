#ifndef __POOL_H__
#define __POOL_H__
#include <stddef.h>
#define AVG_BUFF 8

typedef struct Pool Pool;


Pool* Pool_Create(size_t _bufSize);

void Pool_Destroy(Pool* _pool);

void* MyMalloc(Pool* _pool,size_t _size);

void MyFree(Pool* _pool,void* _allPtr);

#endif /**__POOL_H__ */