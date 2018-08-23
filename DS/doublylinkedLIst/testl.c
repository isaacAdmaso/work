#include <stdio.h>
#include <stdlib.h>
#include "LIST.h"
#include "mu_test.h"
#define MAGIC 3567978


int CheckListContent(List_t* _list, int* _arr, int _size)
{
	size_t  i;
	int val;
	for (i = 0; i < _size; ++i)
	{
		ASSERT_THAT( ListPopTail(_list, &val) == ERR_OK );
		ASSERT_THAT( val == _arr[i] );
	}
	return PASS;
}


UNIT(create_normal)
	List_t* l = ListCreate();
	ASSERT_THAT(l != NULL);
	ListDestroy(l);
END_UNIT

UNIT(List_push_head_null_List)
    ASSERT_THAT( ListPushHead(NULL, 0) == ERR_NOT_INITIALIZED );
END_UNIT

UNIT(List_push_tail_null_List)
    ASSERT_THAT( ListPushTail(NULL, 0) == ERR_NOT_INITIALIZED );
END_UNIT


UNIT(List_push_head_normal)
    List_t *l = ListCreate();
    ASSERT_THAT( ListPushHead(l, 45) == ERR_OK );
    ListDestroy(l);
END_UNIT

UNIT(List_push_tail_normal)
    List_t *l = ListCreate();
    ASSERT_THAT( ListPushTail(l, 45) == ERR_OK );
    ListDestroy(l);
END_UNIT

UNIT(List_pop_head_normal)
    int item;
    List_t *l = ListCreate();
    ASSERT_THAT( ListPushHead(l, 45) == ERR_OK );
    ASSERT_THAT( ListPushHead(l, 12) == ERR_OK );
    ASSERT_THAT( ListPopHead(l, &item) == ERR_OK && item == 12 );
    ListDestroy(l);
END_UNIT

UNIT(List_pop_tail_normal)
    int item;
    List_t *l = ListCreate();
    ASSERT_THAT( ListPushHead(l, 45) == ERR_OK );
    ASSERT_THAT( ListPushHead(l, 12) == ERR_OK );
    
    //ASSERT_THAT( ListPopTail(l, &item) == ERR_OK && item == 12 );
    ListDestroy(l);
END_UNIT


UNIT(List_pop_head_null_List)
    int item;
    ASSERT_THAT( ListPopHead(NULL, &item) == ERR_NOT_INITIALIZED );
END_UNIT


UNIT(List_pop_tail_null_List)
    int item;
    ASSERT_THAT( ListPopTail(NULL, &item) == ERR_NOT_INITIALIZED );
END_UNIT

UNIT(List_underflow)
	List_t *_List_t;
	int i,val;
	int expected[] = { 0, 1, 2, 3, 4 };
	_List_t = ListCreate();
	ASSERT_THAT(_List_t != NULL);
	for (i = 0; i < 5; ++i)
	{
		ASSERT_THAT( ListPushHead(_List_t, i) == ERR_OK);
	}
	ASSERT_THAT( CheckListContent(_List_t, expected,5) == PASS);
	ASSERT_THAT(ListPopTail(_List_t, &val)==ERR_UNDERFLOW);
	ListDestroy(_List_t);
END_UNIT


UNIT(List_pop_null_item)
    List_t *l = ListCreate();
    ASSERT_THAT( ListPopHead(l, NULL) == ERR_NOT_INITIALIZED );
    ASSERT_THAT( ListPopTail(l, NULL) == ERR_NOT_INITIALIZED );
    ListDestroy(l);
END_UNIT

UNIT(List_pop_underflow)
    int item;
    List_t *q = ListCreate();
    ASSERT_THAT( ListPushHead(q, 45) == ERR_OK );
    ASSERT_THAT( ListPopTail(q, &item) == ERR_OK );
    ASSERT_THAT( ListPopHead(q, &item) == ERR_UNDERFLOW );
    ASSERT_THAT( ListPopTail(q, &item) == ERR_UNDERFLOW );
    ListDestroy(q);
END_UNIT

/*
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
	TEST(List_push_head_null_List)
	TEST(List_push_tail_null_List)
	TEST(List_pop_head_null_List)	
	TEST(List_pop_tail_null_List)
	//TEST(List_underflow)
	TEST(List_push_head_normal)	
	TEST(List_push_tail_normal)
	TEST(List_pop_head_normal)
	TEST(List_pop_tail_normal)
	TEST(List_pop_null_item)
	TEST(List_pop_underflow)
/*
	TEST(List_t_print_after_insert_and_remove)
	TEST(List_t_print_after_insert_and_remove)
	TEST(List_t_print_after_insert_and_remove)
	TEST(List_t_print_after_insert_and_remove)
*/	
END_SUITE


