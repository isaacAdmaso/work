#include "ADTDefs.h"
#include "vector.h"
#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>


int main(){
	int a;
	Vector* v = VectorCreate(2,2);
	if (v==NULL)
	{
		return 1;
	}
	for(int i =0;i<15;++i) VectorAdd(v,i);
	VectorGet(v,13,&a);
	printf("%d\n",a);
	VectorPrint(v);
	return 0;
}
