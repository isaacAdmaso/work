#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"
#include "mu_test.h"



int CreatVector(Vector *v)
{
	int  i;
	int arr[]={1,2,3,4,5,36,77,81,29,120};
	for (i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
	{
		ASSERT_THAT(VectorAdd(v,arr[i]) == ERR_OK);
	}
	return PASS;
}

UNIT(heapBuild)
	Heap *h;
	Vector *v;
	v=VectorCreate(2,2);
	CreatVector(v);
	h = HeapBuild(v);
	ASSERT_THAT(h != NULL);
	HeapDestroy(h);
	VectorDestroy(v);
END_UNIT

UNIT(heapBuild_NULL)
	Heap *h;
	Vector *v;
	v = NULL;
	h = HeapBuild(v);
	ASSERT_THAT(h == NULL);
	HeapDestroy(h);
	VectorDestroy(v);
END_UNIT

UNIT(heapInsert_normal)
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

UNIT(heapInsert_null)
	Heap *h;
	h = NULL;
	ASSERT_THAT(h == NULL);
	ASSERT_THAT(HeapInsert(h,2303) == ERR_NOT_INITIALIZED);
	HeapDestroy(h);
END_UNIT


UNIT(heapInsert_overflow)
	Heap *h;
	Vector *v;
	v=VectorCreate(1,0);
	CreatVector(v);
	h = HeapBuild(v);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(HeapInsert(h,2303) == ERR_OVERFLOW);
	HeapDestroy(h);
	VectorDestroy(v);
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


TEST_SUITE(Heap test)
	TEST(heapBuild)
	TEST(heapInsert_normal)
	TEST(heapBuild_NULL)
	TEST(heapInsert_null)
	TEST(heapInsert_overflow)
	TEST(heapMaxNormal)	
	TEST(heapExtractMax)
	TEST(heapSize)
	TEST(heapMaxNULL)
	TEST(heapMaxuNDERFLOW)
END_SUITE

