#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "ADTDefs.h"
#include<stdlib.h>
#include<stddef.h>

typedef struct Queue Queue;

Queue* QueueCreate(size_t _size);
void   QueueDestroy(Queue *_queue);
ADTErr QueueInsert(Queue *_queue, int  _item);
ADTErr QueueRemove(Queue *_queue, int *_item);
int QueueSize(const Queue *_queue);
int    QueueIsEmpty(const Queue *_queue);
void   QueuePrint(const Queue *_queue);


#endif

