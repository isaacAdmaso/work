#include <stdlib.h>
#include <stdio.h>
#include "person.h"
#include "mu_test.h"
#include <string.h>
#include <time.h>

#define SIZE_ARR(A) sizeof(A)/sizeof(A[0]) 
#define SIZE_INT_ARR_TEST 100








void Arr_Int(int arr[SIZE_INT_ARR_TEST])
{
	int i;

	srand(time(0));

	for(i = 0; i < SIZE_INT_ARR_TEST;++i)
		arr[i] = rand()%SIZE_INT_ARR_TEST;
	
}



UNIT (list_create)
	List* list = NULL;
	int num  =  rand()%SIZE_INT_ARR_TEST;

	ASSERT_THAT((list = List_Create()) != NULL);
	List_Destroy(&list,NULL);
	ASSERT_THAT(List_PushHead(list,(void*)&num) == LIST_UNINITIALIZED_ERROR);
END_UNIT	 


UNIT (List_Push_Head_NULL)
	int num  =  rand()%SIZE_INT_ARR_TEST;

	ASSERT_THAT(List_PushHead(NULL,&num) == LIST_UNINITIALIZED_ERROR);
END_UNIT



UNIT (List_Push_Head_Normal)
	List* list = NULL;
	int num  =  rand()%SIZE_INT_ARR_TEST;

	ASSERT_THAT((list = List_Create()) != NULL);
	ASSERT_THAT(List_PushHead(list,&num) == LIST_SUCCESS); 
	List_Destroy(&list,NULL);
END_UNIT	 


UNIT (List_Push_Tail_NULL)
	int num  =  rand()%SIZE_INT_ARR_TEST;

	ASSERT_THAT(List_PushTail(NULL,&num) == LIST_UNINITIALIZED_ERROR);
END_UNIT



UNIT (List_Push_Tail_Normal)
	List* list = NULL;
	int num  =  rand()%SIZE_INT_ARR_TEST;

	ASSERT_THAT((list = List_Create()) != NULL); 
	ASSERT_THAT(List_PushTail(list,&num) == LIST_SUCCESS);
	List_Destroy(&list,NULL);
END_UNIT




UNIT (List_Pop_Push)
	int *arr1 ,*arr0,arr[] = {13,2};
	List* list = List_Create();

	
	arr1 = &arr[1];
	arr0 = &arr[0];
	ASSERT_THAT(List_PopHead(list,NULL) == LIST_UNINITIALIZED_ERROR);
	ASSERT_THAT(List_PushTail(list,arr) == LIST_SUCCESS);
	ASSERT_THAT(List_PushHead(list,arr+1) ==  LIST_SUCCESS);
	ASSERT_THAT(List_PopHead(list,(void**)&arr0) == LIST_SUCCESS);
	ASSERT_THAT(List_PopTail(list,(void**)&arr1) == LIST_SUCCESS);
	ASSERT_THAT(*arr0 == arr[1]);
	ASSERT_THAT(*arr1== arr[0]);
	ASSERT_THAT(List_Size(list) == 0 );
	List_Destroy(&list,NULL);
END_UNIT


