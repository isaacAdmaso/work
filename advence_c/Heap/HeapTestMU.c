#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"
#include "mu_test.h"

#define SIZE(ARR) sizeof(ARR)/sizeof(ARR[0])



int IntCmp(const void* _a,const void* _b)
{
	int *num1 = (int*)_a,*num2 = (int*)_b;
	return *num1 < *num2; 
}
int arr[]={1,2,3,4,5,36,77,81,298,998,120,92,83,3,24,5,2,3,4,35,5,67,23};
int CreatVector(Vector *v)
{
	int  i;
	for (i = 0; i < SIZE(arr); ++i)
	{
		ASSERT_THAT(Vector_Append(v,&arr[i])==VECTOR_SUCCESS);
	}
	
	return PASS;
}
UNIT(heapBuild)
	Heap *h = NULL;
	Vector *v;
	v=Vector_Create(2,2);
	h = Heap_Build(v,IntCmp);
	ASSERT_THAT(h != NULL);
	Heap_Destroy(&h);
	Vector_Destroy(&v,NULL);

END_UNIT

UNIT(heapBuild_NULL)
	Heap *h;
	Vector *v;
	v = NULL;

	h = Heap_Build(v,IntCmp);
	ASSERT_THAT(h == NULL);
	ASSERT_THAT(Heap_Size(h) == 0);
END_UNIT

UNIT(heapInsert_normal)
	int item = 2303,item2 = 123,*itemPtr = &item;
	Heap *h;
	Vector *v;
	
	v=Vector_Create(2,2);
	CreatVector(v);

	h = Heap_Build(v,IntCmp);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(Heap_Size(h) == SIZE(arr));
	ASSERT_THAT(Heap_Insert(h,&item) == HEAP_SUCCESS);
	itemPtr = (int*)Heap_Peek(h);
	ASSERT_THAT(*itemPtr >= item);
	Heap_Destroy(&h);
	ASSERT_THAT(Heap_Size(h) == 0);
	ASSERT_THAT(Heap_Insert(h,&item2) == HEAP_NOT_INITIALIZED);
	Vector_Destroy(&v,NULL);
	
END_UNIT

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
	ASSERT_THAT(Heap_Size(h) == SIZE(arr) - 1);

	printf("\n%d\n",*intPtr);
	intPtr = (int*)Heap_Peek(h);
	printf("\n%d\n",*intPtr);
	Heap_Destroy(&h);
	ASSERT_THAT(Heap_Insert(h,&num) == HEAP_NOT_INITIALIZED);
	Vector_Destroy(&v,NULL);
END_UNIT


UNIT(heapMaxNormal)
	int item = 2303,item2 = 0;
	int *Ptr2 = &item2;
	Heap *h;
	Vector *v;

	v = Vector_Create(2,2);
	CreatVector(v);
	h = Heap_Build(v,IntCmp);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(Heap_Insert(h,&item) == HEAP_SUCCESS);
	ASSERT_THAT(Heap_Size(h) == SIZE(arr)+1);

	Vector_Print(v);
	Ptr2 = (int*)Heap_Extract(h);
	ASSERT_THAT(*Ptr2 >= 2303);
	Vector_Print(v);
	Heap_Destroy(&h);
	ASSERT_THAT(Heap_Insert(h,&item) == HEAP_NOT_INITIALIZED);
	Vector_Destroy(&v,NULL);
END_UNIT


UNIT(heapSort)
	int item = 2303,item2 = 0;
	int *Ptr2 = &item2;
	Heap *h;
	Vector *v;

	v = Vector_Create(2,2);
	CreatVector(v);
	h = Heap_Build(v,IntCmp);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(Heap_Size(h) == SIZE(arr));

	Vector_Print(v);
	ASSERT_THAT(Heap_Insert(h,&item) == HEAP_SUCCESS);
	ASSERT_THAT(Heap_Size(h) == SIZE(arr)+1);

	Heap_Sort(v,IntCmp);
	Vector_Print(v);
	Ptr2 = (int*)Heap_Extract(h);
	ASSERT_THAT(*Ptr2 >= 2303);
	Vector_Print(v);
	Heap_Destroy(&h);
	ASSERT_THAT(Heap_Insert(h,&item) == HEAP_NOT_INITIALIZED);
	Vector_Destroy(&v,NULL);
END_UNIT

/*
UNIT(heapMaxuNDERFLOW)
	int item;
	Heap *h;
	Vector *v;

	v = VectorCreate(2,2);
	h = Heap_Build(v,IntCmp);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(HeapMax(h,&item) == ERR_UNDERFLOW);
	ASSERT_THAT(HeapExtractMax(h , &item) == ERR_UNDERFLOW);
	HeapDestroy(h);
	VectorDestroy(v);
END_UNIT

 */
/**
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
TEST_SUITE(Heap test)
	TEST(heapBuild)
	TEST(heapBuild_NULL)
	TEST(heapInsert_normal)
	TEST(heapInsert_overflow)
	TEST(heapMaxNormal)	
	TEST(heapSort)
/*
	TEST(heapExtractMax)
	TEST(heapSize)
	TEST(heapMaxNULL)
	TEST(heapMaxuNDERFLOW)
*/
END_SUITE

