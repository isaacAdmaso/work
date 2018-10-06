#include <stdio.h>
#include "LIST.h"
#include "mu_test.h"


typedef List_t List;
UNIT (list_create)
	List* list = ListCreate();
	ASSERT_THAT(list != NULL);
END_UNIT	 



UNIT (List_Push_Head_NULL)
	ASSERT_THAT(ListPushHead(NULL,4) == ERR_NOT_INITIALIZED);
END_UNIT


UNIT (List_Push_Head_Nurmal)
	List* list = ListCreate();
	ASSERT_THAT(ListPushHead(list,4) == ERR_OK);
END_UNIT



UNIT (List_Push_Head_After_Destroyed)
	List* list = ListCreate();
	ListPushHead(list,4);
	ListDestroy(list);
	ASSERT_THAT(ListPushHead(list,4) == ERR_NOT_INITIALIZED);          
END_UNIT	 


UNIT (List_Push_Tail_NULL)
	ASSERT_THAT(ListPushTail(NULL,4) == ERR_NOT_INITIALIZED);
END_UNIT



UNIT (List_Push_Tail_Nurmal)
	List* list = ListCreate();
	ASSERT_THAT(ListPushTail(list,4) == ERR_OK);
END_UNIT



UNIT (List_Push_Tail_After_Destroyed)
	List* list = ListCreate();
	ListPushTail(list,10);
	ListDestroy(list);
	ASSERT_THAT(ListPushTail(list,4) == ERR_NOT_INITIALIZED);
END_UNIT


UNIT (List_Pop_Head_NULL_Data)
	List* list = ListCreate();
	ASSERT_THAT(ListPopHead(list,NULL) == ERR_NOT_INITIALIZED);
END_UNIT



UNIT (List_Pop_Head_NULL_list)
	int x;
	ASSERT_THAT(ListPopHead(NULL,&x) == ERR_NOT_INITIALIZED);
END_UNIT



UNIT (List_Pop_Head_After_Destroyed)
	int x;
	List* list = ListCreate();
	ListPushTail(list,5);
	ListDestroy(list);
	ASSERT_THAT(ListPopHead(list,&x) == ERR_NOT_INITIALIZED);
END_UNIT



UNIT (List_Pop_Head_No_Node)
	int x;
	List* list = ListCreate();
	ASSERT_THAT(ListPopHead(list,&x) == ERR_UNDERFLOW);
END_UNIT



UNIT (List_Pop_Head_Nurmal)
	int x, data=10;
	List* list = ListCreate();
	ListPushHead(list,data);
	ASSERT_THAT(ListPopHead(list,&x) == ERR_OK);
END_UNIT



UNIT (List_Pop_Tail_NULL_Data)
	List* list = ListCreate();
	ASSERT_THAT(ListPopTail(list,NULL) == ERR_NOT_INITIALIZED);
END_UNIT



UNIT (List_Pop_Tail_NULL_List)
	int x;
	ASSERT_THAT(ListPopTail(NULL,&x) == ERR_NOT_INITIALIZED);
END_UNIT



UNIT (List_Pop_Tail_After_Destroyed)
	int x;
	List* list = ListCreate();
	ListDestroy(list);
	ASSERT_THAT(ListPopTail(list,&x) == ERR_NOT_INITIALIZED);
END_UNIT


UNIT (List_Pop_Tail_No_Node)
	int x;
	List* list = ListCreate();
	ASSERT_THAT(ListPopTail(list,&x) == ERR_UNDERFLOW);
END_UNIT



UNIT (List_Pop_Tail_Nurmal)
	int x, data=10;
	List* list = ListCreate();
	ListPushTail(list,data);
	ASSERT_THAT(ListPopTail(list,&x) == ERR_OK);
END_UNIT



UNIT (List_Count_Items_NULL_List)
	int data=10;
	List* list = NULL;
	ListPushTail(list,data);
	ASSERT_THAT(ListCountItems(list) == 0);
END_UNIT

UNIT (List_Count_Items_After_Destroyed)
	int data=10;
	List* list = ListCreate();
	ListPushTail(list,data);
	ListDestroy(list);
	ASSERT_THAT(ListCountItems(list) == 0);
END_UNIT


UNIT (List_Count_Items_Normal)
	int data=10;
	List* list = ListCreate();
	ListPushTail(list,data);
	ListPushTail(list,data);
	ASSERT_THAT(ListCountItems(list) == 2);
	ListPrint(list);
END_UNIT


UNIT (List_Is_Empty_NULL_List)
	int data=10;
	List* list = NULL;
	ListPushTail(list,data);
	ASSERT_THAT(ListIsEmpty(list) == 1);
END_UNIT


UNIT (List_Is_Empty_No_Push)
	List* list = NULL;
	ASSERT_THAT(ListIsEmpty(list) == 1);
END_UNIT



UNIT (List_Is_Empty_After_Destroyed)
	int data=10;
	List* list = ListCreate();
	ListPushTail(list,data);
	ASSERT_THAT(ListIsEmpty(list) == 1);
END_UNIT



UNIT (List_Is_Empty_Normal)
	int data=10;
	List* list = ListCreate();
	ListPushTail(list,data);
	ListPushTail(list,data);
	ASSERT_THAT(ListIsEmpty(list) == 0);
END_UNIT


TEST_SUITE(list tester)
	TEST(list_create)
	
	TEST(List_Push_Head_NULL)
	TEST(List_Push_Head_Nurmal)
	TEST(List_Push_Head_After_Destroyed)
	
	TEST(List_Push_Tail_NULL)
	TEST(List_Push_Tail_Nurmal)
	TEST(List_Push_Tail_After_Destroyed)
	
	TEST(List_Pop_Head_NULL_Data)
	/*TEST(List_Pop_Head_NULL_list)
	TEST(List_Pop_Head_After_Destroyed)
	TEST(List_Pop_Head_Nurmal)
	TEST(List_Pop_Head_No_Node)
	
	TEST(List_Pop_Tail_NULL_Data)
	TEST(List_Pop_Tail_NULL_List)*/
	TEST(List_Pop_Tail_After_Destroyed)
	TEST(List_Pop_Tail_No_Node)
	TEST(List_Pop_Tail_Nurmal)
	
	TEST (List_Count_Items_NULL_List)
	/*TEST (List_Count_Items_After_Destroyed)*/
	TEST (List_Count_Items_Normal)
	
	TEST (List_Is_Empty_NULL_List)
	TEST (List_Is_Empty_No_Push)
	/*TEST (List_Is_Empty_After_Destroyed)*/
	TEST (List_Is_Empty_Normal)
END_SUITE	












