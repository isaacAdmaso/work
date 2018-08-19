#include "ADTDefs.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int values[] = {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30};

size_t SIZE = sizeof(values)/sizeof(values[0]);




/*-----------------------------------------------------------------------------------------------

									      Function
									      
------------------------------------------------------------------------------------------------*/


int checkVector(Vector* v, int* ref)
{
	size_t size;
	int value;
	int i;
	VectorItemsNum(v,&size);
	for(i=0; i<size; ++i)
	{
		if(VectorGet(v,i,&value) != ERR_OK || value != ref[i])
		{
			return 1;
		}
	}
	return 0;
}




int	FillVector(Vector* v, int values[], size_t _size)
{
	int i,count=0;
	for(i = 0; i<_size; ++i)
	{
		if (VectorAdd(v, values[i]) != ERR_OK)
		{
			return 1;
		}
	}
	return 0;
}	


/*-----------------------------------------------------------------------------------------------

									      Check Create
									      
------------------------------------------------------------------------------------------------*/


void CheakCreateNormal()
{
	Vector *v = NULL;
	v = VectorCreate(2, 4);
	if(v != NULL)
	{
		printf("CheakCreateNormal sucsses \n\n");
		return;
	}
	printf("CheakCreateNormal failed \n\n");

}




void CheakCreateInSize0()
{
	Vector *v = NULL;
	v = VectorCreate(0, 1);
	if(v != NULL)
	{
		printf("CheakCreateInSize0 sucsses \n\n");
		return;
	}
	printf("CheakCreateInSize0 failed \n\n");
}



void CheakCreateInSize0BlockSize0()
{
	Vector *v = NULL;
	v = VectorCreate(0, 0);
	if(v == NULL ) 
	{
		printf("CheakCreateInSize0BlockSize0 sucsses \n\n");
		return;
	}
	printf("CheakCreateInSize0BlockSize0 failed \n\n");
}



/*-----------------------------------------------------------------------------------------------

									      Check Add
									      
------------------------------------------------------------------------------------------------*/



void CheckAddNoNeedRealloc ()
{
	Vector *v = NULL;
	v = VectorCreate (10,5);
	if (FillVector (v,values,5) == 0 && checkVector(v,values) != 0)
	{
		printf("CheckAddNoNeedRealloc failed \n\n");	
		return;	
	}
	printf("CheckAddNoNeedRealloc sucsses \n\n");
}	
	
	



void CheckAddNULLVector()
{
	Vector *v = NULL;
	if(	VectorAdd(v,5) == ERR_NOT_INITIALIZED)
	{
		printf("CheckAddNULLVector : sucsses \n\n");
		return;
	}
	printf("CheckAddNULLVector failed \n\n");
}




void CheckAddAfterDesroy()
{
	Vector* v = NULL;
	v = VectorCreate (10,5);
	FillVector (v,values,5); 
	VectorDestroy(v);
	if(VectorAdd(v,5) == ERR_NOT_INITIALIZED)
	{
		printf("CheckAddAfterDesroy : sucsses  \n\n");
		return;
	}
	printf("CheckAddAfterDesroy : failed \n\n");
		
}



void CheckAddRealloc()
{
	Vector* v = NULL;
	v = VectorCreate (2,3);
	if(FillVector(v,values,4) == 0 && checkVector(v,values) == 0)
	{
		printf("CheckAddRealloc : sucsses \n\n");
		return;
	}
	printf("CheckAddRealloc : failed \n\n");
}



void CheckAddOverFlow()
{
	int i;
	Vector* v = NULL;
	v = VectorCreate (1,0);
	if(FillVector(v,values,5) != 0)
	{
		printf("CheckAddOverFlow : sucsses \n\n");
		return;
	}
	printf("CheckAddOverFlow : failed \n\n");
}




void CheckAddInitSize0 ()
{
	Vector* v = NULL;
	v = VectorCreate (0,1);
	if (FillVector(v,values,5) == 0)
	{
		printf("CheckAddInitSize0 sucsses \n\n");
		return; 
	}
	printf("CheckAddInitSize0 failed \n\n");
}

/*-----------------------------------------------------------------------------------------------

									      Check Get
									      
------------------------------------------------------------------------------------------------*/




void CheckGetNULLVector ()
{
	int x;
	Vector* v = NULL;
	if(	VectorGet(v,5,&x) == ERR_NOT_INITIALIZED)
	{
		printf("CheckGetNULLVector : sucsses \n\n");
		return;
	}
	printf("CheckGetNULLVector failed \n\n");
}






void CheckGetNULLItem ()
{
	int* x=NULL;
	Vector* v;  
	v = VectorCreate (5,1);
	if (FillVector(v,values,5) == 0 && VectorGet(v,5,x) == ERR_NOT_INITIALIZED)
	{
		printf("CheckGetNULLItem : sucsses  \n\n");
		return;
	}
	printf("CheckGetNULLItem : failed \n\n");
}


