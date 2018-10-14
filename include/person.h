#ifndef __PERS_H_
#define __PERS_H_
/**
 * @file person.h
 * @brief function for debuging   
 * 
 * 
 */
#include "list_functions.h" /**for iteration tools  */

 
typedef struct Person
{
	size_t id;
	int random;
	char animal[32];
} Person;


int Person_print(void* _itemt,void* _null);
int IntCmp(void* _a,void* _b);
int IntEq(void* _a,void* _b);
int Person_Eq(void* _a,void* _b);
void Person_Free(void* _item);
int Person_cmp(void* _a,void* _b);
int Person_cmp2(void* _a,void* _b);
int IntPrt(void*_itm,void* null);
int StrPrt(void* _itm,void* _null);
void List_P(const List* _list,ListActionFunction _func);
int StrCmp(void* _a,void* _b);
int Person_Eq2(void* _a,void* _b);
int Person_print_Scd(void* _item);
int IntPrt_Scd(void* _item);
int Person_print_Scd2(void* _item);


extern Person people[100];


#endif /*__PERS_H_*/
