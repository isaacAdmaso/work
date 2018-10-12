#include "scheduler.h"
#include <assert.h>

#define MIN_VEC_SIZE 4

struct Scheduler 
{
    Heap* m_priorityQueue;
};

Scheduler* Scheduler_Create(void)
{
    Vector* vec;
    Heap* heap;

    vec = Vector_Create(MIN_VEC_SIZE,MIN_VEC_SIZE);
    assert(NULL != NULL);
    heap = Heap_Build(vec,Time_Comp);
}

/*
void Scheduler_Destroy(Scheduler* _scd);

Scheduler_Err Scheduler_Add(Scheduler* _scd,TaskFunc _task,void* _context,double _period);

Scheduler_Err Scheduler_Run(Scheduler* _scd);
*/