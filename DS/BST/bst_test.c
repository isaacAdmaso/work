#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "mu_test.h"
#define ARR_LEN( ARRAY ) ( sizeof(ARRAY) / sizeof(ARRAY[0]) )

UNIT(tree_create_normal)
    Tree* t;
    ASSERT_THAT(t = TreeCreate());
    TreeDestroy( t );
END_UNIT

UNIT(tree_insert_NULL_tree)
    ASSERT_THAT(TreeInsert(NULL, 8) == ERR_NOT_INITIALIZED);
END_UNIT

UNIT(tree_insert_same_data)
    Tree* t;
    ASSERT_THAT(t = TreeCreate());
    ASSERT_THAT(TreeInsert(t, 8) == ERR_OK);
    ASSERT_THAT(TreeInsert(t, 8) == ERR_ALREADY_EXISTS);
    TreeDestroy( t );
END_UNIT

UNIT(tree_insert_after_destroy)
    Tree* t;
    ASSERT_THAT(t = TreeCreate());
    TreeDestroy( t );
    ASSERT_THAT(TreeInsert(t, 8) == ERR_NOT_INITIALIZED);
END_UNIT

UNIT(tree_insert_normal)
    Tree* t;
    int i, arr[13] = {23,2,5,21,675,15,63,8,3,7,53,72,214};
    ASSERT_THAT(t = TreeCreate());
    for(i=0; i < ARR_LEN( arr ); i++)
    {
        ASSERT_THAT(TreeInsert(t, arr[i]) == ERR_OK);
    }
    TreeDestroy( t );
END_UNIT

UNIT(tree_find_normal)
    Tree* t=TreeCreate();
   	ASSERT_THAT(t != NULL);
    ASSERT_THAT(TreeInsert(t, 8) == ERR_OK);
    ASSERT_THAT(TreeIsDataFound(t, 8)== ERR_OK);
    TreeDestroy( t );
END_UNIT

UNIT(tree_find_after_destroy)
    Tree* t=TreeCreate();
   // ASSERT_THAT(t = TreeCreate());
    ASSERT_THAT(TreeInsert(t, 8) == ERR_OK);
    TreeDestroy( t );
    ASSERT_THAT(TreeIsDataFound(t, 8) == ERR_NOT_INITIALIZED);
END_UNIT

UNIT(tree_find_not_exists)
    Tree* t=TreeCreate();
    //ASSERT_THAT(t = TreeCreate());
    ASSERT_THAT(TreeInsert(t, 8) == ERR_OK);
    ASSERT_THAT(TreeIsDataFound(t, 3) == ERR_NOT_EXISTS);
    TreeDestroy( t );
END_UNIT

UNIT(tree_find_NULL)
    ASSERT_THAT(TreeIsDataFound(NULL, 8) == ERR_NOT_INITIALIZED);
END_UNIT

UNIT(tree_all)
    Tree* t;
    int i, arr[13] = {23,2,5,21,675,15,63,8,3,7,53,72,214};
    ASSERT_THAT(t = TreeCreate());
    for(i=0; i < ARR_LEN( arr ); i++)
    {
        ASSERT_THAT(TreeInsert(t, arr[i]) == ERR_OK);
    }
    for(i=0; i < ARR_LEN( arr ); i++)
    {
        ASSERT_THAT(TreeIsDataFound( t, arr[i])== ERR_OK);
    }
    ASSERT_THAT(TreeIsDataFound( t, 2018)== ERR_NOT_EXISTS);
    ASSERT_THAT(TreeInsert(t, 2018) == ERR_OK);
    ASSERT_THAT(TreeInsert(t, 1972) == ERR_OK);
    ASSERT_THAT(TreeInsert(t, 1989) == ERR_OK);
    ASSERT_THAT(TreeIsDataFound( t, 2018)== ERR_OK);
    ASSERT_THAT(TreeIsDataFound( t, 2054) == ERR_NOT_EXISTS);
/*    TreePrint( t, IN_ORDER ); */
    TreeDestroy( t );
END_UNIT

TEST_SUITE(tree_test)
    TEST(tree_create_normal)
    TEST(tree_insert_normal)
    TEST(tree_insert_after_destroy)
    TEST(tree_insert_NULL_tree)
    TEST(tree_insert_same_data)
    TEST(tree_find_normal)
    TEST(tree_find_NULL)
    TEST(tree_find_after_destroy)
    TEST(tree_find_not_exists)
    TEST(tree_all)
END_SUITE
