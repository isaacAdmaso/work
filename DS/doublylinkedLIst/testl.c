#include <stdio.h>
#include <stdlib.h>
#include "LIST.h"
#include "mu_test.h"
#define MAGIC 3567978
/*

int CheckList_tContent(List_t* _List_t, int* _arr, int _size)
{
	size_t  i;
	int val;
	for (i = 0; i < _size; ++i)
	{
		ASSERT_THAT( ListRemove(_List_t, &val) == ERR_OK );
		ASSERT_THAT( val == _arr[i] );
	}
	return PASS;
}

*/
UNIT(create_normal)
	List_t* l = ListCreate();
	ASSERT_THAT(l != NULL);
	ListDestroy(l);
END_UNIT
/*
UNIT(List_t_insert_null_List_t)
    ASSERT_THAT( List_tInsert(NULL, 0) == ERR_NOT_INITIALIZED );
END_UNIT

UNIT(List_t_insert_normal)
    List_t *q = List_tCreate();
    ASSERT_THAT( List_tInsert(q, 45) == ERR_OK );
    List_tDestroy(q);
END_UNIT

UNIT(List_t_remove_normal)
    int item;
    List_t *q = List_tCreate(2);
    ASSERT_THAT( List_tInsert(q, 45) == ERR_OK );
    ASSERT_THAT( List_tInsert(q, 12) == ERR_OK );
    ASSERT_THAT( List_tRemove(q, &item) == ERR_OK && item == 45 );
    List_tDestroy(q);
END_UNIT

UNIT(List_t_remove_null_List_t)
    int item;
    ASSERT_THAT( List_tRemove(NULL, &item) == ERR_NOT_INITIALIZED );
END_UNIT

UNIT(List_t_underflow)
	List_t *_List_t;
	int i,val;
	int expected[] = { 0, 1, 2, 3, 4 };
	_List_t = List_tCreate();
	ASSERT_THAT(_List_t != NULL);
	for (i = 0; i < 5; ++i)
	{
		ASSERT_THAT( List_tInsert(_List_t, i) == ERR_OK);
	}
	ASSERT_THAT( CheckList_tContent(_List_t, expected,5) == PASS);
	ASSERT_THAT(List_tRemove(_List_t, &val)==ERR_UNDERFLOW);
	List_tDestroy(_List_t);
END_UNIT

UNIT(List_t_remove_null_item)
    List_t *q = List_tCreate();
    ASSERT_THAT( List_tRemove(q, NULL) == ERR_NOT_INITIALIZED );
    List_tDestroy(q);
END_UNIT

UNIT(List_t_remove_underflow)
    int item;
    List_t *q = List_tCreate();
    ASSERT_THAT( List_tInsert(q, 45) == ERR_OK );
    ASSERT_THAT( List_tRemove(q, &item) == ERR_OK );
    ASSERT_THAT( List_tRemove(q, &item) == ERR_UNDERFLOW );
    List_tDestroy(q);
END_UNIT

UNIT(List_t_is_empty_normal)
    List_t *q = List_tCreate();
    ASSERT_THAT( List_tIsEmpty(q) != 0);
    List_tDestroy(q);
END_UNIT

UNIT(List_t_is_empty_after_remove)
    int item = 55;
    List_t *q = List_tCreate();
    ASSERT_THAT( List_tInsert(q, item) == ERR_OK );
    ASSERT_THAT( List_tRemove(q, &item) == ERR_OK );
    ASSERT_THAT( List_tIsEmpty(q) == 0);
    List_tDestroy(q);
END_UNIT

UNIT(List_t_full_remove_one_add_one)
    int item;
    List_t *q = List_tCreate();
    ASSERT_THAT( List_tInsert(q, 45) == ERR_OK );
    ASSERT_THAT( List_tInsert(q, 23) == ERR_OK );
    ASSERT_THAT( List_tRemove(q, &item) == ERR_OK && item == 45 );
    ASSERT_THAT( List_tInsert(q, 2) == ERR_OK );
    ASSERT_THAT( List_tRemove(q, &item) == ERR_OK && item == 23 ); 
    ASSERT_THAT( List_tRemove(q, &item) == ERR_OK && item == 2 ); 
    List_tDestroy(q);
END_UNIT

UNIT(List_t_print_after_insert_and_remove)
    int item;
    List_t *q = List_tCreate();
    ASSERT_THAT( List_tInsert(q, 1) == ERR_OK );
    ASSERT_THAT( List_tInsert(q, 9) == ERR_OK );
    List_tPrint(q);
    ASSERT_THAT( List_tRemove(q, &item) == ERR_OK );
    ASSERT_THAT( List_tInsert(q, 2) == ERR_OK );
    ASSERT_THAT( List_tRemove(q, &item) == ERR_OK );
    ASSERT_THAT( List_tRemove(q, &item) == ERR_OK );
    ASSERT_THAT( List_tInsert(q, 78) == ERR_OK );
    ASSERT_THAT( List_tInsert(q, 23) == ERR_OK );
    List_tPrint(q);
    List_tDestroy(q);
END_UNIT

*/
TEST_SUITE(List_t test)
	TEST(create_normal)
/*	TEST(List_t_insert_null_List_t)
	TEST(List_t_insert_normal)
	TEST(List_t_remove_null_List_t)	
	TEST(List_t_underflow)
	TEST(List_t_remove_null_item)
	TEST(List_t_remove_normal)	
	TEST(List_t_remove_underflow)
	TEST(List_t_is_empty_normal)
	TEST(List_t_is_empty_after_remove)
	TEST(List_t_full_remove_one_add_one)
	TEST(List_t_print_after_insert_and_remove)
*/	
END_SUITE


