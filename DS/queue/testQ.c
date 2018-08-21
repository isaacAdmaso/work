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
	Queue *_queue = QueueCreate(5);
	ASSERT_THAT(_queue != NULL);
	QueueDestroy(_queue);
END_UNIT

UNIT(create_with_zero_size)
	Queue *_queue = QueueCreate(0);
	ASSERT_THAT(_queue == NULL);
	QueueDestroy(_queue);
END_UNIT

UNIT(Queue_overflow)
	Queue *_queue;
	int i;
	int expected[] = { 0, 1, 2, 3, 4 };
	_queue = QueueCreate(5);
	ASSERT_THAT(_queue != NULL);
	for (i = 0; i < 5; ++i)
	{
		ASSERT_THAT( QueueInsert(_queue, i) == ERR_OK);
	}
	ASSERT_THAT( QueueInsert(_queue, i) == ERR_OVERFLOW);
	
	ASSERT_THAT( CheckQueueContent(_queue, expected,5) == PASS);
	
	QueueDestroy(_queue);
END_UNIT

UNIT(Queue_underflow)
	Queue *_queue;
	int i,val;
	int expected[] = { 0, 1, 2, 3, 4 };
	_queue = QueueCreate(5);
	ASSERT_THAT(_queue != NULL);
	for (i = 0; i < 5; ++i)
	{
		ASSERT_THAT( QueueInsert(_queue, i) == ERR_OK);
	}
	ASSERT_THAT( QueueInsert(_queue, i) == ERR_OVERFLOW);
	
	ASSERT_THAT( CheckQueueContent(_queue, expected,5) == PASS);

	ASSERT_THAT(QueueRemove(_queue, &val)==ERR_UNDERFLOW);

	QueueDestroy(_queue);
END_UNIT





TEST_SUITE(Queue test)
	TEST(create_normal)
	TEST(create_with_zero_size)
	TEST(Queue_overflow)
	TEST(Queue_underflow)
END_SUITE


