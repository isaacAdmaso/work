#include"person.h"


int Person_print(void* _itemt,void* _null)
{
	Person *_p = (Person*)_itemt;
	return printf("\n %ld, %d , %s\n",_p->id,_p->random,_p->animal);
}




int Person_cmp(void* _a,void* _b)
{
	Person *p1 = (Person*)_a ,*p2 = (Person*)_b;
    return p1->random > p2->random;
}

