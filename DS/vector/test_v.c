#include "ADTDefs.h"
#include "vector.h"
#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>


/****************************************CheckCreate*/

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


int CheckGetNUllVec()
{
	int _item;
	Vector* v = NULL;
	if(ERR_NOT_INITIALIZED==VectorGet(v, 0,&_item))
	{
		return 0;
	}
	return 1;
}


int CheckGetNUllItm()
{
	int* _item=0;
	Vector* v = VectorCreate(1,2);
	if(ERR_NOT_INITIALIZED==VectorGet(v, 0,_item))
	{
		VectorDestroy(v);
		return 0;
	}
	VectorDestroy(v);
	return 1;
}

int CheckGetGdInx()
{
	int _item;
	Vector* v = VectorCreate(1,1);
	VectorAdd(v,2);
	VectorGet(v,0,&_item);
	if(_item == 2)
	{
		VectorDestroy(v);
		return 0;
	}
	VectorDestroy(v);
	return 1;
}

int CheckGetBadInx()
{
	int _item;
	Vector* v = VectorCreate(1,1);
	VectorAdd(v,2);
	
	if(VectorGet(v,3,&_item)==ERR_WRONG_INDEX)
	{
		VectorDestroy(v);
		return 0;
	}
	VectorDestroy(v);	
	return 1;
}



int CheckVector(Vector* _v,int* ref,int _size)
{
	int i,val;
	
	for(i=0;i<_size;++i)
	{
		VectorGet(_v, i, &val);
		if(ref[i] != val)
		{
			VectorDestroy(_v);
			return 1;
		}
	}
	VectorDestroy(_v);	
	return 0;	
}


void FillVector(Vector* _v,int* ref,int _size)
{
	int i;
	
	for(i=0;i<_size;++i)
	{
		VectorAdd(_v,ref[i]);		
	}

}

int CheckAddNormal()
{
	int i;
	Vector* _v = VectorCreate(3,3);
	int  _itemCheck[]={654,6542};
	for(i=0;i<2;++i)
	{
		VectorAdd(_v,_itemCheck[i]);
	
	}
	return CheckVector(_v,_itemCheck,2);
}

int CheckAddNullVec()
{
	Vector* _v = NULL;
	int _itemCheck=654;
	if(VectorAdd(_v,_itemCheck)==ERR_NOT_INITIALIZED)
	{
		return 0;
	}
	return 1;
}

int CheckAddOvFl()
{
	Vector* _v = VectorCreate(1,0);
	int _itemCheck[]={654,6542};
	VectorAdd(_v,_itemCheck[0]);
	if (VectorAdd(_v,_itemCheck[1]) == ERR_OVERFLOW)
	{
	 	VectorDestroy(_v);
		return 0;
	}
	VectorDestroy(_v);	
	return 1;
}
	
int CheckAddAftrDstry()
{
	Vector* _v = VectorCreate(1,0);
	int _itemCheck[]={654,6542};
	VectorAdd(_v,_itemCheck[0]);
	VectorDestroy(_v);
	if (VectorAdd(_v,_itemCheck[1]) == ERR_NOT_INITIALIZED)
	{
		return 0;
	}
	return 1;
}

int CheckAddIniSizZero()
{
	Vector* _v = VectorCreate(0,1);
	int _itemCheck=654;
	if(VectorAdd(_v,_itemCheck)==ERR_OK)
	{
		VectorDestroy(_v);
		return 0;
	}
	VectorDestroy(_v);	
	return 1;
}



int CheckSetNUllVec()
{
	int _item=3;
	Vector* v = NULL;
	if(ERR_NOT_INITIALIZED==VectorSet(v, 0,_item))
	{
		return 0;
	}
	return 1;
}

int CheckSetGdInx()
{
	int _item=3;
	Vector* v = VectorCreate(1,1);
	VectorAdd(v,2);
	VectorSet(v,0,1);
	VectorGet(v,0,&_item);
	if(1 == _item)
	{
		VectorDestroy(v);
		return 0;
	}
	VectorDestroy(v);	
	return 1;
}

int CheckSetBadInx()
{
	int _item=3;
	Vector* v = VectorCreate(1,1);
	VectorAdd(v,2);
	
	if(VectorSet(v,3,_item)==ERR_WRONG_INDEX)
	{
		VectorDestroy(v);
		return 0;
	}
	VectorDestroy(v);
	return 1;
}


void CheckDelNrml()
{
	int i,_item;
	Vector* _v = VectorCreate(1,1);
	for(i=0;i<7;++i) VectorAdd(_v,i);
	VectorPrint(_v);
	for(i=0;i<7;++i)
	{
	VectorDelete(_v,&_item);
	printf("%d \n",_item); 
	}
	VectorPrint(_v);
	VectorDestroy(_v);
}


int CheckDelNUllVec()
{
	int _item;
	Vector* v = NULL;
	if(ERR_NOT_INITIALIZED==VectorDelete(v,&_item))
	{
		return 0;
	}
	return 1;
}

int CheckDelNUllItm()
{
	int _item;
	Vector* v = VectorCreate(1,2);
	if(ERR_NOT_INITIALIZED==VectorDelete(v, &_item))
	{
		VectorDestroy(v);
		return 0;
	}
	VectorDestroy(v);
	return 1;
}


int CheckDelUnFl()
{
	int _item;
	Vector* _v = VectorCreate(1,1);
	if (VectorDelete(_v,&_item) == ERR_UNDERFLOW)
	{
		VectorDestroy(_v);
		return 0;
	}
	VectorDestroy(_v);
	return 1;
}

void CheckAddOF()
{
	int val[]={3,54,-77,55,634,356,648,10,-10};
	Vector * vec = VectorCreate(4,0);
	FillVector(vec,val,9);
	CheckVector(vec,val,9);
		
}


int main()
{	
	CheckCreateNormal();
	printf("\n");
	CheckCreateZeIn();
	printf("\n");
	CheckCreateZeBk();
	printf("\n");
	CheckCreateZeBoth();
	printf("\n");
	printf("%d\n",CheckGetNUllVec());
	printf("%d\n",CheckGetNUllItm());
	printf("%d\n",CheckGetGdInx());
	printf("%d\n",CheckGetBadInx());
	printf("%d\n",CheckAddNormal());
	printf("%d\n",CheckAddNullVec());
	printf("%d\n",CheckAddOvFl());
	printf("%d\n",CheckAddAftrDstry());
	printf("%d\n",CheckAddIniSizZero());
	printf("%d\n",CheckSetNUllVec());
	printf("%d\n",CheckSetGdInx());
	printf("11111111%d\n",CheckSetBadInx());
	
	printf("%d\n",CheckDelNUllVec());
	printf("%d\n",CheckDelNUllItm());
	printf("%d\n",CheckDelUnFl());
	printf("9873289");
	CheckDelNrml();
	printf("\n");
	CheckAddOF();
	return 0;
}
