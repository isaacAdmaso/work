#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "mu_test.h"



int InserTree(Tree* _tree)
{
	int  i,arr[]={1,2,3,4,5,36,77,81,29,120};
	for (i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
	{
		ASSERT_THAT(TreeInsert(_tree,arr[i]) == ERR_OK);
		ASSERT_THAT(TreeIsDataFound(_tree,arr[i]) == ERR_OK);
	}
	return PASS;
}

UNIT(print_tree)
	Tree *t = TreeCreate();
	InserTree(t);
	TreePrint(t,PRE_ORDER);
	printf("\n");
	TreePrint(t,IN_ORDER);
	printf("\n");
	TreePrint(t,POST_ORDER);
	printf("\n");
END_UNIT
	
UNIT(create_normal)
	Tree* t = TreeCreate();
	ASSERT_THAT(t != NULL);
	TreeDestroy(t);
END_UNIT

UNIT(insert_null_tree)
    ASSERT_THAT( TreeInsert(NULL, 0) == ERR_NOT_INITIALIZED );
END_UNIT

UNIT(tree_insert_normal)
    Tree *t = TreeCreate();
    ASSERT_THAT( TreeInsert(t, 45) == ERR_OK );
    ASSERT_THAT( TreeIsDataFound(t,45) == ERR_OK );
    TreeDestroy(t);
END_UNIT


UNIT(tree_insert_item_twice)
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


TEST_SUITE(Tree test)
	TEST(print_tree)
	TEST(create_normal)
	TEST(insert_null_tree)
	TEST(tree_insert_normal)
	TEST(tree_insert_item_twice)	
	TEST(tree_serch_not_exists)
END_SUITE


