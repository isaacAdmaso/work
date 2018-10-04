#include "Vector.h"
#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include "mu_test.h"

#define SIZE_ARR(A) sizeof(A)/sizeof(A[0]) 

UNIT(Vector_create_normal)
	Vector* vec = NULL;
	int *item;
	ASSERT_THAT((vec= Vector_Create(2,0)) != NULL);
	ASSERT_THAT(Vector_Remove(vec,(void**)&item) == VECTOR_UNDERFLOW);
END_UNIT

UNIT(vector_append_null)
	Vector* vec = NULL;
	ASSERT_THAT((vec= Vector_Create(1,1)) != NULL);
	ASSERT_THAT(Vector_Append(vec,NULL) == VECTOR_UNINITIALIZED_ERROR);
	
END_UNIT

UNIT(vector_append_normal)
	Vector* vec = NULL;
	int *item ;
	int i;
	int arr[] = {1,2,3,4,54,5,6321,321,54};
	ASSERT_THAT((vec= Vector_Create(SIZE_ARR(arr),0)) != NULL);
	ASSERT_THAT(Vector_Append(vec,NULL) == VECTOR_UNINITIALIZED_ERROR);

	for(i = 0;i < SIZE_ARR(arr);++i)
		ASSERT_THAT(Vector_Append(vec,arr+i) == VECTOR_SUCCESS);

	ASSERT_THAT(Vector_Append(vec,arr+6) == VECTOR_OVERFLOW);
	ASSERT_THAT(Vector_Size(vec) == SIZE_ARR(arr));
	ASSERT_THAT(Vector_Capacity(vec) == SIZE_ARR(arr));
	ASSERT_THAT(Vector_Remove(vec,(void**)&item) == VECTOR_SUCCESS);
	printf("%d , %d",*item,arr[SIZE_ARR(arr)-1]);
	ASSERT_THAT(*item == arr[SIZE_ARR(arr)-1]);
	ASSERT_THAT(Vector_Size(vec) == SIZE_ARR(arr)-1);
	ASSERT_THAT(Vector_Set(vec,0,(void*)item)== VECTOR_SUCCESS);
	ASSERT_THAT(Vector_Get(vec,0,(void**)&item) == VECTOR_SUCCESS);
	printf("%d, %d",*item,arr[0]);
	for(i = 0;i < SIZE_ARR(arr)-1;++i)
		ASSERT_THAT(Vector_Get(vec,i,(void**)&item) == VECTOR_SUCCESS);
	
END_UNIT


UNIT(vector_append_string)
	Vector* vec = NULL;
	int i;
	char* item;
	char* str[] = {"yitshak","admaaso","i am","late","shoshi"};

	ASSERT_THAT((vec= Vector_Create(SIZE_ARR(str),0)) != NULL);
	ASSERT_THAT(Vector_Append(vec,NULL) == VECTOR_UNINITIALIZED_ERROR);

	for(i = 0;i < SIZE_ARR(str);++i)
		ASSERT_THAT(Vector_Append(vec,str[i]) == VECTOR_SUCCESS);

	ASSERT_THAT(Vector_Append(vec,str+6) == VECTOR_OVERFLOW);
	ASSERT_THAT(Vector_Size(vec) == SIZE_ARR(str));
	ASSERT_THAT(Vector_Capacity(vec) == SIZE_ARR(str));
	ASSERT_THAT(Vector_Remove(vec,(void**)&item) == VECTOR_SUCCESS);
	printf("\n%s , \n%s",item,str[SIZE_ARR(str)-1]);
	ASSERT_THAT(item == str[SIZE_ARR(str)-1]);
	printf("\n%s , %s\n",item,str[SIZE_ARR(str)-1]);
	ASSERT_THAT(Vector_Size(vec) == SIZE_ARR(str)-1);
	ASSERT_THAT(Vector_Set(vec,0,item)== VECTOR_SUCCESS);
	ASSERT_THAT(Vector_Get(vec,0,(void**)&item) == VECTOR_SUCCESS);
	printf("\n%s , %s\n",item,str[0]);
	for(i = 0;i < SIZE_ARR(str)-1;++i)
		ASSERT_THAT(Vector_Get(vec,i,(void**)&item) == VECTOR_SUCCESS);
END_UNIT
/*
UNIT(vector_append_struct)
	Vector* vec = NULL;
	int i;
	Person  p = {666,101,"lion"} ;
	Person *_p = &p;
	
	ASSERT_THAT((vec= Vector_Create(SIZE_ARR(people),0)) != NULL);
	ASSERT_THAT(Vector_Append(vec,NULL) == VECTOR_UNINITIALIZED_ERROR);

	for(i = 0;i < SIZE_ARR(people);++i)
		ASSERT_THAT(Vector_Append(vec,people+i) == VECTOR_SUCCESS);

	ASSERT_THAT(Vector_Append(vec,&p) == VECTOR_OVERFLOW);
	ASSERT_THAT(Vector_Size(vec) == SIZE_ARR(people));
	ASSERT_THAT(Vector_Capacity(vec) == SIZE_ARR(people));
	Person_print(_p,NULL);
	Person_print(&p,NULL);

	ASSERT_THAT(Vector_Remove(vec,(void**)(&_p)) == VECTOR_SUCCESS);
	Person_print(_p,NULL);
	Person_print(&p,NULL);

	Person_print(people+SIZE_ARR(people)-1,NULL);
	ASSERT_THAT(Vector_Size(vec) == SIZE_ARR(people)-1);
	ASSERT_THAT(Vector_Set(vec,0,&p)== VECTOR_SUCCESS);
	ASSERT_THAT(Vector_Get(vec,0,(void**)&_p) == VECTOR_SUCCESS);
	Person_print(_p,NULL);

	for(i = 0;i <10;++i)
	{
		ASSERT_THAT(Vector_Get(vec,i,(void**)&_p) == VECTOR_SUCCESS);
		Person_print(_p,NULL);
	}
END_UNIT
*/
/*
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

	TEST(Vector_create_normal)
	TEST(vector_append_null)
	TEST(vector_append_normal)
	TEST(vector_append_string)
	/*
	TEST(vector_append_struct)
	TEST(tree_found_normal)*/
	
END_SUITE