UNIT (List_sort_Unique_int)

	int i,num,chkNum = 12092,chkNum2 = -12345,arr[SIZE_INT_ARR_TEST],ntRndArr[SIZE_INT_ARR_TEST];
	int *check = &chkNum , *check2 = &chkNum2;
	ListItr start = NULL,end = NULL,checkItr =NULL;
	List *lstRnd = NULL,*lst = NULL,*l = NULL;

	lstRnd = List_Create();
	lst = List_Create(); 
	ASSERT_THAT(NULL != lstRnd && NULL != lst);
	Arr_Int(arr);
	for(i = 0;i < SIZE_ARR(arr);++i)
	{
		ASSERT_THAT(List_PushTail(lstRnd,arr+i) == LIST_SUCCESS);
		
		ntRndArr[i] = i;
		ASSERT_THAT(List_PushTail(lst,ntRndArr+i) == LIST_SUCCESS);
	}
	start = ListItr_Begin(lst);
	num =  List_Size(lst);
	for(i = 0; i < num;++i)
	{
		ASSERT_THAT(List_PushTail(lstRnd,arr+i) == LIST_SUCCESS);

		check = ListItr_Get(start);
		start  = ListItr_Next(start);
		ASSERT_THAT(*check == ntRndArr[i]);		
	}
	ASSERT_THAT(List_Size(lst) == SIZE_ARR(ntRndArr));		

	
	start = ListItr_Begin(lstRnd);
	end  = ListItr_End(lstRnd);
	ListItr_Sort(start,end,IntCmp);
	
	start = ListItr_Begin(lstRnd);
	end  = ListItr_End(lstRnd);
	num =  List_Size(lstRnd);
	for(i = 0; i < num/2;++i)
	{

		check = ListItr_Get(start);
		start  = ListItr_Next(start);
		end = ListItr_Prev(end);
		check2 = ListItr_Get(end);
		ASSERT_THAT(*check <= *check2 );
	}

	
	chkNum = rand()%SIZE_INT_ARR_TEST;
	start = ListItr_Begin(lst);
	end  = ListItr_End(lst);
	checkItr = ListItr_FindFirst(start,end,IntEq,(void*)&chkNum);
	while(!ListItr_Equals(start,checkItr))
	{
		check = ListItr_Get(start);
		ASSERT_THAT(*check <= chkNum);
		start = ListItr_Next(start);
	}
	

	start = ListItr_Begin(lstRnd);
	end  = ListItr_End(lstRnd);
	chkNum = List_Size(lstRnd);
	l = ListItr_Unique(start,end,IntEq);
	ASSERT_THAT( l != NULL);
	ASSERT_THAT(chkNum == (List_Size(l) + List_Size(lstRnd)));
	start = ListItr_Begin(lstRnd);
	checkItr = ListItr_Next(start);
	end  = ListItr_End(lstRnd);
	while(!ListItr_Equals(checkItr,end))
	{
		check = ListItr_Get(start);
		check2 = ListItr_Get(checkItr);
		ASSERT_THAT(*check < *check2);
		start = checkItr;
		checkItr = ListItr_Next(checkItr);
	}
	List_Destroy(&lstRnd, NULL);
	List_Destroy(&lst,NULL);
	List_Destroy(&l,NULL);
END_UNIT
	
UNIT (List_int_Cut_FindFirst)
	size_t szLst = 0;
	int i,chkNum ,arr[SIZE_INT_ARR_TEST],ntRndArr[SIZE_INT_ARR_TEST];
	ListItr start = NULL,end = NULL,checkItr =NULL;
	List *srtLst = NULL,*l = NULL;

	l = List_Create();
	srtLst = List_Create();

	Arr_Int(arr);
	for(i = 0;i < SIZE_ARR(arr);++i)
	{
		ntRndArr[i] = i;
		ASSERT_THAT(List_PushTail(srtLst,ntRndArr+i) == LIST_SUCCESS);
	}
	chkNum = SIZE_INT_ARR_TEST/2;
	start = ListItr_Begin(srtLst);
	end  = ListItr_End(srtLst);
	szLst = List_Size(srtLst);
	checkItr = ListItr_FindFirst(start,end,IntEq,(void*)&chkNum);
	ASSERT_THAT(IntEq((void*)&chkNum,ListItr_Get(checkItr)));
	l = ListItr_Cut(start, checkItr);
	ASSERT_THAT(List_Size(l) > 0 && szLst == List_Size(l)+List_Size(srtLst));
	List_Destroy(&l, NULL);
	List_Destroy(&srtLst, NULL);


END_UNIT


UNIT (List_int_Splice)
	size_t szLst = 0;
	int i,arr[SIZE_INT_ARR_TEST],ntRndArr[SIZE_INT_ARR_TEST];
	ListItr start = NULL,end = NULL,checkItr =NULL,start1 = NULL,end1 = NULL;
	List *rndLst = NULL,*noRndLst = NULL,*l = NULL;

	l = List_Create();
	noRndLst = List_Create();
	rndLst = List_Create();

	Arr_Int(arr);
	for(i = 0;i < SIZE_ARR(arr);++i)
	{
		ASSERT_THAT(List_PushTail(rndLst,arr+i) == LIST_SUCCESS);
		
		ntRndArr[i] = i;
		ASSERT_THAT(List_PushTail(noRndLst,ntRndArr+i) == LIST_SUCCESS);
	}

	start = ListItr_Begin(rndLst);
	end  = ListItr_End(rndLst);
	start1 = ListItr_Begin(noRndLst);
	end1 = ListItr_End(noRndLst);
	szLst = List_Size(rndLst) +List_Size(noRndLst);
	
	checkItr = ListItr_Begin(l);
	checkItr = ListItr_Splice(checkItr,start,end);
	checkItr = ListItr_Splice(checkItr,start1,end1);

	ASSERT_THAT(List_Size(l) == szLst);
	ASSERT_THAT(List_Size(rndLst) == 0 && List_Size(noRndLst) == 0);
	List_Destroy(&l,NULL);
	List_Destroy(&rndLst,NULL);
	List_Destroy(&noRndLst,NULL);
	

