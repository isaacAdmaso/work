#include "pool2.h"

#include <stdlib.h>

#define DLT  sizeof(void*)
#define MAGIC 12432132
#define IS_INVALID(P) (NULL == (P) || (P)->m_magic != MAGIC)

typedef struct Inode
{
    void* m_Real_prev;
    size_t m_size;
    void* m_iBuffer;
    struct Inode *m_next;
    struct Inode *m_prev;
}Inode;

struct Pool
{
    size_t m_magic;
    size_t m_totBufleft;/**check if needded.. */
    Inode* m_buffer;
};


static void Inode_Init(Pool* _pool,size_t _bufSize)
{
    _pool->m_buffer->m_Real_prev = NULL;
    _pool->m_buffer->m_size = _bufSize;
    _pool->m_buffer->m_next = _pool->m_buffer->m_next = NULL;
}

static void  Pool_Init(Pool* _pool,size_t _size)
{
    _pool->m_totBufleft = AVG_BUFF;
    _pool->m_magic = MAGIC;
    _pool->m_buffer = (_pool+1);
    Inode_Init(_pool,_size);
}
/**
 * @brief create "Pool" of memory get 2 parm 
 * buffer size and number of Memory
 * return Pool Ptr
 */
Pool* Pool_Create(size_t _bufSize)
{
    Pool* pol;
    size_t size;

    if(0 >= _bufSize)
    {
        return NULL;
    }
    size = sizeof(Pool)+_bufSize*sizeof(char)+sizeof(Inode) +AVG_BUFF*sizeof(size_t);
    pol = malloc(size);
    if(NULL == pol)
    {
        return NULL;
    }
    size -= (sizeof(Pool) + sizeof(Inode));
    Pool_Init(pol,size);
    
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
    _pool->m_magic = 0;
    free(_pool);
}

static Inode* Split(Inode *_node,size_t _size)
{
    Inode* newNode = (Inode*)(_node->m_iBuffer + _size);

    newNode->m_size = _node->m_size -(_size + sizeof(Inode));
    _node->m_size = _size;
    newNode->m_iBuffer = (char**)(newNode + 1);
    newNode->m_next = _node->m_next;
    newNode->m_prev = _node->m_prev;
    return newNode;
}

static void* FindFirstFree(Pool* _pool,size_t _size)
{
    Inode *cur = &(_pool->m_buffer) ;
    
    while ((cur->m_next != NULL) && (cur->m_size >= _size))
    {
        cur = cur->m_next;
    }
    if ((cur->m_size >= _size) && (cur->m_size <= _size + sizeof(Inode) + DLT))
    {
        if(cur->m_next != NULL)
        {
            cur->m_next->m_prev = cur->m_prev;
            cur->m_prev->m_next = cur->m_next;
        }
        _pool->m_totBufleft -=_size;
        return (void*)cur->m_iBuffer;

    }
    else if(cur->m_size > _size + sizeof(Inode) + DLT)
    {
        cur = Split(cur , _size);
        _pool->m_totBufleft -=(_size + sizeof(Inode));
        return (void*)cur->m_iBuffer;
    }
    return NULL;
}
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
    void* newNode;

    if(IS_INVALID(_pool) || 0 == _size)
    {
        return NULL;
    }
    
    newNode = FindFirstFree(_pool,_size);

    return newNode; 
}
/**
 * @brief return bufsize to pool
 * 
void MyFree(Pool* _pool,void* _rtPtr)
{
    Inode* cur = _rtPtr;

    --cur;
    if( IS_INVALID(_pool) || _rtPtr == NULL)
    {
        return;
    }
    cur->m_next =  _pool->m_buffer.m_next;
    _pool->m_buffer.m_next = cur;
    cur->m_prev = &_pool->m_buffer;
}
 */
