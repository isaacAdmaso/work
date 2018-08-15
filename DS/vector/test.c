#include "ADTDefs.h"
#include "vector.h"
#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>


int main(){
	int error1=-1,item1=3,item2=9;
	size_t item3=0,item4=0,item5=0;
	Vector* v = VectorCreate(2,2);
	error1=VectorAdd(v,item1);
	printf("%d",error1);
	VectorPrint(v);
	error1=VectorDelete(v,&item1);
	printf("%d",error1);
	VectorPrint(v);
	error1=VectorAdd(v,item2);
	printf("%d",error1);
	error1=VectorGet(v,0,&item1);
	printf("%d",error1);
	printf("%d",VectorItemsNum(v,&item4));
	pritf("%d",VectorSet(v,0,error1));
	error1=VectorAdd(v,item1);
	VectorPrint(v);	
	VectorDestroy(v);
	return 0;
}
