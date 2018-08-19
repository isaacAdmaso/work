#include "ADTDefs.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


int IsVectorContenOK(Vector* v, int* ref)
{
	int itemGet;
	size_t numItems;
	int i;
	VectorItemsNum(v, &numItems);
	
	for(i=0; i < numItems; ++i)
	{
		VectorGet(v, i, &itemGet);
		if(itemGet != ref[i])
		{
		return 1;
		}
	}
	return 0;
} 	


int	FillVector(Vector* v, int values[], size_t _size)
{
	int i;
	for(i = 0; i < _size; ++i)
	{
		if (VectorAdd(v, values[i]) != ERR_OK);
		return 1;
	}
	return 0;
}	

/**********************************
		CheakCreate
***********************************/

void CheakCreateNormal()
{
	Vector* v = NULL;
	v = VectorCreate(2, 4);
	if(v != NULL)
	{
		printf("PASSED: CheakCreateNormal\n");
	}
	else
	{
		printf("FAILED: CheakCreateNormal\n");
	}
}


void CheakCreateInSize0()
{
	Vector* v = NULL;
	
	v = VectorCreate(0, 1);
	if(v != NULL)
	{
		printf("PASSED: CheakCreateInSize0\n");
	}
	else
	{
		printf("FAILED: CheakCreateInSize0\n");
	}
}


void CheakCreateInBlock0()
{
	Vector* v = NULL;
	
	v = VectorCreate(1, 0);
	if(v != NULL)
	{
		printf("PASSED: CheakCreateInBlock0\n");
	}
	else
	{
		printf("FAILED: CheakCreateInBlock0\n");
	}
}


void CheakCreateInSize0BlockSize0()
{
	Vector* v = NULL;
	v = VectorCreate(0, 0);
	
	if(v == NULL)
	{
		printf("PASSED: CheakCreateInSize0BlockSize0\n");
	}
	else
	{
		printf("FAILED: CheakCreateInSize0BlockSize0\n");
	}
}


/**********************************
			CheakAdd
***********************************/

void CheakAddNormal()
{
	Vector* v = VectorCreate(2, 4);
	ADTErr statusErrorAdd  = VectorAdd(v, 2);
	
	if (statusErrorAdd == ERR_OK)
	{
		printf("PASSED: CheakAddNormal\n");
	}
	else
	{
		printf("FAILED: CheakAddNormal\n");
	}
}
	

void CheakAddNullVector()
{
	Vector* v = VectorCreate(0, 0);
	ADTErr statusErrorAdd = VectorAdd(v, 2);
	
	if (statusErrorAdd == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: CheakAddNullVector\n");
	}
	else
	{
		printf("FAILED: CheakAddNullVector\n");
	}
}


void CheakAddAfterDestroy()
{
	Vector* v = VectorCreate(2, 4);
	VectorDestroy(v);
	ADTErr statusErrorAdd = VectorAdd(v, 2);
	
	if (statusErrorAdd == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: CheakAddAfterDestroy\n");
	}
	else
	{
		printf("FAILED: CheakAddAfterDestroy\n");
	}
}


void CheakAddOverflow()
{
	int i,values[]= {3, 54, -77, 55, 634, 356, 648, 10, -10};
	Vector* vec = VectorCreate(4, 0);
	for(i=0;i<9;++i)
	{
		VectorAdd(vec,values[i]);
	}
	VectorPrint(vec);
	VectorDestroy(vec);
} 



void CheakAddRealloc()
{
	int i,values[]= {3, 54, -77, 55, 634, 356, 648, 10,99};
	Vector* vec = VectorCreate(4, 2);
	
	for(i=0;i<9;++i)
	{
		VectorAdd(vec,values[i]);
	}
	
	VectorPrint(vec);
}


void CheakAddInitSize0()
{
	int values[]= {3, 54, -77, 55, 634, 356, 648, 10,99};
	Vector* vec = VectorCreate(0, 2);
	
	FillVector(vec, values, sizeof(values)/sizeof(values[0]));
	
	if (IsVectorContenOK(vec, values) == 0 )
	{
		printf("PASSED: CheakAddInitSize0");
	}
	else
	{
	printf("FAILED: CheakAddInitSize0");
	}
}


/**********************************
			CheakGet
***********************************/

void CheakGetNullVector()
{
	int* item;
	
	Vector* v = VectorCreate(0, 0);
	ADTErr statusErrorGet = VectorGet(v, 2, item);
	
	if (statusErrorGet == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: CheakGetNullVector\n");
	}
	else
	{
		printf("FAILED: CheakAddNullVector\n");
	}
}

void CheakGetAfterDestroy()
{
	int* item;
	
	Vector* v = VectorCreate(2, 4);
	VectorDestroy(v);
	ADTErr statusErrorGet = VectorGet(v, 2, item);
	
	if (statusErrorGet == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: CheakGetAfterDestroy\n");
	}
	else
	{
		printf("FAILED: CheakGetAfterDestroy\n");
	}
}


