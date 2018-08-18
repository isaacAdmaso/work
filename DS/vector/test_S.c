#include "Stack_API.h"
#include<stdlib.h>
#include<stdio.h>




void CheckCreateStackNormal()
{
	Stack* s;
	s=StackCreate(1,1);
	if(s != NULL)
	{
		printf("pass Create Normal \n");
	}else
	{
		
		printf("faild create Normal \n");
	}
	StackDestroy(s);
}
void CheckCreateStackZeIn()
{
	Stack* s = NULL;
	s = StackCreate(0,1);
	if(s!= NULL)
	{
		printf("pass Create ze-in \n");
	}else
	{
		
		printf("faild create ze-in \n");
	}
	StackDestroy(s);
}

void CheckCreateStackZeBk()
{
	Stack* s = NULL;
	s = StackCreate(1,0);
	if(s!= NULL)
	{
		printf("pass Create ze-bk\n");
	}else
	{
		
		printf("faild create ze-bk \n");
	}
	StackDestroy(s);
}

void CheckCreateStackZeBoth()
{
	Stack* s = NULL;
	s = StackCreate(0,0);
	if(s== NULL)
	{
		printf("pass Create ze-both\n");
	}else
	{
		
		printf("faild create ze-both \n");
	}
	StackDestroy(s);
}
Stack* StackHlpCreate(Stack* _s)
{
	int i;
	for(i=0;i<7;i+=2)
	{
		StackPush(_s,i);
	}
}
void ChackStackPushNurmal()
{
	int i;
	Stack* s=StackCreate(1,1);
	StackHlpCreate(s);
	StackPrint(s);
}

int CheckAddNullStack()
{
	Stack* s=NULL;
	int _itemCheck = 421188;
	if(StackPush(s,_itemCheck) == ERR_NOT_INITIALIZED)
	{
		return 0;
	}
	return 1;
}


/*
		
*/
int main(){
	CheckCreateStackNormal();
	CheckCreateStackZeIn();
	CheckCreateStackZeBk();
	CheckCreateStackZeBoth();
	ChackStackPushNurmal();
	printf("\n%d\n",CheckAddNullStack());
	return 0;
}
