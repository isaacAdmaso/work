#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "mu_test.h"



int InserTree(Tree* _tree, int _size)
{
	int  i;
	for (i = 0; i < _size; ++i)
	{
		ASSERT_THAT( TreeInsert(_tree,i) == ERR_OK );
		ASSERT_THAT( TreeIsDataFound(_tree,i) == ERR_OK );
	}
	return PASS;
}

UNIT(print_tree)
	Tree *t = TreeCreate();
	InserTree(t,10);
	TreePrint(t,PRE_ORDER);
	TreePrint(t,IN_ORDER);
	TreePrint(t,POST_ORDER);
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
    InserTree(t,7);
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
	TEST(create_normal)
	TEST(insert_null_tree)
	TEST(tree_insert_normal)
	TEST(tree_insert_item_twice)	
	TEST(tree_serch_not_exists)
END_SUITE


