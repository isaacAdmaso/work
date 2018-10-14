#ifndef __TASK_H__
#define __TASK_H__

#include <stddef.h>


typedef struct Task Task;
typedef int(*TaskFunc)(void* _context);


Task* Task_Create(TaskFunc _task,void* _context,double _period);

void Task_Destroy(void* _task);

int Task_Run(void* _task);

int Task_Comp(const void* _firsTask,const void* _sedcondTask);




#endif /**__TASK_H__ */