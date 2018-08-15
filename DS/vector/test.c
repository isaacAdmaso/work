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
	printf("8-%d",error1);
	printf("\n");
	VectorPrint(v);
	printf("\n");
	error1=VectorDelete(v,&item1);
	printf("7-%d\n",error1);
	VectorPrint(v);
	printf("\n");
	error1=VectorAdd(v,item2);
	printf("6-%d\n",error1);
	error1=VectorGet(v,0,&item1);
	printf("5-%d\n",error1);
	error1=VectorItemsNum(v,&item4);
	printf("4-%d\n",item4);
	printf("3-%d\n",VectorSet(v,1,error1));
	error1=VectorAdd(v,item1);
	VectorPrint(v);
	printf("2\n");	
	VectorDestroy(v);
	printf("1\n");

	return 0;
}
