#include "bin_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mu_test.h"



int IntCmp(void* _a,void* _b)
{
	int *num1 = (int*)_a,*num2 = (int*)_b;
	return *num1 < *num2; 
}

/**********************
TreeCreate
**********************/
UNIT(tree_create_normal)
	BSTree* tree = NULL;

	ASSERT_THAT((tree = BSTree_Create(IntCmp)) != NULL);
	BSTree_Destroy(tree,NULL);
END_UNIT
/**********************
TreeInsert
**********************/
UNIT(tree_insert_null_tree)
	int n = 3;

	ASSERT_THAT(BSTree_Insert(NULL, &n) == NULL);
	
END_UNIT

UNIT(tree_insert_normal)
	int i = 0,arr[] = {7,4,2,3,6,5,1};
	BSTreeItr itr1,itr[7];
	BSTree* tree = NULL;
	int* item = &i;

	ASSERT_THAT((tree = BSTree_Create(IntCmp)) != NULL);
	for(i = 0;i < 7;++i)
	{
		itr[i] = BSTree_Insert(tree,&arr[i]);
	}
	itr1 = BSTreeItr_Begin(tree);
	item = BSTreeItr_Get(itr1);
	ASSERT_THAT(*item == 1);
	itr1 = BSTreeItr_End(tree);
	itr1 = BSTreeItr_Prev(itr1);
	item = BSTreeItr_Get(itr1);
	ASSERT_THAT(*item == 7);
	for(i = 0;i < 7;++i)
	{
		item = BSTreeItr_Get(itr[i]);
		ASSERT_THAT(*item == arr[i]);
	}
	BSTree_Destroy(tree,NULL);
END_UNIT

/*
UNIT(tree_insert_exist)
	Tree* tree = NULL;
	ASSERT_THAT((tree = TreeCreate()) != NULL);
	ASSERT_THAT(TreeInsert(tree, 3) == ERR_OK);
	ASSERT_THAT(TreeInsert(tree, 2) == ERR_OK);
	ASSERT_THAT(TreeInsert(tree, 4) == ERR_OK);
	ASSERT_THAT(TreeInsert(tree, 4) == ERR_ALREADY_EXISTS);
	printf("\npre order\n");
	TreePrint(tree, PRE_ORDER);
	TreeDestroy(tree);
END_UNIT
*/
/**********************
TreeIsDataFound
**********************/
/*
UNIT(tree_found_null_tree)
	
	ASSERT_THAT(TreeIsDataFound(NULL, 3) == ERR_NOT_INITIALIZED);
	
END_UNIT

UNIT(tree_found_normal)
	Tree* tree = NULL;
	ASSERT_THAT((tree = TreeCreate()) != NULL);
	ASSERT_THAT(TreeInsert(tree, 3) == ERR_OK);
	ASSERT_THAT(TreeInsert(tree, 2) == ERR_OK);
	ASSERT_THAT(TreeInsert(tree, 4) == ERR_OK);
	ASSERT_THAT(TreeIsDataFound(tree, 3) == ERR_OK);
	ASSERT_THAT(TreeIsDataFound(tree, 4) == ERR_OK);
	ASSERT_THAT(TreeIsDataFound(tree, 2) == ERR_OK);
	ASSERT_THAT(TreeIsDataFound(tree, 5) == ERR_NOT_EXISTS);
	ASSERT_THAT(TreeIsDataFound(tree, 0) == ERR_NOT_EXISTS);
	ASSERT_THAT(TreeIsDataFound(tree, -19) == ERR_NOT_EXISTS);
	TreeDestroy(tree);
END_UNIT
*/
TEST_SUITE(framework test)

	TEST(tree_create_normal)
	TEST(tree_insert_null_tree)
	TEST(tree_insert_normal)
	/*
	TEST(tree_insert_exist)
	TEST(tree_found_null_tree)
	TEST(tree_found_normal)
	*/
END_SUITE
