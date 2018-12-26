#include <stdio.h>
#include <stdlib.h>
#include "../../include/Queue.h"
#include "mu_test.h"



int CheckQueueContent(Queue* _queue, int* _arr, int _size)
{
	size_t  i;
	int num = 3,*val = &num;
	for (i = 0; i < _size; ++i)
	{
		ASSERT_THAT( Queue_Remove(_queue,(void**) &val) == QUEUE_SUCCESS);
		ASSERT_THAT( *val == _arr[i] );
	}
	return PASS;
}

UNIT(create_normal)
	Queue *_queue = Queue_Create();
	ASSERT_THAT(_queue != NULL);
	Queue_Destroy(_queue,NULL);
END_UNIT


UNIT(Queue_insert)
	Queue *_queue;
	int i,num;
	int expected[] = { 0, 1, 2, 3, 4 };
	_queue = Queue_Create();
	ASSERT_THAT(_queue != NULL);
	for (i = 0; i < 5; ++i)
	{
        num = i;
		ASSERT_THAT( Queue_Insert(_queue, &num) == QUEUE_SUCCESS);
	}
	
	CheckQueueContent(_queue, expected,5);
	
	Queue_Destroy(_queue,NULL);
END_UNIT

UNIT(Queue_underflow)
	Queue *_queue;
	int num = 3,i,*val = &num;
	int expected[] = { 0, 1, 2, 3, 4 };
	_queue = Queue_Create();
	ASSERT_THAT(_queue != NULL);
	for (i = 0; i < 5; ++i)
	{
		ASSERT_THAT( Queue_Insert(_queue, &i) == QUEUE_SUCCESS);
	}
	
	CheckQueueContent(_queue, expected,5);

	ASSERT_THAT(Queue_Remove(_queue,(void**) &val) == QUEUE_UNDERFLOW);

	Queue_Destroy(_queue,NULL);
END_UNIT

/*
*/



TEST_SUITE(Queue test)
	TEST(create_normal)
	TEST(Queue_insert)
	TEST(Queue_underflow)
/*
	TEST(Queue_overflow)
*/
END_SUITE


