#include "task.h"


struct Task
{
    TaskFunc m_task;
    void* m_context;
    ScdTime m_period;
    ScdTime m_nextRun;
};

