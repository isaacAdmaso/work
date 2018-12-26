#include "pool2.h"

#include <stdlib.h>

#define DLT  3*sizeof(void*)
#define MAGIC 12432132
#define IS_INVALID(P) (NULL == (P) || (P)->m_magic != MAGIC)

typedef struct Inode
{
    struct Inode* m_Real_prev;
    size_t m_size;
    void* m_iBuffer;
    struct Inode* m_prev;
    struct Inode* m_next;

}Inode;

struct Pool
{
    size_t m_magic;
    /*check if needded.. */
    size_t m_totBufleft;
    Inode* m_buffer;
};


static void Inode_Init(Pool* _pool,size_t _bufSize)
{
    _pool->m_buffer->m_Real_prev = NULL;
    _pool->m_buffer->m_size = _bufSize; 
    _pool->m_buffer->m_iBuffer = _pool->m_buffer->m_iBuffer;
    _pool->m_buffer->m_next = _pool->m_buffer->m_prev = NULL; 

    /*(_pool->m_buffer + 3*sizeof(void*))*/
}

static void  Pool_Init(Pool* _pool,size_t _size)
{
    _pool->m_totBufleft = AVG_BUFF;
    _pool->m_buffer = (Inode*)(_pool+1);
    Inode_Init(_pool,_size);
    _pool->m_magic = MAGIC;
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
    size = sizeof(Pool) + _bufSize + (1 + AVG_BUFF)*sizeof(Inode);
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

static void Split(Inode *_node,size_t _size)
{
    Inode* newNode = (Inode*)((char**)_node->m_iBuffer + _size);

    newNode->m_size = _node->m_size -(_size + sizeof(Inode));
    newNode->m_Real_prev = _node;
    newNode->m_next = _node->m_next;
    newNode->m_prev = _node->m_prev;
    _node->m_size = _size;
    _node->m_Real_prev = NULL;
}

static Inode* FindFirstFree(Pool* _pool,size_t _size)
{
    Inode *cur = _pool->m_buffer ;
    
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
        --(_pool->m_totBufleft);
        cur->m_Real_prev = NULL;
        return cur;

    }
    else if(cur->m_size > _size + sizeof(Inode) + DLT)
    {
        Split(cur , _size);
        --(_pool->m_totBufleft);
        return cur;
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
    Inode* newNode;

    if(IS_INVALID(_pool) || 0 == _size)
    {
        return NULL;
    }
    
    newNode = FindFirstFree(_pool,_size);

    return newNode->m_iBuffer; 
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