void CheckGetMAGIC()
{
	int *x;
	Vector* v = NULL;
	v = VectorCreate (5,5);
	FillVector(v,values,5);
	VectorDestroy(v);
	if (VectorGet(v,5,x) == ERR_NOT_INITIALIZED)
	{
		printf("CheckGetMAGIC sucsses : sucsses \n\n");
		return;
	}
	printf("CheckGetMAGIC : failed \n\n");
}



void CheckGetGoodIndex()
{
	int *x;
	Vector* v = NULL;
	v = VectorCreate (5,5);
	if(FillVector(v,values,SIZE) == 0 && VectorGet(v,SIZE/2,x) == ERR_OK)
	{
		printf("CheckGetGoodIndex sucsses : sucsses \n\n");
		return;
	}
	printf("CheckGetGoodIndex : failed \n\n");
}





void CheckGetBadIndex()
{
	int *x;
	Vector* v = NULL;
	v = VectorCreate (5,5);
	if(FillVector(v,values,SIZE) == 0 && VectorGet(v,2*SIZE,x) == ERR_WRONG_INDEX)
	{
		printf("CheckGetBadIndex : sucsses  \n\n");
		return;
	}
	printf("CheckGetBadIndex : failed \n\n");
}

/*-----------------------------------------------------------------------------------------------

									      Check Items Num
									      
------------------------------------------------------------------------------------------------*/



void checkVectorItemsNumNULLVector()
{
	size_t x;
	Vector* v = NULL;
	if(	VectorItemsNum(v,&x) == ERR_NOT_INITIALIZED)
	{
		printf("VectorItemsNumNULLVector : sucsses  \n\n");
		return;
	}
	printf("VectorItemsNumNULLVector :  failed \n\n");
}





void checkVectorItemsNumMAGIC()
{
	size_t x;
	Vector* v = NULL;
	v = VectorCreate (5,5);
	VectorDestroy(v);
	if(VectorItemsNum(v,&x) == ERR_NOT_INITIALIZED)
	{
		printf("VectorItemsNumMAGIC : sucsses \n\n");
		return;
	}
	printf("VectorItemsNumMAGIC : failed \n\n");		
}




void checkVectorItemsNumMAGICNULLItem ()
{
	size_t* x = NULL;
	Vector* v = VectorCreate (5,1);
	if(FillVector(v,values,SIZE) == 0 && VectorItemsNum(v,x) == ERR_NOT_INITIALIZED)
	{
		printf("VectorItemsNumMAGICNULLItem : sucsses  \n\n");
		return;
	}
	printf("VectorItemsNumMAGICNULLItem : failed \n\n");
}



void checkVectorItemsNumExeptedValue ()
{
	size_t x;
	Vector* v = VectorCreate (5,1);
	if(FillVector(v,values,SIZE) == 0 && VectorItemsNum(v,&x) == ERR_OK && x==SIZE )
	{
		printf("VectorItemsNumExeptedValue : sucsses\n\n");
		return;
	}
	printf("VectorItemsNumExeptedValue : failed \n\n");
}


/*-----------------------------------------------------------------------------------------------

									       Check Set
									       
----------------------------------------------------------------------------------------------*/




void checkVectorSetItemsNumNULLVector()
{
	size_t x;
	Vector* v = NULL;
	if(	VectorItemsNum(v,&x) == ERR_NOT_INITIALIZED)
	{
		printf("VectorItemsNumNULLVector : sucsses \n\n");
		return;
	}
	printf("VectorItemsNumNULLVector :  failed \n");
}





void CheckVectorSetMAGIC()
{
	Vector* v = NULL;
	v = VectorCreate (5,5);
	FillVector(v,values,SIZE);
	VectorDestroy(v);
	if (VectorSet(v,SIZE-5,10) == ERR_NOT_INITIALIZED)
	{
		printf("CheckVectorSetMAGIC : sucsses  \n\n");
		return;
	}
	printf("CheckVectorSetMAGIC : failed \n\n");
}



void CheckVectorSetGoodIndex()
{
	Vector* v = NULL;
	v = VectorCreate (5,5);
	if(FillVector(v,values,SIZE) == 0 && VectorSet(v,SIZE/2,10) == ERR_OK && checkVector(v,values) == 1)
	{
		printf("CheckVectorSetGoodIndex : sucsses  \n\n");
		return;
	}
	printf("CheckVectorSetGoodIndex : failed \n\n");
}




void CheckVectorSetBadIndex()
{
	Vector* v = NULL;
	v = VectorCreate (5,5);
	if(FillVector(v,values,SIZE) == 0 && VectorSet(v,2*SIZE,10) == ERR_WRONG_INDEX)
	{
		printf("CheckVectorSetBadIndex : sucsses  \n\n");
		return;
	}
	printf("CheckVectorSetBadIndex : failed \n\n");
}



/*-----------------------------------------------------------------------------------------------

									       Delete
									       
------------------------------------------------------------------------------------------------*/



