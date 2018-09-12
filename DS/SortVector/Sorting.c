/**  Desctiption: Sorting Algorithems-	Bubble Sort
										Insertion Sort
										Shake Sort
										(Quick Sort)			  **/
#include "Sorting.h"
#include <stdio.h>
#include <stdlib.h>

#define IS_INVALID(V) (NULL == (V))
#define MINI  1

/*Bubble Sort - works by repeatedly stepping through the list to be sorted comparing each pair by a given function and swapping them if they are in the wrong order.*/
ADTErr BubbleSort (Vector* _vec, KeyCompare _func)
{
	size_t size;
	int i,j,swap,item,adjItem,error = ERR_OK;
	if(IS_INVALID(_vec) || IS_INVALID(_func))
	{
		return ERR_NOT_INITIALIZED;
	} 
	error = VectorItemsNum(_vec ,&size);
	if(size <= MINI)
	{
		return error;
	}
	for(i = 0;i < size; ++i)
	{
		swap = 0;
		for(j = 0;j < size-i-1;++j)	
		{
			VectorGet(_vec,j,&item);
			VectorGet(_vec,j+1,&adjItem);
			if(_func(item,adjItem) > 0)
			{
				VectorSet(_vec,j,adjItem);
				VectorSet(_vec,j+1,item);
				swap = 1;
			}
		}
		/*No swap was needed alredy sorted*/
		if(swap == 0)
		{
			break;
		}
	}
	return ERR_OK;
}
/*Shake Sort  like Bubble only both ways*/
ADTErr ShakeSort(Vector* _vec, KeyCompare _func)
{
	size_t size;
	int i,j,swap,item,adjItem,error = ERR_OK;
	if(IS_INVALID(_func))
	{
		return ERR_NOT_INITIALIZED;
	} 
	error = VectorItemsNum(_vec ,&size);
	if(size <= MINI)
	{
		return error;
	}
	for(i = 1;i <= size/2; ++i)
	{
		swap = 0;
		for(j = i-1;j < size-i;++j)
		{
			VectorGet(_vec,j,&item);
			VectorGet(_vec,j+1,&adjItem);
			if(_func(item,adjItem) > 0)
			{
				VectorSet(_vec,j,adjItem);
				VectorSet(_vec,j+1,item);
				swap = 1;
			}
		}
		for(j = size-i-1;j >= i ;--j)
		{
			VectorGet(_vec,j,&item);
			VectorGet(_vec,j-1,&adjItem);
			if(_func(item,adjItem) < 0)
			{
				VectorSet(_vec,j,adjItem);
				VectorSet(_vec,j-1,item);
				swap = 1;
			}
		}
		/*No swap was needed alredy sorted*/
		if(swap == 0)
		{
			break;
		}
	}
	return ERR_OK;
}	

/*Insertion Sort- a comparison sort in which the sorted Vector is built one entry at a time
*/
ADTErr InsertionSort (Vector* _vec, KeyCompare _func)
{
	size_t size;
	int i,j,swapItem,item,error = ERR_OK;
	if(IS_INVALID(_func))
	{
		return ERR_NOT_INITIALIZED;
	} 
	error = VectorItemsNum(_vec ,&size);
	if(size <= MINI)
	{
		return error;
	}
	for(i=1;i<size;++i)
	{
		VectorGet(_vec,i,&item);
		j = i-1;
		VectorGet(_vec,j,&swapItem);
	/*Move elements bigger than val  */
		while (j >= 0 && (_func(swapItem ,item) > 0))
		{
			VectorSet(_vec,j+1,swapItem);
			--j;
			VectorGet(_vec,j,&swapItem);
		}
		VectorSet(_vec,j+1,item);
	}
	return ERR_OK;
}	
static size_t Qpart(Vector* _vec,size_t _start,size_t _end,KeyCompare _func)
{
	int i,j,pivIdx = _end;
	int pivVal = 0,smItm = 0,bgItm = 0;
	
	VectorGet(_vec,pivIdx,&pivVal);
	
	for(i = _start,j = _end-1;i < j; --j,++i)
	{
		VectorGet(_vec,i,&smItm);
		while(_func(smItm,pivVal) > 0 && i<j)
		{
			VectorGet(_vec,++i,&smItm);
		}
		VectorGet(_vec,j,&bgItm);
		while(_func(bgItm,pivVal) < 0 && j>i)
		{
			VectorGet(_vec,--j,&bgItm);
		}
		if(j > i)
		{
			VectorSet(_vec,i,bgItm);
			VectorSet(_vec,j,smItm);
		}
	}
	VectorGet(_vec,i,&smItm);
	VectorSet(_vec,pivIdx,smItm);
	VectorSet(_vec,i,pivVal);
	return i;
}


static void Qsort(Vector* _vec,size_t _start,size_t _end,KeyCompare _func)
{
	size_t midIdx;
	if(_end - _start >MINI )
	{
		midIdx = Qpart(_vec,_start,_end,_func);
		if(midIdx == _start)
		{
			Qsort(_vec,midIdx+1,_end,_func);
		}else if(midIdx == _end)
		{
			Qsort(_vec,_start,midIdx-1,_func);
		}else
		{
			Qsort(_vec,_start,midIdx-1,_func);
			Qsort(_vec,midIdx+1,_end,_func);
		}
		
	}
}
	

ADTErr QuickSort(Vector* _vec, KeyCompare _func)
{
	size_t size = 0;
	ADTErr error = ERR_OK;
	if(IS_INVALID(_vec) || IS_INVALID(_func))
	{
		return ERR_NOT_INITIALIZED;
	} 
	error = VectorItemsNum(_vec ,&size);
	if(size <= MINI)
	{
		return error;
	}
	Qsort(_vec,0,size - 1,_func);
	return ERR_OK;
}	
	






















 




