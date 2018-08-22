#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "ADTDefs.h"
#include<stddef.h>

typedef struct Queue Queue;

Queue* QueueCreate();
void   QueueDestroy(Queue *_queue);
ADTErr QueueInsert(Queue *_queue, int  _item);
ADTErr QueueRemove(Queue *_queue, int *_item);
int    QueueIsEmpty(const Queue *_queue);
void   QueuePrint(const Queue *_queue);


#endif

