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
UNIT(heapInsert)
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
END_UNIT
/*	

UNIT(HeapMax)
    ASSERT_THAT( TreeInsert(NULL, 0) == ERR_NOT_INITIALIZED );
END_UNIT

UNIT(HeapExtractMax)
    Tree *t = TreeCreate();
    ASSERT_THAT( TreeInsert(t, 45) == ERR_OK );
    ASSERT_THAT( TreeIsDataFound(t,45) == ERR_OK );
    TreeDestroy(t);
END_UNIT


UNIT(HeapSize)
    Tree *t = TreeCreate();
    InserTree(t);
    ASSERT_THAT( TreeInsert(t,3) == ERR_ALREADY_EXISTS );
    ASSERT_THAT( TreeInsert(t,4) == ERR_ALREADY_EXISTS );
    TreeDestroy(t);
END_UNIT

UNIT(tree_serch_not_exists)
    Tree *t = TreeCreate();
    ASSERT_THAT( TreeInsert(t, 45) == ERR_OK );
    ASSERT_THAT( TreeInsert(t, 23) == ERR_OK );
    ASSERT_THAT( TreeIsDataFound(t,23) == ERR_OK );
    ASSERT_THAT( TreeIsDataFound(t,50) == ERR_NOT_EXISTS );
    TreeDestroy(t);
END_UNIT


	TEST(insert_null_tree)
	TEST(tree_insert_normal)
	TEST(tree_insert_item_twice)	
	TEST(tree_serch_not_exists)
*/
TEST_SUITE(Tree test)
	TEST(heapBuild)
	TEST(heapInsert)


END_SUITE