void checkVectorDeleteNULLVector()
{
	int x;
	Vector* v = NULL;
	if(	VectorDelete(v,&x) == ERR_NOT_INITIALIZED)
	{
		printf("checkVectorDeleteNULLVector : sucsses \n\n");
		return;
	}
	printf("checkVectorDeleteNULLVector :  failed \n\n");
}




void CheckVectorDeleteNULLItem ()
{
	int* x=NULL;
	Vector* v;  
	v = VectorCreate (5,1);
	if (FillVector(v,values,SIZE) == 0 && VectorDelete(v,x) == ERR_NOT_INITIALIZED)
	{
		printf("CheckVectorDeleteNULLItem : sucsses \n\n");
		return;
	}
	printf("CheckVectorDeleteNULLItem : failed \n\n");
}


void CheckVectorDeleteMAGIC()
{
	int *x;
	Vector* v = NULL;
	v = VectorCreate (5,5);
	FillVector(v,values,SIZE);
	VectorDestroy(v);
	if (VectorDelete(v,x) == ERR_NOT_INITIALIZED)
	{
		printf("CheckVectorDeleteMAGIC : sucsses  \n\n");
		return;
	}
	printf("CheckVectorDeleteMAGIC : failed \n\n");
}


void CheckVectorDeleteUnderFlow()
{
	int *x;
	Vector* v = NULL;
	v = VectorCreate (1,0);
	if (VectorDelete(v,x) == ERR_UNDERFLOW)
	{
		printf("CheckVectorDeleteUnderFlow : sucsses \n\n");
		return;
	}
	printf("CheckVectorDeleteUnderFlow : failed \n\n");
}



void CheckVectorDeleteNItems()
{
	int x;
	size_t new_size;
	Vector* v = NULL;
	v = VectorCreate (5,5);
	if (FillVector(v,values,SIZE) == 0 && VectorDelete(v,&x) == ERR_OK && VectorItemsNum(v,&new_size) == ERR_OK && new_size==SIZE-1)
	{
		printf("CheckVectorDeleteNItems : sucsses  \n\n");
		return;
	}
	printf("CheckVectorDeleteNItems : failed \n\n");
}



void CheckVectorDeleteValues()
{
	Vector* v = NULL;
	int x;
	v = VectorCreate (5,5);
	FillVector(v,values,SIZE);
	if (VectorDelete(v,&x) == ERR_OK && x == values[SIZE-1])
	{
		printf("CheckVectorDeleteValues : sucsses \n\n");
		return;
	}
	printf("CheckVectorDeleteValues : failed \n\n");
}



void CheckVectorDeleteReallocUnderInitSize()
{
	size_t x;
	int i,y;
	Vector* v = NULL;
	v = VectorCreate (5,5);
	if (FillVector(v,values,SIZE) == 0)
			
	{
		for (i=0; i<SIZE; ++i)
		{
			if (VectorDelete(v,&y) != ERR_OK)
			{
				break;
			}
		}
		VectorItemsNum(v,&x);

		if (x == 0)
		{
			printf("CheckVectorDeleteReallocUnderInitSize : sucsses   \n\n");
			return;
		}
	}
	printf("CheckVectorDeleteReallocUnderInitSize : failed \n\n");
}




void CheckVectorDeleteReallocNormal()
{
	size_t x;
	int i,y;
	Vector* v = NULL;
	v = VectorCreate (2,5);
	if (FillVector(v,values,SIZE) == 0)
	{
		for (i=0; i<6; ++i)
		{
			if (VectorDelete(v,&y) != ERR_OK)
			{
				break;
			}
		}
		VectorItemsNum(v,&x);
		if (x == SIZE-6)
		{
			printf("CheckVectorDeleteReallocNormal : sucsses \n\n");
			return;
		}
	}
	printf("CheckVectorDeleteReallocNormal : failed \n\n");
}


int main()
{
	
	
	
	CheakCreateNormal();
	CheakCreateInSize0();
	CheakCreateInSize0BlockSize0();
	CheckAddNoNeedRealloc ();
	CheckAddNULLVector();
	CheckAddRealloc();
	CheckAddAfterDesroy();
	CheckAddRealloc();
	CheckAddOverFlow();
	CheckAddInitSize0 ();
	CheckGetNULLVector ();
	CheckGetNULLItem ();
	CheckGetMAGIC();
	CheckGetGoodIndex();
	checkVectorItemsNumNULLVector();
	checkVectorItemsNumMAGIC();
	checkVectorItemsNumMAGICNULLItem ();
	checkVectorItemsNumExeptedValue ();
	checkVectorSetItemsNumNULLVector();
	CheckVectorSetMAGIC();
	CheckVectorSetGoodIndex();
	CheckVectorSetBadIndex();
	checkVectorDeleteNULLVector();
	CheckVectorDeleteNULLItem ();
	CheckVectorDeleteMAGIC();
	CheckVectorDeleteUnderFlow();
	CheckVectorDeleteNItems();
	CheckVectorDeleteValues();
	CheckVectorDeleteReallocUnderInitSize();
	CheckVectorDeleteReallocNormal();
	
}









































