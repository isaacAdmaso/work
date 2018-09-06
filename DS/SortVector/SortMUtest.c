#include "Sorting .h"
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
	int a[]={12,3,324,56,324,6,734,6,7,4,6,7,9,22,43};
	unsigned int size;
	size = SIZEARR(a);
	FillVector(v,a,size);
	printf("\n");
	VectorPrint(v);
	printf("\n");
	BubbleSort(v,KCmp);
	VectorPrint(v);
	printf("\n");
	VectorDestroy(v);
END_UNIT

UNIT(shakeSort)
	Vector* v = VectorCreate(1,2);
	int a[]={12,3,324,56,324,6,734,6,7,4,6,7,9,22,43};
	unsigned int size;
	size = SIZEARR(a);
	FillVector(v,a,size);
	VectorPrint(v);
	printf("\n");
	ShakeSort(v,KCmp2);
	VectorPrint(v);
	printf("\n");
	VectorDestroy(v);
END_UNIT


UNIT(insertionSort)
	Vector* v = VectorCreate(1,2);
	int a[]={12,3,324,56,324,6,734,6,7,4,6,7,9,22,43};
	unsigned int size;
	size = SIZEARR(a);
	FillVector(v,a,size);
	VectorPrint(v);
	printf("\n");
	InsertionSort(v,KCmp);
	VectorPrint(v);
	printf("\n");
	VectorDestroy(v);
END_UNIT

UNIT(quickSort)
	int a[]={12,3323,324,56,324,6,734,6,7,4,6,7,9,22,43};
	Vector* v = VectorCreate(SIZEARR(a),2);
	unsigned int size;
	size = SIZEARR(a);
	FillVector(v,a,size);
	VectorPrint(v);
	printf("\n");
	QuickSort(v,KCmp);
	VectorPrint(v);
	printf("\n");
	VectorDestroy(v);
END_UNIT

TEST_SUITE(sort test)
	TEST(bubbleSort)
	TEST(shakeSort)
	TEST(insertionSort)
	TEST(quickSort)
END_SUITE

