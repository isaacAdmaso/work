/**  Desctiption: Sorting Algorithems-	Bubble Sort
										Insertion Sort
										Shake Sort
										(Quick Sort)			  **/
#ifndef __SORT_H__
#define __SORT_H__
#include "ADTDefs.h"



// Bubble Sort - works by repeatedly stepping through the list to be sorted,
// comparing each pair of adjacent items and swapping them if they are in the wrong order.
// Complexity: for sorted array - O(n). for random array - O(n^2).
ADTErr BubbleSort (int *_arr,unsigned int _size);



/*
//Shake Sort - The algorithm differs from bubble sort in that it sorts
//in both directions on each pass through the list.
//shaking sort is better than babble sort becouse of the option to move objects backwords.
//shake sort is 2 times better than bubble sort-
*/
ADTErr ShakeSort  (int *_arr,unsigned int _size);


/*Insertion Sort- a comparison sort in which the sorted array (or list) is built one entry at a time
*/
ADTErr InsertionSort (Vector* _vec, compFunc _func);



#endif // __SORT_H__

