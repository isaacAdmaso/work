/**  Desctiption: Sorting Algorithems-	Bubble Sort
										Insertion Sort
										Shake Sort
										(Quick Sort)			  **/
#include "Sorting .h"
#include <stdio.h>
#include <stdlib.h>

#define IS_INVALID(V) (NULL == (V))
#define MINI  1

/*Bubble Sort - works by repeatedly stepping through the list to be sorted comparing each pair by a given function and swapping them if they are in the wrong order.*/
ADTErr BubbleSort (Vector* _vec, KeyCompare _func)
{
	size_t size;
	int i,j,swap,item,adjItem,error = ERR_OK;
	if(IS_INVALID(_vec))
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
	if(IS_INVALID(_vec))
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
	if(IS_INVALID(_vec))
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
/*	
static int PivFind(int _first,int _mid,int _last,int* _piv)
{
	int index ;
	*_piv = (first+last+mid)/3;
	if((first - *_piv) > (last - *_piv))
	{
		if((last - *_piv) > (mid - *_piv))
		{
			*_piv = mid;
			index = 0;
		}else
		{
			*_piv = last;
			index = 1;
		}
	}else
	{
		if((first-*_piv) > (mid-*_piv))
		{
			*_piv = mid;
			index = 0;
		}else
		{
			*_piv = first;
			index = -1;
		}
	}
	return index;
}
	switch(idxPiv){
		case -1:
			idxPiv = 0;
			break;
		case 0:
		 	idxPiv = (size-1)/2;
		 	break;
		default:
			idxPiv = size-1;
			break;
	}

*/




static void QuickSortHlper(Vector* _vec ,int left,int right, KeyCompare _func)
{
 	int valPiv,idxPiv,i=left,j=right-1,leftVal,rightVal;
	if(left < right)
	{
		idxPiv = right;
		VectorGet(_vec,idxPiv,&valPiv);		
		VectorGet(_vec,i,&leftVal);	
		VectorGet(_vec,j,&rightVal);	
		while(i < j)
		{
			while(_func(leftVal,valPiv) > 0)
			{
				++i;
				VectorGet(_vec,i,&leftVal);
				if(i == j) return;	
			}
			while(_func(valPiv,rightVal) > 0)
			{
				--j;
				VectorGet(_vec,j,&rightVal);
				if(i == j) return;		
			}
			
			VectorSet(_vec,j,leftVal);
			VectorSet(_vec,i,rightVal);
			--j;
			++i;
			VectorGet(_vec,i,&leftVal);
			VectorGet(_vec,j,&rightVal);
		}
		VectorGet(_vec,i+1,&leftVal);
		VectorSet(_vec,i+1,valPiv);
		VectorSet(_vec,idxPiv,leftVal);
		QuickSortHlper(_vec,0,i,_func);
		QuickSortHlper(_vec,i+2,right,_func);
	}
}	
		
	
	

/*Quick Sort recursively divides a large list into  smaller sub-lists and sorts the sub-lists*/
ADTErr QuickSort(Vector* _vec, KeyCompare _func)
{
	size_t size;
	int error = ERR_OK;
	if(IS_INVALID(_vec))
	{
		return ERR_NOT_INITIALIZED;
	} 
	error = VectorItemsNum(_vec ,&size);
	if(size <= MINI)
	{
		return error;
	}
	QuickSortHlper(_vec,0,size-1,_func);
	return ERR_OK;
}
		 




