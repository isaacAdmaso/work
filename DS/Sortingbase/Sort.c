/**  Desctiption: Sorting Algorithems-	Bubble Sort
										Insertion Sort
										Shake Sort
										(Quick Sort)			  **/
#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>

#define IS_INVALID(A) (NULL == (A))
#define MINI  1

static void Swap(int* x,int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
	
/*Bubble Sort - works by repeatedly stepping through the list to be sorted comparing each pair and swapping them if they are in the wrong order.*/
ADTErr BubbleSort (int *_arr,unsigned int _size)
{
	int i,j,swap;
	
	if(IS_INVALID(_arr) || MINI >= _size )
	{
		return ERR_NOT_INITIALIZED;
	} 
	for(i = 0;i < _size; ++i)
	{
		swap = 0;
		for(j = 0;j < _size-i-1;++j)
		{
			if(_arr[j] > _arr[j+1])
			{
				Swap(_arr+j,_arr+j+1);
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
ADTErr ShakeSort  (int *_arr,unsigned int _size)
{
	int i,j,swap;
	
	if(IS_INVALID(_arr) || MINI >= _size )
	{
		return ERR_NOT_INITIALIZED;
	} 
	for(i = 1;i <= _size/2; ++i)
	{
		swap = 0;
		for(j = i-1;j < _size-i;++j)
		{
			if(_arr[j] > _arr[j+1])
			{
				Swap(_arr+j,_arr+j+1);
				swap = 1;
			}
		}
		for(j = _size-i-1;j >= i ;--j)
		{
			if(_arr[j]<_arr[j-1])
			{
				Swap(_arr+j,_arr+j-1);
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
	
/*Insertion Sort- a comparison sort in which the sorted array (or list) is built one entry at a time
*/
ADTErr InsertionSort (int *_arr,unsigned int _size)
{
	
	int i,j,val;
	if(IS_INVALID(_arr) || MINI >= _size )
	{
		return ERR_NOT_INITIALIZED;
	} 

	for(i=1;i<_size;++i)
	{
		val = _arr[i];
		j = i-1;
	/*Move elements bigger than val  */
		while (j >= 0 && _arr[j] > val)
		{
			_arr[j+1] = _arr[j];
			--j;
		}
		_arr[j+1] = val;
	}
	return ERR_OK;
}	

	
	
	
	
	
