#include "task.h"
#include "timeScd.h"
#include "logger.h"

#include <stdlib.h>
#include <assert.h>

#define MAGIC 871235
#define IS_INVALID(T) (NULL == (T) || (T)->m_magic != MAGIC)

struct Task
{
    TaskFunc m_task;
    void* m_context;
    ScdTime* m_period;
    ScdTime* m_nextRun;
    size_t m_magic;
};


Task* Task_Create(TaskFunc _task,void* _context,double _period)
{
    Task* sTask;

    if(NULL == _task|| _period <= 0)
    {
        return NULL;
    }
    sTask = malloc(sizeof(Task));
    if(NULL == sTask)
    {
        return NULL;
    }
    sTask->m_task = _task;
    sTask->m_context = _context;
    sTask->m_period = Time_Convert(_period);
    sTask->m_nextRun = Time_Add(Time_Create(),sTask->m_period);
    sTask->m_magic = MAGIC;
    return sTask;
}

void Task_Destroy(void* _task)
{
    Task* task =_task;

    if(IS_INVALID(task))
    {
        return;
    }
    task->m_magic = 0;
    free(task->m_nextRun);
    free(task->m_period);
    free(task);
}

int Task_Run(void* _task)
{
    Task* task =_task;
    ScdTime sRef,eRef,timeToRun ;
    int rtVal = 0;

    if(IS_INVALID(task))
    {
        return 0;
    }
    sRef = Time_Get_Start();
    rtVal = task->m_task(task->m_context);
    eRef = Time_Get_End();
    timeToRun = Time_Subt(sRef,eRef);
    task->m_nextRun = Time_Add(task->m_nextRun,task->m_period);
    task->m_nextRun = Time_Add(task->m_nextRun,&timeToRun);
    return rtVal;
}

int Task_Comp(const void* _firsTask,const void* _sedcondTask)
{
    Task *firsTask = (Task*)_firsTask ,*sedcondTask = (Task*)_sedcondTask;

    if(IS_INVALID(firsTask) || IS_INVALID(sedcondTask))
    {
        return 0;
    }
    return Time_Comp(*(sedcondTask->m_nextRun),*(firsTask->m_nextRun));
}

void Task_Sleep(void* _task)
{
    Task* task = (Task*)_task;

    assert(!IS_INVALID(task));
    Time_Tsleep(*(task->m_nextRun));
}