END_UNIT

UNIT (List_int_merge)
	size_t szLst = 0;
	int i,chkNum = 12092,chkNum2 = -12345,arr[SIZE_INT_ARR_TEST],ntRndArr[SIZE_INT_ARR_TEST];
	int *check = &chkNum , *check2 = &chkNum2;
	ListItr start = NULL,end = NULL,checkItr =NULL,start1 = NULL,end1 = NULL;
	List *rndLst = NULL,*noRndLst = NULL,*l = NULL;

	l = List_Create();
	noRndLst = List_Create();
	rndLst = List_Create();

	Arr_Int(arr);
	for(i = 0;i < SIZE_ARR(arr);++i)
	{
		ASSERT_THAT(List_PushTail(rndLst,arr+i) == LIST_SUCCESS);
		
		ntRndArr[i] = i;
		ASSERT_THAT(List_PushTail(noRndLst,ntRndArr+i) == LIST_SUCCESS);
	}

	start = ListItr_Begin(rndLst);
	end  = ListItr_End(rndLst);
	start1 = ListItr_Begin(noRndLst);
	end1 = ListItr_End(noRndLst);

	ListItr_Sort(start,end,IntCmp);
	ListItr_Sort(start1,end1,IntCmp);
	
	szLst = List_Size(rndLst) +List_Size(noRndLst);
	start = ListItr_Begin(rndLst);
	end  = ListItr_End(rndLst);
	start1 = ListItr_Begin(noRndLst);
	end1 = ListItr_End(noRndLst);
	checkItr = ListItr_Begin(l);

	
	checkItr = ListItr_Merge(checkItr,start,end,start1,end1,IntCmp);
	
	ASSERT_THAT(List_Size(l) == szLst);
	
	
	for(i = 1; i < szLst-1;++i)
	{
		check = ListItr_Get(checkItr);
		start  = ListItr_Next(checkItr);
		check2 = ListItr_Get(checkItr);
		ASSERT_THAT(*check <= *check2);		
	}
	List_Destroy(&l, NULL);
	List_Destroy(&rndLst, NULL);
	List_Destroy(&noRndLst, NULL);


END_UNIT
/*

*/

UNIT (List_Size_check)
	int num,num1,*ptr1,*ptr;
	List* list = NULL;
	
	num = 3;
	num1 = 4;
	ptr = &num;
	ptr1 = &num1;
	ASSERT_THAT(List_PushTail(list,ptr1) == LIST_UNINITIALIZED_ERROR);
	ASSERT_THAT(List_Size(list) == 0);
	list = List_Create();
	ASSERT_THAT(List_PushHead(list,ptr)  == LIST_SUCCESS);
	List_PushTail(list,ptr1);
	List_PushTail(list,ptr);
	ASSERT_THAT(List_Size(list) == 3);
	List_Destroy(&list, NULL);

END_UNIT


