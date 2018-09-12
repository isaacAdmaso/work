#include "Sorting.h"
#include "mu_test.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZEARR(a) sizeof(a)/sizeof(a[0])


int KCmp(int _1val, int _2val)	
{
	return 	_2val - _1val;
}

int KCmp2(int _1val, int _2val)	
{
	return 	_1val - _2val;
}


static int	FillVector(Vector* v, int values[], size_t _size)
{
	int i;
	for(i = 0; i < _size; ++i)
	{
		ASSERT_THAT(VectorAdd(v, values[i]) == ERR_OK);
	}
	return PASS;
}	
		


UNIT(bubbleSort)
	Vector* v = VectorCreate(1,2);
	int a[]={12,33049,324,56,324,6,734,6,7,4,6,7,9,22,43};
	unsigned int size;
	size = SIZEARR(a);
	FillVector(v,a,size);
	VectorPrint(v);
	BubbleSort(v,KCmp2);
	VectorPrint(v);
	VectorDestroy(v);
END_UNIT

UNIT(shakeSort)
	Vector* v = VectorCreate(1,2);
	int a[]={12,33049,324,56,324,6,734,6,7,4,6,7,9,22,43};
	unsigned int size;
	size = SIZEARR(a);
	FillVector(v,a,size);
	VectorPrint(v);
	ShakeSort(v,KCmp2);
	VectorPrint(v);
	VectorDestroy(v);
END_UNIT


UNIT(insertionSort)
	Vector* v = VectorCreate(1,2);
	int a[]={12,3,324,56,324,6,734,6,7,4,6,7,9,22,43};
	unsigned int size;
	size = SIZEARR(a);
	FillVector(v,a,size);
	VectorPrint(v);
	InsertionSort(v,KCmp2);
	VectorPrint(v);
	VectorDestroy(v);
END_UNIT

UNIT(quickSort)
	int i;
	Vector* v = VectorCreate(2,2);
	for(i = 0; i<12;++i)
		VectorAdd(v,i);
	VectorPrint(v);
	QuickSort(v,KCmp2);
	VectorPrint(v);
	VectorDestroy(v);
END_UNIT

TEST_SUITE(sort test)
	TEST(bubbleSort)
	TEST(shakeSort)
	TEST(insertionSort)
	TEST(quickSort)

END_SUITE

