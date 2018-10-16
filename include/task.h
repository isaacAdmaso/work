#ifndef __TASK_H__
#define __TASK_H__

#include <stddef.h>
#include "timeScd.h"



typedef struct Task Task;
typedef int(*TaskFunc)(void* _context);

TaskFunc Task_Get_Func(Task* _task);

void* Task_Get_Context(Task* _task);

double Task_Get_Period(Task* _task);

int Task_Update_after_P(Task* _task,size_t _i,ScdTime* _timeToAdd);

Task* Task_Create(TaskFunc _task,void* _context,double _period);

ScdTime Task_Get_Time(Task* _task);

void Task_Destroy(void* _task);

int Task_Run(void* _task);

void Task_Sleep(void* _task);

int Task_Comp(const void* _firsTask,const void* _sedcondTask);






#endif /**__TASK_H__ */