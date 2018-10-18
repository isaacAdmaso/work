#include "Pool.h"

#include <stdlib.h>

#define MAGIC 12432132
#define IS_INVALID(P) (NULL == (P) || (P)->m_magic != MAGIC)

struct Pool
{
    size_t m_bufSize;
    size_t m_magic;
    size_t m_numOfBufs;
    char** m_Buffer;
};
/**
 * @brief create "Pool" of memory get 2 parm 
 * buffer size and number of Memory
 * return Pool Ptr
 */
Pool* Pool_Create(size_t _bufSize,size_t _numOfBufs)
{
    Pool* pol;

    if(0 >= _bufSize || 0 >= _numOfBufs)
    {
        return NULL;
    }
    pol = malloc(sizeof(Pool)+_bufSize*_numOfBufs);
    if(NULL == pol)
    {
        return NULL;
    }
    pol->m_bufSize = _bufSize;
    pol->m_numOfBufs = _numOfBufs;
    pol->m_Buffer = (char**)(pol + 1);
    *(pol->m_Buffer) = NULL;
    pol->m_magic =MAGIC;
    return pol;
}

/**
 * @brief return allocated memory
 * 
 */
void Pool_Destroy(Pool* _pool)
{   
    if(IS_INVALID(_pool))
    {
        return;
    }
    free(_pool);
}
/*
static void* MyHash(Pool* _pool)
{
    char i;
    void* tmpFree = NULL;
    size_t numOfBuff = _pool->m_numOfBufs;

    for(i = 0;i < numOfBuff; ++i)
    {
        if(*(_pool->m_Buffer) == ((char*)_pool->m_Buffer+((char)(_pool->m_bufSize) * i)))
        {
            tmpFree = _pool->m_Buffer;
            _pool->m_Buffer = (char*)_pool->m_Buffer+((char)(_pool->m_bufSize) * i);
            break;
        }
    }
    return tmpFree;
}
*/
/**
 * @brief give buffer size of memory  from the Pool
 * return NULL if error else return ptr
 * 
 */
void* MyMalloc(Pool* _pool)
{
    void* rtPtr;

    if(IS_INVALID(_pool) || 0 == _pool->m_numOfBufs)
    {
        return NULL;
    }
    /*
    rtPtr = MyHash(_pool->m_Buffer);
    */
    rtPtr = (void*)(_pool->m_Buffer);
    if(NULL == *(_pool->m_Buffer))
    {
        _pool->m_Buffer = (_pool->m_Buffer) +(_pool->m_bufSize);
        *(_pool->m_Buffer) = NULL;
    }
    else
    {
        _pool->m_Buffer = (char**)(*(_pool->m_Buffer));
    }
    --(_pool->m_numOfBufs);
    return rtPtr; 
}
/**
 * @brief return bufsize to pool
 * 
 */
void MyFree(Pool* _pool,void* _rtPtr)
{
    if(_pool->m_numOfBufs == 0 || _rtPtr == NULL)
    {
        return;
    }
    *((char**)_rtPtr) = (char*)_pool->m_Buffer;
    _pool->m_Buffer = _rtPtr;
    ++(_pool->m_numOfBufs);

    /*
    if(IS_INVALID(_pool) || NULL == _rtPtr)
    {
        return;
    }
    *(char**)_rtPtr = _pool->m_Buffer; 
    _rtPtr = (_pool->m_Buffer);
    _pool->m_Buffer = tempPtr;
*/
}
