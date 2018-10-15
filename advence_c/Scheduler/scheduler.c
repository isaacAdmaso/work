#include "timeScd.h"
#include "scheduler.h"
#include "Heap.h"
#include "logger.h"
#include "Vector.h"
#include "task.h"

#include <stdlib.h>

#define MAGIC  823791
#define MODULE "scheduler"
#define IS_INVALID(S) (NULL == (S) || (S)->m_magic != MAGIC)
#define MIN_VEC_SIZE 4

struct Scheduler 
{
    Heap* m_priorityQueue;
    int m_magic;
    int m_is_pause;
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
    scdul->m_is_pause = 0;
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

static void Scheduler_Re_Do(Scheduler*_scd)
{
    ScdTime time_To_Add = Time_Get_Start();
    ScdTime ref = {0};
    Task* fTask;

    fTask = (Task*)Heap_Peek(_scd->m_priorityQueue);
    time_To_Add = Time_Subt(Task_Get_Next_Run(fTask),time_To_Add);
    if(Time_Eq(time_To_Add,ref))
    {
        return;
    }
    Heap_ForEach(_scd->m_priorityQueue,(int (*)(void *, long unsigned int,  void *))Task_Update_after_P,&time_To_Add);
    _scd->m_is_pause = 0;
}

Scheduler_Err Scheduler_Run(Scheduler* _scd)
{
    void* task;

    if(IS_INVALID(_scd))
    {
        return SCHEDULER_UNINITIALIZED_ERROR;
    }
    ZLOG(MODULE,LOG_CRITICAL,"before  while");
    if(_scd->m_is_pause)
    {
        Scheduler_Re_Do(_scd);
    }
    while(Heap_Size(_scd->m_priorityQueue) != 0 && !(_scd->m_is_pause))
    {
        task = Heap_Extract(_scd->m_priorityQueue);
        Task_Sleep(task);
        ZLOG(MODULE,LOG_CRITICAL,"inside while");
        if (Task_Run(task))
        {
            Heap_Insert(_scd->m_priorityQueue,task);
        }
    }
    return SCHEDULER_SUCCESS;
}

int Scheduler_Pause(void* _scd)
{
    Scheduler* scd = (Scheduler*)_scd;
    scd->m_is_pause = 1;
    return 0;
}
/*
*/