UNIT (List_W_string)

	int i;
	char* item;
	char* str2[] = {"shoshan", "almia","lets","try","merge","cut"};
	char* str[] = {"yitshak","admaso","i am","late","shoshi"};
	List *list = NULL,*lst2 = NULL,*l = NULL;
	ListItr checkItr = NULL ,start,end,start1,end1;

	ASSERT_THAT((list = List_Create()) != NULL);

	ASSERT_THAT(List_PushHead(list,NULL) == LIST_UNINITIALIZED_ERROR);
	ASSERT_THAT(List_PushTail(lst2,str2[0]) == LIST_UNINITIALIZED_ERROR);
	lst2 = List_Create();
	ASSERT_THAT(NULL != lst2);
	for(i = 0;i < SIZE_ARR(str);++i)
	{
		ASSERT_THAT(List_PushTail(list,str[i]) == LIST_SUCCESS);

	}
	for(i = 0;i < SIZE_ARR(str2);++i)
	{
		ASSERT_THAT(List_PushTail(lst2,str2[i]) == LIST_SUCCESS);

	}
	ASSERT_THAT(List_Size(list) == SIZE_ARR(str));
	ASSERT_THAT(List_PopHead(list,(void**)&item) == LIST_SUCCESS);
	ASSERT_THAT(strcmp(item,str[0]) == 0);/**strcmp return 0 when equal  */
	ASSERT_THAT(List_PopTail(list,(void**)&item) == LIST_SUCCESS);
	ASSERT_THAT(strcmp(item,str[SIZE_ARR(str)-1]) == 0);
	ASSERT_THAT(item == str[SIZE_ARR(str)-1]);
	ASSERT_THAT(List_Size(list) == SIZE_ARR(str) - 2);
	checkItr = ListItr_Begin(list);
	ASSERT_THAT(item != ListItr_Set(checkItr,item));
	l = List_Create();

	start = ListItr_Begin(list);
	end  = ListItr_End(list);
	start1 = ListItr_Begin(lst2);
	end1 = ListItr_End(lst2);

	ListItr_Sort(start,end,StrCmp);
	ListItr_Sort(start1,end1,StrCmp);

	start = ListItr_Begin(list);
	end  = ListItr_End(list);
	start1 = ListItr_Begin(lst2);
	end1 = ListItr_End(lst2);
	checkItr = ListItr_Begin(l);
	checkItr = ListItr_Merge(checkItr,start,end,start1,end1,StrCmp);

	List_Destroy(&list, NULL);
	List_Destroy(&lst2,NULL);
	
	List_P(list, StrPrt);
	List_P(lst2, StrPrt);
	List_P(l, StrPrt);
	List_Destroy(&l, NULL);
	
END_UNIT



UNIT (List_W_struct)

	int i;
	List *list = NULL,*l1 = NULL,*l2 = NULL;
	ListItr start = NULL,end = NULL,start1 = NULL,end1 = NULL,start2 = NULL;
	void* item = NULL;
	Person p = {50, 409572, "Crane, sarus"};

	ASSERT_THAT((list = List_Create()) != NULL);
	ASSERT_THAT(List_PushTail(list,NULL) == LIST_UNINITIALIZED_ERROR);
	for(i = 0;i < SIZE_ARR(people);++i)
		ASSERT_THAT(List_PushTail(list,people+i) == LIST_SUCCESS);
	ASSERT_THAT(List_Size(list) == SIZE_ARR(people));
	for(i = 0;i < SIZE_ARR(people);++i)
		ASSERT_THAT(List_PushTail(list,people+i) == LIST_SUCCESS);
	start = ListItr_Begin(list);
	end  = ListItr_End(list);
	ListItr_Sort(start,end,Person_cmp2);
	l1 = List_Create();
	start = ListItr_Begin(list);
	end  = ListItr_End(list);
	l1 = ListItr_Unique(start,end,Person_Eq);
	start = ListItr_Begin(list);
	end  = ListItr_End(list);
	start1 = ListItr_Begin(l1);
	end1  = ListItr_End(l1);

	l2 = List_Create();
	start2 = ListItr_Merge(ListItr_Begin(l2),start,end,start1,end1,Person_cmp2);
	start = ListItr_Begin(l2);
	end  = ListItr_End(l2);
	
	ASSERT_THAT(ListItr_CountIf(start,end,Person_Eq,&p) == 2);


	start = ListItr_Begin(l2);
	end  = ListItr_End(l2);
	start2 = ListItr_FindFirst(start,end,Person_cmp2,(void*)&p);
	list = ListItr_Cut(start2, end);
	List_P(l2,Person_print);
	List_P(list,Person_print);

	item = ListItr_Remove(start2);
	Person_print(item,NULL);
	List_Destroy(&list,NULL);
	List_Destroy(&l1,NULL);
	List_Destroy(&l2,NULL);
	List_P(l1,Person_print);

END_UNIT


TEST_SUITE(list tester)

	TEST(list_create)
	TEST(List_Push_Head_NULL)
	TEST(List_Push_Head_Normal)
	TEST(List_Push_Tail_NULL)
	TEST(List_Push_Tail_Normal)
	TEST(List_Pop_Push)
	TEST(List_int_Splice)
	TEST(List_int_merge)
	TEST (List_Size_check)
	TEST(List_sort_Unique_int)
	TEST(List_W_string) 
	TEST(List_W_struct)
END_SUITE	












