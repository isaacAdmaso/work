#include "pool2.h"

#include <stdlib.h>
#include <string.h>

#define MAGIC 12432132
#define IMAGIC (void*)0xDEADBEEF
#define IS_INVALID(P) (NULL == (P) || (P)->m_magic != MAGIC)

typedef struct Inode
{
    void* m_magic;
    int m_size;
    char** m_iBuffer;
    char** m_next;
}Inode;

struct Pool
{
    size_t m_magic;
    size_t m_totBufleft;/**check if needded.. */
    Inode m_buffer;
};
/**
 * @brief create "Pool" of memory get 2 parm 
 * buffer size and number of Memory
 * return Pool Ptr
 */
Pool* Pool_Create(size_t _bufSize)
{
    Pool* pol;

    if(0 >= _bufSize)
    {
        return NULL;
    }
    pol = malloc(sizeof(Pool)+_bufSize*sizeof(char));
    if(NULL == pol)
    {
        return NULL;
    }
    pol->m_totBufleft = _bufSize;
    pol->m_buffer.m_iBuffer = (char**)(pol + 1);
    pol->m_buffer.m_next = NULL;
    pol->m_buffer.m_size = _bufSize;
    pol->m_buffer.m_magic = IMAGIC;
    pol->m_magic = MAGIC;
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
    return tmpFreInodee;
}
static void* Div_Mem(Pool _pool,size_t _size)
{
    Inode newF;

    _pool->m_buffer.


}
*/
/**
 * @brief give buffer size of memory  from the Pool
 * return NULL if error else return ptr
 * void* m_magic;
    int m_size;
    char** m_iBuffer;
    char** m_next;
 */
void* MyMalloc(Pool* _pool,size_t _size)
{
    void* rtPtr;
    Inode newNode;

    if(IS_INVALID(_pool) || 0 == _pool->m_totBufleft)
    {
        return NULL;
    }
    /*
    rtPtr = MyHash(_pool->m_Buffer);
    */
    rtPtr = (void*)(_pool->m_buffer.m_iBuffer);
    if(NULL == _pool->m_buffer.m_next && _size < _pool->m_totBufleft)
    {
        _pool->m_buffer.m_size = _size;
        newNode.m_size = _pool->m_totBufleft - _size;
        if(0 >= newNode.m_size)
        {
            return NULL;
        }
        _pool->m_totBufleft -= (_size +sizeof(Inode)); 
        newNode.m_iBuffer =(_pool->m_buffer.m_iBuffer + _size + sizeof(Inode)); 
        newNode.m_next = NULL;
        memset((void*)((_pool->m_buffer.m_iBuffer) + _size),newNode,sizeof(Inode));
    }
    else
    {
        while()
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
