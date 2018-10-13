#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include <stddef.h>
#include "task.h"


typedef struct Scheduler Scheduler;


typedef enum Scheduler_Err {
	SCHEDULER_SUCCESS = 0,
	SCHEDULER_UNINITIALIZED_ERROR,			/**< Uninitialized list 					 	*/
	SCHEDULER_ALLOCATION_ERROR,				/**< Node allocation failed due to heap error   */
	SCHEDULER_UNDERFLOW_ERROR,
	SCHEDULER_NULL_ELEMENT_ERROR
	/* Add more as needed by your implementation */
	
}Scheduler_Err;

Scheduler* Scheduler_Create(void);

void Scheduler_Destroy(Scheduler* _scd);

Scheduler_Err Scheduler_Add(Scheduler* _scd,TaskFunc _task,void* _context,double _period);

Scheduler_Err Scheduler_Run(Scheduler* _scd);


#endif /**__SCHEDULER_H__ */