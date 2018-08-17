#include "Stack_API.h"
#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>



void CheckCreateNormal()
{
	Stack* s;
	s=StackCreate(1,1);
	if(s != NULL)
	{
		printf("pass Create Normal ");
	}else
	{
		
		printf("faild create Normal ");
	}
	StackDestroy(s);
}
/*		
	
void CheckCreateNormal()
{
	Vector* v = NULL;
	v = VectorCreate(1,1);
	if(v!= NULL)
	{
		printf("pass Create Normal ");
	}else
	{
		
		printf("faild create Normal ");
	}
	VectorDestroy(v);
}

void CheckCreateZeIn()
{
	Vector* v = NULL;
	v = VectorCreate(0,1);
	if(v!= NULL)
	{
		printf("pass Create ze-in ");
	}else
	{
		
		printf("faild create ze-in ");
	}
	VectorDestroy(v);
}

void CheckCreateZeBk()
{
	Vector* v = NULL;
	v = VectorCreate(1,0);
	if(v!= NULL)
	{
		printf("pass Create ze-bk ");
	}else
	{
		
		printf("faild create ze-bk ");
	}
	VectorDestroy(v);
}

void CheckCreateZeBoth()
{
	Vector* v = NULL;
	v = VectorCreate(0,0);
	if(v== NULL)
	{
		printf("pass Create ze-both");
	}else
	{
		
		printf("faild create ze-both ");
	}
	VectorDestroy(v);
}

*/