void CheakGetNullItem()
{
	int* item = NULL;
	
	Vector* v = VectorCreate(2, 4);
	ADTErr statusErrorGet = VectorGet(v, 2, item);
	
	if (statusErrorGet == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: CheakGetNullItem\n");
	}
	else
	{
		printf("FAILED: CheakGetNullItem\n");
	}
}

void CheakGetGoodIndex()
{
	int* item;
	
	Vector* v = VectorCreate(2, 4);
	ADTErr statusErrorGet = VectorGet(v, 1, item);
	
	if (statusErrorGet != ERR_OK)
	{
		printf("FAILED: CheakGetGoodIndexError\n");
	}
	else
	{
		printf("PASSED: CheakGetGoodIndexError\n");
	}
	
		if (*item != 4)
	{
		printf("FAILED: CheakGetGoodIndexItemReturn\n");
	}
	else
	{
		printf("PASSED: CheakGetGoodIndexItemReturn\n");
	}
	
}


void CheakGetBadIndexBig()
{
	int* item;
	
	Vector* v = VectorCreate(2, 4);
	ADTErr statusErrorGet = VectorGet(v, 150, item);
	
	if (statusErrorGet != ERR_WRONG_INDEX)
	{
		printf("FAILED: CheakGetBedIndex\n");
	}
	else
	{
		printf("PASSED: CheakGetBedIndex\n");
	}
}


void CheakGetBadIndexNitems()
{
	int* item;
	Vector* v = VectorCreate(4, 2);
	int values[]= {3, 54, -77, 55, 634, 356, 648, 10};
	FillVector(v, values, sizeof(values)/sizeof(values[0]));
	ADTErr statusErrorGet = VectorGet(v, 8, item);
	
	if (statusErrorGet != ERR_WRONG_INDEX)
	{
		printf("FAILED: CheakGetBedIndexNitemsError\n");
	}
	else
	{
		printf("PASSED: CheakGetBedIndexNitemsError\n");
	}
}


/**********************************
			CheakNumOfItems
***********************************/


void CheakNOINullVector()
{
	size_t* _numOfItems;
	Vector* v = VectorCreate(0, 0);
	ADTErr CheakNOINullVector = VectorItemsNum(v, _numOfItems);
	
	if (CheakNOINullVector == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: CheakNOINullVector\n");
	}
	else
	{
		printf("FAILED: CheakNOINullVector\n");
	}
}

void CheakNOIDestroy()
{
	size_t _numOfItems;
	Vector* v = VectorCreate(2, 4);
	VectorDestroy(v);
	ADTErr CheakNOIDestroy = VectorItemsNum(v, &_numOfItems);
	
	if (CheakNOIDestroy == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: CheakNOIDestroy\n");
	}
	else
	{
		printf("FAILED: CheakNOIDestroy\n");
	}
}


void CheakNOIItem()
{
	size_t _numOfItems;
	Vector* v = VectorCreate(4, 2);
	int values[]= {3, 54, -77, 55, 634, 356, 648, 10};
	FillVector(v, values, sizeof(values)/sizeof(values[0]));
	ADTErr CheakNOIItem = VectorItemsNum(v, &_numOfItems);
	
	if ( _numOfItems == 8)
	{
		printf("PASSED: CheakNOIItem\n");
	}
	else
	{
		printf("FAILED: CheakNOIItem\n");
	}
}



/**********************************
			CheakSet
***********************************/

void CheakSetNullVector()
{
	int* item;
	
	Vector* v = VectorCreate(0, 0);
	ADTErr statusErrorSet = VectorGet(v, 2, item);
	
	if (statusErrorSet == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: CheakSetNullVector\n");
	}
	else
	{
		printf("FAILED: CheakSetNullVector\n");
	}
}

void CheakSetDestroy()
{
	int* item;
	
	Vector* v = VectorCreate(2, 4);
	ADTErr statusErrorSet = VectorGet(v, 2, item);
	VectorDestroy(v);
	
	if (statusErrorSet == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: CheakSetDestroy\n");
	}
	else
	{
		printf("FAILED: CheakSetDestroy\n");
	}
}


void CheakSetGoodIndex()
{
	int item = 999;
	Vector* v = VectorCreate(2, 4);
	VectorAdd(v, 10);
	VectorAdd(v, 20);
	ADTErr statusErrorSet = VectorSet(v, 1, item);
	
	if (statusErrorSet != ERR_OK)
	{
		printf("FAILED: CheakSetGoodIndexError\n");
	}
	else
	{
		printf("PASSED: CheakSetGoodIndexError\n");
	}
	
		if (statusErrorSet != 20)
	{
		printf("FAILED: CheakSetGoodIndexItemReturn\n");
	}
	else
	{
		printf("PASSED: CheakSetGoodIndexItemReturn\n");
	}
	
}


