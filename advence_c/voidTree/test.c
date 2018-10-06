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
/*
UNIT(tree_insert_null_tree)
	
	ASSERT_THAT(TreeInsert(NULL, 3) == ERR_NOT_INITIALIZED);
	
END_UNIT

UNIT(tree_insert_nornal)
	Tree* tree = NULL;
	ASSERT_THAT((tree = TreeCreate()) != NULL);
	ASSERT_THAT(TreeInsert(tree, 3) == ERR_OK);
	ASSERT_THAT(TreeInsert(tree, 2) == ERR_OK);
	ASSERT_THAT(TreeInsert(tree, 4) == ERR_OK);
	printf("\npre order\n");
	TreePrint(tree, PRE_ORDER);
	printf("\nin order\n");
	TreePrint(tree, IN_ORDER);
	printf("\npost order\n");
	TreePrint(tree, POST_ORDER);
	TreeDestroy(tree);
END_UNIT

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
	/*
	TEST(tree_insert_null_tree)
	TEST(tree_insert_nornal)
	TEST(tree_insert_exist)
	TEST(tree_found_null_tree)
	TEST(tree_found_normal)
	*/
END_SUITE
