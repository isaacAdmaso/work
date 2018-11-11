#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "mu_test.h"

#define SIZEARR(ARR) sizeof(ARR)/sizeof(ARR[0])

int expected[] = { 0, 1, 2, 3, 4 ,12433,574,532,5,345,687,435,62,35,435,456,54,6,47,75,8,69,7372482,262,62,82,89,-123435,29292,9,93,98,83,-132,29,28387,7};


int CheckQueueContent(Queue* _queue, int* _arr, int _size)
{
	size_t  i;
	int val;
	printf("\n%d\n",QueueSize(_queue));
	QueuePrint(_queue);
	for (i = 0; i < _size; ++i)
	{
		ASSERT_THAT( QueueRemove(_queue, &val) == ERR_OK );

		ASSERT_THAT( val == _arr[i] );
	}
	printf("\n%d\n",QueueSize(_queue));
	QueuePrint(_queue);

	return PASS;
}


UNIT(create_normal)
	Queue *_queue = QueueCreate(5);
	printf("\n%d\n",QueueSize(_queue));
	QueuePrint(_queue);

	ASSERT_THAT(_queue != NULL);
	QueueDestroy(_queue);
END_UNIT

UNIT(create_with_zero_size)
	Queue *_queue = QueueCreate(0);
	printf("\n%d\n",QueueSize(_queue));
	QueuePrint(_queue);

	ASSERT_THAT(_queue == NULL);
	QueueDestroy(_queue);
END_UNIT

UNIT(Queue_overflow)
	Queue *_queue;
	int i;
	_queue = QueueCreate(SIZEARR(expected));
	ASSERT_THAT(_queue != NULL);
	for (i = 0; i < SIZEARR(expected); ++i)
	{
		ASSERT_THAT( QueueInsert(_queue, expected[i]) == ERR_OK);
	}
	ASSERT_THAT( QueueInsert(_queue, i) == ERR_OVERFLOW);
	printf("\n%d\n",QueueSize(_queue));
	QueuePrint(_queue);
	
	ASSERT_THAT( CheckQueueContent(_queue, expected,SIZEARR(expected)) == PASS);
	
	QueueDestroy(_queue);
END_UNIT

UNIT(Queue_underflow)
	Queue *_queue;
	int i,val;
	_queue = QueueCreate(SIZEARR(expected));
	ASSERT_THAT(_queue != NULL);
	for (i = 0; i < SIZEARR(expected); ++i)
	{
		ASSERT_THAT( QueueInsert(_queue, expected[i]) == ERR_OK);
		printf("\n%d\n",QueueSize(_queue));
		QueuePrint(_queue);

	}
	ASSERT_THAT( QueueInsert(_queue, i) == ERR_OVERFLOW);
	
	ASSERT_THAT( CheckQueueContent(_queue, expected,SIZEARR(expected)) == PASS);

	ASSERT_THAT(QueueRemove(_queue, &val)==ERR_UNDERFLOW);

	QueueDestroy(_queue);
END_UNIT





TEST_SUITE(Queue test)
	TEST(create_normal)
	TEST(create_with_zero_size)
	TEST(Queue_overflow)
	TEST(Queue_underflow)
END_SUITE


