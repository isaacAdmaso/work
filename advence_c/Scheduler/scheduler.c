#include "scheduler.h"
#include "../../include/Heap.h"
#include "../../include/Vector.h"
#include "timeScd.h"


#include <stdlib.h>

#define MAGIC  823791
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
        Vector_Destroy(vec,NULL);
        return NULL;
    }
    scdul->m_priorityQueue = heap;
    scdul->m_magic = MAGIC;
    return scdul;
}

/*
void Scheduler_Destroy(Scheduler* _scd)
{

}

Scheduler_Err Scheduler_Add(Scheduler* _scd,TaskFunc _task,void* _context,double _period);

Scheduler_Err Scheduler_Run(Scheduler* _scd);
*/