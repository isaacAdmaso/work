#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "mu_test.h"



int CheckQueueContent(Queue* _queue, int* _arr, int _size)
{
	size_t  i;
	int val;
	for (i = 0; i < _size; ++i)
	{
		ASSERT_THAT( QueueRemove(_queue, &val) == ERR_OK );
		ASSERT_THAT( val == _arr[i] );
	}
	return PASS;
}


UNIT(create_normal)
	Queue *_queue = QueueCreate();
	ASSERT_THAT(_queue != NULL);
	QueueDestroy(_queue);
END_UNIT

UNIT(queue_insert_null_queue)
    ASSERT_THAT( QueueInsert(NULL, 0) == ERR_NOT_INITIALIZED );
END_UNIT

UNIT(queue_insert_normal)
    Queue *q = QueueCreate();
    ASSERT_THAT( QueueInsert(q, 45) == ERR_OK );
    QueueDestroy(q);
END_UNIT

UNIT(queue_remove_normal)
    int item;
    Queue *q = QueueCreate(2);
    ASSERT_THAT( QueueInsert(q, 45) == ERR_OK );
    ASSERT_THAT( QueueInsert(q, 12) == ERR_OK );
    ASSERT_THAT( QueueRemove(q, &item) == ERR_OK && item == 45 );
    QueueDestroy(q);
END_UNIT

UNIT(queue_remove_null_queue)
    int item;
    ASSERT_THAT( QueueRemove(NULL, &item) == ERR_NOT_INITIALIZED );
END_UNIT

UNIT(Queue_underflow)
	Queue *_queue;
	int i,val;
	int expected[] = { 0, 1, 2, 3, 4 };
	_queue = QueueCreate();
	ASSERT_THAT(_queue != NULL);
	for (i = 0; i < 5; ++i)
	{
		ASSERT_THAT( QueueInsert(_queue, i) == ERR_OK);
	}
	ASSERT_THAT( CheckQueueContent(_queue, expected,5) == PASS);
	ASSERT_THAT(QueueRemove(_queue, &val)==ERR_UNDERFLOW);
	QueueDestroy(_queue);
END_UNIT

UNIT(queue_remove_null_item)
    Queue *q = QueueCreate();
    ASSERT_THAT( QueueRemove(q, NULL) == ERR_NOT_INITIALIZED );
    QueueDestroy(q);
END_UNIT

UNIT(queue_remove_underflow)
    int item;
    Queue *q = QueueCreate();
    ASSERT_THAT( QueueInsert(q, 45) == ERR_OK );
    ASSERT_THAT( QueueRemove(q, &item) == ERR_OK );
    ASSERT_THAT( QueueRemove(q, &item) == ERR_UNDERFLOW );
    QueueDestroy(q);
END_UNIT

UNIT(queue_is_empty_normal)
    Queue *q = QueueCreate();
    ASSERT_THAT( QueueIsEmpty(q) != 0);
    QueueDestroy(q);
END_UNIT

UNIT(queue_is_empty_after_remove)
    int item = 55;
    Queue *q = QueueCreate();
    ASSERT_THAT( QueueInsert(q, item) == ERR_OK );
    ASSERT_THAT( QueueRemove(q, &item) == ERR_OK );
    ASSERT_THAT( QueueIsEmpty(q) == 0);
    QueueDestroy(q);
END_UNIT

UNIT(queue_full_remove_one_add_one)
    int item;
    Queue *q = QueueCreate();
    ASSERT_THAT( QueueInsert(q, 45) == ERR_OK );
    ASSERT_THAT( QueueInsert(q, 23) == ERR_OK );
    ASSERT_THAT( QueueRemove(q, &item) == ERR_OK && item == 45 );
    ASSERT_THAT( QueueInsert(q, 2) == ERR_OK );
    ASSERT_THAT( QueueRemove(q, &item) == ERR_OK && item == 23 ); 
    ASSERT_THAT( QueueRemove(q, &item) == ERR_OK && item == 2 ); 
    QueueDestroy(q);
END_UNIT

UNIT(queue_print_after_insert_and_remove)
    int item;
    Queue *q = QueueCreate();
    ASSERT_THAT( QueueInsert(q, 1) == ERR_OK );
    ASSERT_THAT( QueueInsert(q, 9) == ERR_OK );
    QueuePrint(q);
    ASSERT_THAT( QueueRemove(q, &item) == ERR_OK );
    ASSERT_THAT( QueueInsert(q, 2) == ERR_OK );
    ASSERT_THAT( QueueRemove(q, &item) == ERR_OK );
    ASSERT_THAT( QueueRemove(q, &item) == ERR_OK );
    ASSERT_THAT( QueueInsert(q, 78) == ERR_OK );
    ASSERT_THAT( QueueInsert(q, 23) == ERR_OK );
    QueuePrint(q);
    QueueDestroy(q);
END_UNIT


TEST_SUITE(Queue test)
	TEST(create_normal)
	TEST(queue_insert_null_queue)
	TEST(queue_insert_normal)
	TEST(queue_remove_null_queue)	
	TEST(Queue_underflow)
	TEST(queue_remove_null_item)
	TEST(queue_remove_normal)	
	TEST(queue_remove_underflow)
	TEST(queue_is_empty_normal)
	TEST(queue_is_empty_after_remove)
	TEST(queue_full_remove_one_add_one)
	TEST(queue_print_after_insert_and_remove)
	
END_SUITE


