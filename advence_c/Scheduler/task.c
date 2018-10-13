#include "task.h"
#include <stdlib.h>

#define MAGIC 871235
#define IS_VALID(T) (NULL == (T) || (T)->m_magic != MAGIC)

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
void Task_Destroy(Task* _task)
{
    if(IS_VALID(_task))
    {
        _task->m_magic = 0;
        free(_task);
    }
}

int Task_Run(Task* _task)
{
    if (IS_VALID(_task))
    {
        return _task->m_task(_task->m_context);
    }
    return 0;
}

int Task_Comp(void* _firsTask,void* _sedcondTask)
{
    Task *firsTask = _firsTask ,*sedcondTask = _sedcondTask;
    if(IS_VALID(firsTask) && IS_VALID(sedcondTask))
    {
        return Time_Comp(firsTask->m_nextRun,sedcondTask->m_nextRun);
    }
    return 0;
}
