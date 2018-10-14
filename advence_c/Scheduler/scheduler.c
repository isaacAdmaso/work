#include "scheduler.h"
#include "Heap.h"
#include "Vector.h"
#include "task.h"

#include <stdlib.h>

#define MAGIC  823791
#define IS_INVALID(S) (NULL == (S) || (S)->m_magic != MAGIC)
#define MIN_VEC_SIZE 4

struct Scheduler 
{
    Heap* m_priorityQueue;
    int m_magic;
};

Scheduler* Scheduler_Create(void)
{
    Scheduler *scdul = NULL; 
    Vector *vec = NULL;
    Heap *heap = NULL;

    vec = Vector_Create(MIN_VEC_SIZE,MIN_VEC_SIZE);
    if(NULL == vec)
    {
        return NULL;
    }
    heap = Heap_Build(vec,Task_Comp);
    if(NULL == heap)
    {
        Vector_Destroy(&vec,NULL);
        return NULL;
    }
    scdul = malloc(sizeof(Scheduler));
    if(NULL == scdul)
    {
        Heap_Destroy(&heap);
        Vector_Destroy(&vec,NULL);
        return NULL;
    }
    scdul->m_priorityQueue = heap;
    scdul->m_magic = MAGIC;
    return scdul;
}

void Scheduler_Destroy(Scheduler* _scd)
{
    Vector* vec;

    if(IS_INVALID(_scd))
    {
        return;   
    }
    vec =  Heap_Destroy(&(_scd->m_priorityQueue));
    Vector_Destroy(&vec,Task_Destroy);
    free(_scd);
}

Scheduler_Err Scheduler_Add(Scheduler* _scd,int(*_task)(void*),void* _context,double _period)
{
    void *task;

    if(IS_INVALID(_scd))
    {
        return SCHEDULER_UNINITIALIZED_ERROR;
    }
    task = (void*)Task_Create(_task,_context,_period);
    if(NULL == task)
    {
        return SCHEDULER_ALLOCATION_ERROR;
    }
    if(Heap_Insert(_scd->m_priorityQueue,task) != HEAP_SUCCESS)
    {
    
        return SCHEDULER_ERROR;
    }
    return SCHEDULER_SUCCESS;
}

Scheduler_Err Scheduler_Run(Scheduler* _scd)
{
    void* task;

    if(IS_INVALID(_scd))
    {
        return SCHEDULER_UNINITIALIZED_ERROR;
    }
    while(Heap_Size(_scd->m_priorityQueue) != 0)
    {
        task = Heap_Extract(_scd->m_priorityQueue);
        if(Task_Run(task))
        {
            Heap_Insert(_scd->m_priorityQueue,task);
        }
    }
    return SCHEDULER_SUCCESS;
}
/*
*/