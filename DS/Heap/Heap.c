#include "Heap.h"
#include<stdlib.h>
#include<stdio.h>

#define MAGIC 8989852214
#define IS_INVALID(H) (((H) == NULL) || (H)->m_magic != MAGIC)

struct Heap
{
	Vector *m_vec;
	size_t m_heap_size;
	size_t m_magic;
};

static void MaxHeapify(Heap* _heap,size_t _index)
{
	int l_val,r_val,index_val,largest_val;
	size_t l,r,largest;
	l = 2*_index+1;
	r = 2*_index+2;
	VectorGet(_heap->m_vec,_index,&index_val);
	if(l <= _heap->m_heap_size)
	{
		VectorGet(_heap->m_vec,l,&l_val);
		if(l_val > index_val)
		{
			largest = l;
		}else
		{
			largest = _index;
		}
	}else 
	{
		largest = _index;
	}
	if(r <= _heap->m_heap_size)
	{
		VectorGet(_heap->m_vec,r,&r_val);
		if(r_val > l_val && r_val > index_val)
		{
			largest = r;
		}
	}
	if (largest != _index)
	{
		VectorGet(_heap->m_vec,largest,&largest_val);
		VectorSet(_heap->m_vec,_index,largest_val);
		VectorSet(_heap->m_vec,largest,index_val);
		MaxHeapify(_heap,largest);
	}
}
		
	 		
Heap* HeapBuild(Vector* _vector)
{
	size_t heap_size,i;
	Heap* h = NULL;
	h = (Heap*)malloc(sizeof(Heap));
	if(NULL == _vector || NULL == h)
	{
		return NULL;
	}
	VectorItemsNum(_vector,&heap_size);
	h->m_magic = MAGIC;
	h->m_vec = _vector;
	h->m_heap_size = heap_size;
	for(i = heap_size/2; i >= 0; ++i)
	{	
		MaxHeapify(h,i);
	}
	return h;
}
	
void HeapDestroy(Heap* _heap)
{
	if(!IS_INVALID(_heap))
	{
		_heap->m_magic = -1;
		free(_heap);
	}
}
	
ADTErr HeapInsert(Heap* _heap, int _element)
{
	
	
/*

ADTErr HeapMax(const Heap* _heap, int *_element);
ADTErr HeapExtractMax(Heap* _heap, int *_element);
int HeapSize(const Heap* _heap);
void HeapPrint(const Heap* _heap);

*/


