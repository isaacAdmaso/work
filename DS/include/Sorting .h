/** @file Sorting.h
 *  @brief Vector Sorting
 *
 *  @author Alex Katz 2/7/2018 - API cleanup from previous work
 *
 *  @bug No known bugs.
 */
#ifndef __SORTING_H__
#define __SORTING_H__

#include "vector.h"
#include "ADTDefs.h"
/* Comparator of data to make algorithm agnositic to acsending/descending order */
typedef int (*KeyCompare)(int _1val, int _2val);

/**
 * @brief Bubble Sort
 * 		works by repeatedly stepping through the list to be sorted,
 * 		comparing each pair of adjacent items and swapping them if they are in the wrong order.
 * Complexity: for sorted array - O(n). for random array - O(n^2).
 * @param[in-out]	_vector: to be sorted
 * @param[in]		_compFunc: key comparator
 * @return ERR_OK on success
 */
ADTErr BubbleSort (Vector* _vec, KeyCompare _func);

/**
 * @brief Shake Sort
 * 		The algorithm differs from bubble sort in that it sorts
 * 	in both directions on each pass through the list.
 * 	shaking sort is better than bubble sort becouse of the option
 * 	to move objects backwards.
 * Performance:
 * 		2 times better than bubble sort, e.g.
 * {5,4,3,2,1} - bubble sort 4 passes, shake sort only 2
 * Complexity: for sorted array - O(n). for random array - O(n^2).
 * @param[in-out]	_vector: to be sorted
 * @param[in]		_compFunc: key comparator
 * @return ERR_OK on success
 */
ADTErr ShakeSort(Vector* _vec, KeyCompare _func);

/**
 * @brief Insertion Sort
 * 		a comparison sort in which the sorted array (or list) is built
 * 	one entry at a time.
 * The insertion sort is better than bubble sort especially for an almost
 * sorted array it will have much less operations than bubble sort:
 * e.g. {2,3,4,5,1} - bubble sort 5 comparisons, insertion - only one
 * Complexity: for sorted array - O(n). for random array - O(n^2).
 * @param[in-out]	_vector: to be sorted
 * @param[in]		_compFunc: key comparator
 * @return ERR_OK on success
 */
ADTErr InsertionSort (Vector* _vec, KeyCompare _func);

/**
 * @brief Quick Sort
 * 	First divides a large list into two smaller sub-lists:
 * 		a. the smaller elements and
 * 		b. the bogger elements.
 * Quick Sort then recursively sorts the sub-lists.
 * Complexity: for sorted array - O(n^2). for random array - O(nlogn)
 * @param[in-out]	_vector: to be sorted
 * @param[in]		_compFunc: key comparator
 * @return ERR_OK on success
 */
ADTErr QuickSort(Vector* _vec, KeyCompare _func);

/**
 * @brief Merge Sort
 * 		Divide the unsorted list into two sublists, sort each sublist
 * recursively, and then merge the two sublists back into one sorted list
 * Complexity:
 * 		Time  - O(nlogn)
 *		Space - O(n)
 * @param[in-out]	_vector: to be sorted
 * @param[in]		_compFunc: key comparator
 * @return ERR_OK on success
 */

ADTErr MergeSort (Vector* _vec, KeyCompare _func);

/**
 * @brief Counting Sort
 *  Using the knowledge of the value range, count the number of
 * appearences of each value in the unsorted array and then rearrange
 * the values in accending or descending order
 * Complexity:
 * 		Time  - O(n + max), where m is high value of range [0,max]
 *		Space - O(n + max)
 * @param[in-out]	_vector: to be sorted
 * @param[]			_maxValue: the value range
 * @return ERR_OK on success
 */
 /*
ADTErr CountingSort (Vector* _vec, int _maxValue);
*/
/**
 * @brief Radix Sort
 * 	Sort the numbers by digits in some base (Radix), using stable counting sort
 * for each digit
 * Complexity:
 * 		Time  - O(d*n), where d is number of digits 
 *		Space - O(n + radix)
 * @param[in-out]	_vector: to be sorted
 * @param[in]		_radix: the calculation base
 * @return ERR_OK on success
 */
 /*
ADTErr RadixSort(Vector* _vec, int _radix, int _nDigits);
*/
#endif /* __SORTING_H__ */















