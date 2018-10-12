#ifndef __TASK_H__
#define __TASK_H__

#include "time.h"
#include <stddef.h>


typedef struct Task Task;
typedef int(*TaskFunc)(void* _context);

Task* Task_Create(TaskFunc _task,void* _context,double _period);

void Task_Destroy(Task* _task);

int Task_Run(Task* _task);

int Task_Comper(Task* _firsTask,Task* _sedcondTask);




#endif /**__TASK_H__ */