#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Heap.h"
#include "mu_test.h"

#define NOI 10

/*static int arr[]= {7, 3, 10, 11, 12, 13};*/

void FillVector(Vector* v)
{
    int i;
    int* val;
    srand(time(NULL));
    
    for(i = 0; i < NOI; ++i)
    {
        val = (int*)malloc(sizeof(int));
        *val = rand()%10 + 1;
    	Vector_Append(v, val); 
    }
}


int	comparator(const void *_left, const void *_right)
{
    return((*(int*)_left) >= (*(int*)_right));
}


UNIT(heap_create_normal)
    Heap* heap;
    Vector* vector;
    vector = Vector_Create(4, 2);
    FillVector(vector);
    heap = Heap_Build(vector, comparator);
    ASSERT_THAT(heap != NULL);
    Heap_Destroy(&heap);
	Vector_Destroy(&vector, NULL);
END_UNIT

UNIT(heap_create_vector_empty)
    Heap* heap;
    Vector* vector;
    vector = Vector_Create(4, 2);
    heap = Heap_Build(vector, comparator);
    ASSERT_THAT(heap != NULL);
    Heap_Destroy(&heap);
	Vector_Destroy(&vector, NULL);
END_UNIT

UNIT(heap_insert_normal)
    int element  = 100;
    Heap* heap;
    Vector* vector;
    vector = Vector_Create(4, 2);
    FillVector(vector);
    heap = Heap_Build(vector, comparator);
    ASSERT_THAT(Heap_Insert(heap, (void*)&element) == HEAP_SUCCESS);
    Heap_Destroy(&heap);
	Vector_Destroy(&vector, NULL);
END_UNIT

UNIT(heap_peek_normal)
    void* _pValue;
    Heap* heap;
    Vector* vector;
    vector = Vector_Create(4, 2);
    FillVector(vector);
    heap = Heap_Build(vector, comparator);
    Vector_Get(vector, 0, &_pValue);
    ASSERT_THAT(*(int*)Heap_Peek(heap) == *(int*)_pValue);
    Heap_Destroy(&heap);
	Vector_Destroy(&vector, NULL);
END_UNIT

UNIT(heap_extract_normal)
    void* _pValue;
    Heap* heap;
    Vector* vector;
    vector = Vector_Create(4, 2);
    FillVector(vector);
    heap = Heap_Build(vector, comparator);
    Vector_Get(vector, 0, &_pValue);
    ASSERT_THAT(*(int*)Heap_Extract(heap) == *(int*)_pValue);
    Heap_Destroy(&heap);
	Vector_Destroy(&vector, NULL);
END_UNIT

UNIT(heap_size_normal)
    Heap* heap;
    Vector* vector;
    vector = Vector_Create(4, 2);
    FillVector(vector);
    heap = Heap_Build(vector, comparator);
    ASSERT_THAT(Heap_Size(heap) == NOI);
    Heap_Destroy(&heap);
	Vector_Destroy(&vector, NULL);
END_UNIT


TEST_SUITE(heap_test)
    TEST(heap_create_normal)
    TEST(heap_create_vector_empty)
    TEST(heap_insert_normal)
    TEST(heap_peek_normal)
    TEST(heap_extract_normal)
    TEST(heap_size_normal)
END_SUITE
