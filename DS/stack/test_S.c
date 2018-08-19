#include "Stack.h"
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
void StackHlpCreate(Stack* _s)
{
	int i;
	for(i=0;i<20;i+=2)
	{
		StackPush(_s,i);
	}
}
void ChackStackPushNurmal()
{
	Stack* s=StackCreate(1,1);
	StackHlpCreate(s);
	StackPrint(s);
}

int CheckStackPushNullStack()
{
	Stack* s=NULL;
	int _itemCheck = 421188;
	if(StackPush(s,_itemCheck) == ERR_NOT_INITIALIZED)
	{
		return 0;
	}
	return 1;
}

int CheckStackPushOvFl()
{
	Stack* _s = StackCreate(1,0);
	int _itemCheck[]={654,6542};
	StackPush(_s,_itemCheck[0]);
	if (StackPush(_s,_itemCheck[1]) == ERR_OVERFLOW)
	{
		return 0;
	}
	return 1;
}

int CheckStackPushIniSizZero()
{
	Stack* _s = StackCreate(0,1);
	int _itemCheck=654;
	if(StackPush(_s,_itemCheck)==ERR_OK)
	{
		return 0;
	}
	return 1;
}


int CheckStackPushAftrDstry()
{
	Stack* _s = StackCreate(1,0);
	int _itemCheck[]={654,6542};
	StackPush(_s,_itemCheck[0]);
	StackDestroy(_s);
	if (StackPush(_s,_itemCheck[1]) == ERR_NOT_INITIALIZED)
	{
		return 0;
	}
	return 1;
}

void ChackStackPopNurmalAndUnFlo()
{
	int i,_item;
	Stack* s=StackCreate(1,1);
	StackHlpCreate(s);
	StackPrint(s);
	for(i=0;i<12;++i)
	{
		if(StackPop(s,&_item) == ERR_UNDERFLOW)
		{
			printf("ERR_UNDERFLOW\n");
			break;
		}
		printf("%d\n",_item);
		StackPrint(s);
		printf("\n");
	}
}	

int CheckStackPopNullStack()
{
	Stack* s=NULL;
	int _itemCheck;
	if(StackPop(s,&_itemCheck) == ERR_NOT_INITIALIZED)
	{
		return 0;
	}
	return 1;
}


int CheckStackPopIniSizZero()
{
	Stack* _s = StackCreate(0,1);
	int _itemCheckPop,_itemCheckPush=654;
	StackPush(_s,_itemCheckPush);
	StackPop(_s,&_itemCheckPop);
	if(_itemCheckPop==_itemCheckPush)
	{
		return 0;
	}
	return 1;
}


int CheckStackPopAftrDstry()
{
	Stack* _s = StackCreate(1,0);
	int _itemCheckout,_itemCheckin=4356;
	StackPush(_s,_itemCheckin);
	StackDestroy(_s);
	if (StackPop(_s,&_itemCheckout) == ERR_NOT_INITIALIZED)
	{
		return 0;
	}
	return 1;
}

void CheckStackIsEmptyNormal()
{
	Stack* _s = StackCreate(1,0);
	if (StackIsEmpty(_s))
	{
		printf("Stack is empty ok\n");
	}else
	{
		printf("Not ok!");
	}
}

void ChackStackIsEmptyNullStack()
{
	Stack* _s = StackCreate(0,0);/**same as _s==NULL*/
	if(StackIsEmpty(_s) == ERR_NOT_INITIALIZED)
	{
		printf("Stack is empty ok\n");
	}else
	{
		printf("Not ok!");
	}
}
	
void ChackStackTopNormalAndUnfl()
{
	int i,_item;
	Stack* s=StackCreate(1,1);
	StackHlpCreate(s);
	StackPrint(s);
	for(i=0;i<12;++i)
	{	
		if(StackTop(s,&_item)==ERR_UNDERFLOW)
		{
			printf("ERR_UNDERFLOW-ok\n");
			break;
		}
		StackTop(s,&_item);
		printf("item in top-%d\n",_item);
		StackPop(s,&_item);
		StackPrint(s);
	}
}	
	
int CheckStackTopNullStack()
{
	Stack* s=NULL;
	int _itemCheck;
	if(StackTop(s,&_itemCheck) == ERR_NOT_INITIALIZED)
	{
		return 0;
	}
	return 1;
}
	
int CheckStackTopIniSizZero()
{
	Stack* _s = StackCreate(0,1);
	int _itemCheckTop,_itemCheckPush=654;
	StackPush(_s,_itemCheckPush);
	StackTop(_s,&_itemCheckTop);
	if(_itemCheckTop==_itemCheckPush)
	{
		return 0;
	}
	return 1;
}


int CheckStackTopAftrDstry()
{
	Stack* _s = StackCreate(1,0);
	int _itemCheckout,_itemCheckin=4356;
	StackPush(_s,_itemCheckin);
	StackDestroy(_s);
	if (StackTop(_s,&_itemCheckout) == ERR_NOT_INITIALIZED)
	{
		return 0;
	}
	return 1;
}
	
		
		


int main(){
	CheckCreateStackNormal();
	CheckCreateStackZeIn();
	CheckCreateStackZeBk();
	CheckCreateStackZeBoth();
	ChackStackPushNurmal();
	printf("\n%d\n",CheckStackPushNullStack());
	printf("%d\n",CheckStackPushOvFl());
	printf("%d\n",CheckStackPushIniSizZero());
	printf("%d\n",CheckStackPushAftrDstry());
	ChackStackPopNurmalAndUnFlo();
	printf("%d\n",CheckStackPopNullStack());
	printf("%d\n",CheckStackPopIniSizZero());
	printf("%d\n",CheckStackPopAftrDstry());
	CheckStackIsEmptyNormal();
	ChackStackIsEmptyNullStack();
	ChackStackTopNormalAndUnfl();
	printf("%d\n",CheckStackTopNullStack());
	printf("%d\n",CheckStackTopIniSizZero());
	printf("%d\n",CheckStackTopAftrDstry());
	
	return 0;
}