void CheakSetBadIndexBig()
{
	int* item;
	
	Vector* v = VectorCreate(2, 4);
	VectorAdd(v, 10);
	VectorAdd(v, 20);
	ADTErr statusErrorSet = VectorGet(v, 150, item);
	
	if (statusErrorSet != ERR_WRONG_INDEX)
	{
		printf("FAILED: CheakSetBedIndexBigError\n");
	}
	else
	{
		printf("PASSED: CheakSetBedIndexBigError\n");
	}
	
		if (statusErrorSet != 20)
	{
		printf("FAILED: CheakSetBedIndexBigItemReturn\n");
	}
	else
	{
		printf("PASSED: CheakSetBedIndexBigItemReturn\n");
	}
	
}

/**********************************
			CheakDelete
***********************************/



void CheakDeleteNullVector()
{
	int* item;
	
	Vector* v = VectorCreate(0, 0);
	ADTErr statusErrorDelete = VectorDelete(v, item);
	
	if (statusErrorDelete == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: CheakDeleteNullVector\n");
	}
	else
	{
		printf("FAILED: CheakDeleteNullVector\n");
	}
}

void CheakDeleteAfterDestroy()
{
	int* item;
	
	Vector* v = VectorCreate(2, 4);
	ADTErr statusErrorDelete = VectorGet(v, 2, item);
	VectorDestroy(v);
	
	if (statusErrorDelete == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: CheakDeleteAfterDestroy\n");
	}
	else
	{
		printf("FAILED: CheakDeleteAfterDestroy\n");
	}
}


void CheakDeleteNullItem()
{
	int* item = NULL;
	
	Vector* v = VectorCreate(2, 4);
	ADTErr statusErrorDelete = VectorGet(v, 2, item);
	
	if (statusErrorDelete == ERR_NOT_INITIALIZED)
	{
		printf("PASSED: CheakDeleteNullItem\n");
	}
	else
	{
		printf("FAILED: CheakDeleteNullItem\n");
	}
}

void CheakDeleteUnderfllow()
{
	int item;
	Vector* v = VectorCreate(2, 4);
	if (VectorDelete(v, &item) == ERR_UNDERFLOW)
	{
		printf("PASSED: CheakDeleteUnderfllow\n");
	}
	else
	{
		printf("FAILED: CheakDeleteUnderfllow\n");
	}
}



void CheakDeleteNItems()
{
	int item;
	int values[]= {3, 54, -77, 55, 634, 356, 648, 10};
	size_t numOfItems;
	Vector* v = VectorCreate(2, 4);
	
	FillVector(v, values, 8);
	VectorDelete(v, &item);
	VectorItemsNum(v, &numOfItems);
	
	if (numOfItems == 8)
	{
		printf("PASSED: CheakDeleteNItems\n");
	}
	else
	{
		printf("FAILED: CheakDeleteNItems\n");
	}
}


void CheakDeleteReallocNormal()
{
	int* item;
	int values[]= {3, 54, -77, 55, 634, 356, 648, 10}, i;
	size_t* numOfItems;
	Vector* v = VectorCreate(4, 2);
	FillVector(v, values, sizeof(values)/sizeof(values[0]));
	
	for(i=0; i<4; ++i)
	{
		VectorDelete(v, item);
	}
	VectorItemsNum(v, numOfItems);
	if(*numOfItems == 4)
	{
		printf("PASSED: CheakDeleteReallocNormal\n");
	}
	else
	{
		printf("FAILED: CheakDeleteReallocNormal\n");
	}	
}



void CheakDeleteReallocUnderInitSize()
{
	int* item;
	size_t* numOfItems;
	Vector* v = VectorCreate(4, 2);
	int values[]= {3, 54, -77, 55, 634, 356, 648, 10}, i;
	FillVector(v, values, sizeof(values)/sizeof(values[0]));
	
	for(i=0; i<6; ++i)
	{
		VectorDelete(v, item);
	}
	VectorItemsNum(v, numOfItems);
	if(*numOfItems == 2)
	{
		printf("PASSED: CheakDeleteReallocUnderInitSize\n");
	}
	else
	{
		printf("FAILED: CheakDeleteReallocUnderInitSize\n");
	}	
}


	
int main()
{
	CheakCreateNormal();
	CheakCreateInSize0();
	CheakCreateInBlock0();
	CheakCreateInSize0BlockSize0();
	CheakAddNormal();
	CheakAddNullVector();
	CheakAddAfterDestroy();
	CheakAddOverflow();
	CheakAddRealloc();
	CheakAddInitSize0();
	CheakGetNullVector();
	CheakGetAfterDestroy();
	CheakGetNullItem();
	CheakGetGoodIndex();
	CheakGetBadIndexBig();
	CheakGetBadIndexNitems();
	CheakNOINullVector();
	CheakNOIDestroy();
	CheakNOIItem();
	CheakSetNullVector();
	CheakSetDestroy();
	CheakSetGoodIndex();
	CheakSetBadIndexBig();
	CheakDeleteNullVector();
	CheakDeleteAfterDestroy();
	CheakDeleteNullItem();
	CheakDeleteUnderfllow();
	CheakDeleteNItems();
	CheakDeleteReallocNormal();
	CheakDeleteReallocUnderInitSize();
	
	return 0;
}
















