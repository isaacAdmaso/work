#include "task.h"
#include <stdlib.h>

#define MAGIC 871235
#define IS_INVALID(T) (NULL == (T) || (T)->m_magic != MAGIC)

struct Task
{
    TaskFunc m_task;
    void* m_context;
    ScdTime m_period;
    ScdTime m_nextRun;
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
    sTask->m_period = sTask->m_nextRun = Time_Convert(_period);
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
    free(task);
}

int Task_Run(void* _task)
{
    Task* task =_task;

    if(IS_INVALID(task))
    {
        return 0;
    }
    return task->m_task(task->m_context);
}

int Task_Comp(const void* _firsTask,const void* _sedcondTask)
{
    Task *firsTask = (Task*)_firsTask ,*sedcondTask = (Task*)_sedcondTask;

    if(IS_INVALID(firsTask) || IS_INVALID(sedcondTask))
    {
        return 0;
    }
    return Time_Comp(firsTask->m_nextRun,sedcondTask->m_nextRun);
}
