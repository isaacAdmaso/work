#include "Sort.h"
#include "mu_test.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZEARR(a) sizeof(a)/sizeof(a[0])

static void Pr(int* arr,unsigned int size)
{
	int i;
	for(i = 0;i<size;++i)
		printf(" %d,", arr[i]);
	printf("\n");
}
		
		
UNIT(bubbleSort)
	int a[]={12,3,324,56,324,6,734,6,7,4,6,7,9,22,43};
	unsigned int size;
	size = SIZEARR(a);
	BubbleSort(a,size);
	Pr(a,size);
END_UNIT

UNIT(shakeSort)
	int a[]={12,3,324,56,324,6,734,6,7,4,6,7,9,22,43};
	unsigned int size;
	size = SIZEARR(a);
	ShakeSort(a,size);
	Pr(a,size);

END_UNIT


UNIT(insertionSort)
	int a[]={12,3,324,56,324,6,734,6,7,4,6,7,9,22,43};
	unsigned int size;
	size = SIZEARR(a);
	InsertionSort(a,size);
	Pr(a,size);

END_UNIT

TEST_SUITE(sort test)
	TEST(bubbleSort)
	TEST(shakeSort)
	TEST(insertionSort)
END_SUITE

