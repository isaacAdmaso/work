#ifndef __PERS_H_
#define __PERS_H_
#include<stdlib.h>
#include <stdio.h>
 
typedef struct Person
{
	size_t id;
	int random;
	char animal[32];
} Person;

int Person_print(void* _itemt,void* _null);
int Person_cmp(void* _a,void* _b);
int IntCmp(void* _a,void* _b);
int IntEq(void* _a,void* _b);
int Person_Eq(void* _a,void* _b);








#endif /*__PERS_H_*/
