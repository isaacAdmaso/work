#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"
#include "person.h"
#include "logger.h"
#include "mu_test.h"


/*
int IntCmp(const void* _a,const void* _b)
{
	int *num1 = (int*)_a,*num2 = (int*)_b;
	return *num1 < *num2; 
}
int arr[]={1,2,3,4,5,36,77,81,298998,120};
int CreatVector(Vector *v)
{
	int  i;
	for (i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
	{
		ASSERT_THAT(Vector_Append(v,&arr[i])==VECTOR_SUCCESS);
	}
	
	return PASS;
}
*/

UNIT(SchedulerBuild)

	Scheduler *scd = NULL;

	scd = Scheduler_Create();
	ASSERT_THAT(scd != NULL);
	Scheduler_Destroy(scd);

END_UNIT


UNIT(heapInsert_normal)

	Scheduler *scd = NULL;
	Person p = {50, 409572, "Crane, sarus"};
	int num = 999999;
	Zlog_Init("Confile.txt");


	scd = Scheduler_Create();
	ASSERT_THAT(scd != NULL);
	ASSERT_THAT(Scheduler_Add(scd,Person_print_Scd,(void*)&p,1) == SCHEDULER_SUCCESS);
	ASSERT_THAT(Scheduler_Add(scd,IntPrt_Scd,(void*)&num,0.2) == SCHEDULER_SUCCESS);
	ASSERT_THAT(Scheduler_Run(scd) == SCHEDULER_SUCCESS);

	
/*	
	itmPtr = Heap_Peek(h);
	itemPtr = (int*)itmPtr;
	ASSERT_THAT(*itemPtr == item);
	Heap_Destroy(&h);
	ASSERT_THAT(Heap_Insert(h,&item2) == HEAP_NOT_INITIALIZED);
	Vector_Destroy(&v,NULL);
	*/
	Zlog_Destroy();
	Scheduler_Destroy(scd);
END_UNIT

/*
UNIT(heapInsert_null)
	Heap *h;
	int num = 1324;

	h = NULL;
	ASSERT_THAT(Heap_Insert(h,&num) == HEAP_NOT_INITIALIZED);
	Heap_Destroy(&h);
END_UNIT


UNIT(heapInsert_overflow)
	Heap *h;
	Vector *v;
	int num = 3,*intPtr = &num;

	v = Vector_Create(2,2);
	CreatVector(v);
	h = Heap_Build(v,IntCmp);
	ASSERT_THAT(h != NULL);
	intPtr = (int*)Heap_Peek(h);
	Vector_Print(v);
	printf("\n%d\n",*intPtr);
	intPtr = (int*)Heap_Extract(h);
	printf("\n%d\n",*intPtr);
	Heap_Destroy(&h);
	ASSERT_THAT(Heap_Insert(h,&num) == HEAP_NOT_INITIALIZED);
	Vector_Destroy(&v,NULL);
END_UNIT


UNIT(heapMaxNormal)
	int item;
	Heap *h;
	Vector *v;
	v=VectorCreate(2,2);
	CreatVector(v);
	h = HeapBuild(v);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(HeapInsert(h,2303) == ERR_OK);
	ASSERT_THAT(HeapExtractMax(h , &item) == ERR_OK);
	ASSERT_THAT(item == 2303);
	HeapDestroy(h);
	VectorDestroy(v);
END_UNIT


UNIT(heapMaxNULL)
	int item;
	Heap *h;
	h = NULL;
	ASSERT_THAT(HeapMax(h,&item) == ERR_NOT_INITIALIZED);
END_UNIT

UNIT(heapMaxuNDERFLOW)
	int item;
	Heap *h;
	Vector *v;
	v=VectorCreate(2,2);
	h = HeapBuild(v);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(HeapMax(h,&item) == ERR_UNDERFLOW);
	ASSERT_THAT(HeapExtractMax(h , &item) == ERR_UNDERFLOW);
	HeapDestroy(h);
	VectorDestroy(v);
END_UNIT

UNIT(heapExtractMax)
	int item;
	Heap *h;
	Vector *v;
	v=VectorCreate(2,2);
	CreatVector(v);
	h = HeapBuild(v);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(HeapInsert(h,2303) == ERR_OK);
	ASSERT_THAT(HeapExtractMax(h , &item) == ERR_OK);
	ASSERT_THAT(item == 2303);
	ASSERT_THAT(HeapExtractMax(h , &item) == ERR_OK);
	ASSERT_THAT(item != 2303);
	HeapDestroy(h);
	VectorDestroy(v);
END_UNIT


UNIT(heapSize)
	Heap *h;
	Vector *v;
	h = NULL;
	ASSERT_THAT(HeapSize(h) == -1);
	v=VectorCreate(2,2);
	h = HeapBuild(v);
	ASSERT_THAT(HeapSize(h) == 0);
	CreatVector(v);
	h = HeapBuild(v);
	ASSERT_THAT(HeapSize(h) == 10);
	HeapDestroy(h);
	VectorDestroy(v);

END_UNIT

*/
TEST_SUITE(Scheduler test)

	TEST(SchedulerBuild)
	TEST(heapInsert_normal)
/*
	TEST(heapBuild_NULL)
	TEST(heapInsert_overflow)
	TEST(heapInsert_null)
	TEST(heapMaxNormal)	
	TEST(heapExtractMax)
	TEST(heapSize)
	TEST(heapMaxNULL)
	TEST(heapMaxuNDERFLOW)
*/
END_SUITE

