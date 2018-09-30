#include"person.h"


int Person_print(void* _itemt,void* _null)
{
	Person *_p = (Person*)_itemt;
	return printf("\n %ld, %d , %s\n",_p->id,_p->random,_p->animal);
}




int Person_cmp(void* _a,void* _b)
{
	Person *p1 = (Person*)_a ,*p2 = (Person*)_b;
    return p1->random < p2->random;
}

int Person_Eq(void* _a,void* _b)
{
	Person *p1 = (Person*)_a ,*p2 = (Person*)_b;
    return p1->random == p2->random;
}

int IntPrt(void*_itm,void* null)
{
	int* num = (int*)_itm;
	return printf("%d ,",*num);
}

int IntCmp(void* _a,void* _b)
{
	int *num1 = (int*)_a,*num2 = (int*)_b;
	return *num1 < *num2; 
}

int IntEq(void* _a,void* _b)
{
	int *num1 = (int*)_a,*num2 = (int*)_b;
	return *num1 == *num2; 
}

int StrPrt(void* _itm,void* _null)
{
	char* s = (char*)_itm;
	return printf(" %s ,",s);
}


