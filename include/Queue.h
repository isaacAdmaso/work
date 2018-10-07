#ifndef __QUEUE_H__
#define __QUEUE_H__
/**
 * @file Queue.h
 * @brief queue usuing generic doubly linked list
 * @version 0.1
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <stdlib.h>
#include <stddef.h>
#include "list.h"

typedef struct Queue Queue;

typedef enum Queue_Result {
	QUEUE_SUCCESS = 0,
	QUEUE_NOT_INITIALIZED,
	QUEUE_UNDERFLOW
} Queue_Result;

/**
 * @brief create queue using list 
 * 
 */
Queue* Queue_Create(void);

/**
 * @brief free memory 
 * 
 */
void   Queue_Destroy(Queue *_queue, void (*_elementDestroy)(void* _item));

/**
 * @brief remove first element
 * 
 */
Queue_Result Queue_Remove(Queue *_queue, void **_item);

/**
 * @brief insert to the end
 * 
 */
Queue_Result Queue_Insert(Queue *_queue, void*  _item);

/**
 * @brief check if empty
 * 
 */
size_t   Queue_IsEmpty(const Queue *_queue);


#endif /** __QUEUE_H__ */

