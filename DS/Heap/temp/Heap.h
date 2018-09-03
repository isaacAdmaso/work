#ifndef __HEAP_H__
#define __HEAP_H__

/**
 * @brief Create a Binary Maximum Heap policy ADT over a Vector container.
 * @author yitshak admaso.
 * @see https://en.wikipedia.org/wiki/Binary_heap 
 *
 * Description:              Basic Binary Heap Definition
 */

#include "ADTDefs.h"
#include "vector.h"

typedef struct Heap Heap;

/**  
 * @brief Apply a heap policy over a Vector container.  
 * @param[in] _vector - Vector that holds the elements, must be initialized
 * @return Heap * - on success
 * @retval NULL on fail 
 *
 * @warning allocating and freeing the underlying vector is user responsibility. 
 * as long as vector is under the heap control, user should not access the vector directly
 */
Heap* HeapBuild(Vector* _vector);

/**  
 * @brief Deallocate a previously allocated heap
 * Frees the heap but not the underlying vector  
 * @param[in] _heap - Heap to be deallocated.
 */
void HeapDestroy(Heap* _heap);

/**  
 * @brief Add an element to the Heap preserving heap property.  
 * @param[in] _heap - Heap to insert element to.
 * @param[in] _element - Element to insert. can't be null
 * @return success or error code 
 * @retval ERR_OK  on success
 * @retval ERR_NOT_INITIALIZED  error, heap not initilized
 * @retval ERR_REALLOCATION_FAILED error, heap could not reallocate underlying vector 
 */
ADTErr HeapInsert(Heap* _heap, int _element);

/**  
 * @brief Return the current maximum element from th heap without extracting it.  
 * @param[in]  _heap - Heap to peek at.
 * @param[out] _element - placeholder for the max element
 * @return success or error code 
 * @retval ERR_OK on succes
 * @retval ERR_NOT_INITIALIZED error, heap is not initialized
 * @retval ERR_UNDERFLOW, heap is empty
 */
ADTErr HeapMax(const Heap* _heap, int *_element);

/**  
 * @brief Extract element on top of heap and remove it.  
 * @param[in]  _heap - Heap to extract from.
 * @param[out] _element - placeholder for the max element
 * @retval ERR_OK on succes
 * @retval ERR_NOT_INITIALIZED error, heap is not initialized
 * @retval ERR_UNDERFLOW, heap is empty
 */
ADTErr HeapExtractMax(Heap* _heap, int *_element);

/**  
 * @brief Get the current size (number of elements) of the heap.  
 * @param[in] _heap - the Heap.
 * @retval number of elements or zero if empty, -1 if not initialized 
 */
int HeapSize(const Heap* _heap);

/**
 * @brief Printout the contents of the heap - for debugging and testing purposes
 * @param[in] _heap - the Heap
 */
void HeapPrint(const Heap* _heap);


#endif /*__HEAP_H__*/
