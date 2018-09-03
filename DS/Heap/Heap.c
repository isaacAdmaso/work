#include "Heap.h"
#include<stdlib.h>
#include<stdio.h>

#define MAGIC 8952214
#define IS_INVALID(H) ((NULL == (H)) /*|| NULL == (H)->m_vec */|| (H)->m_magic != MAGIC)

struct Heap
{
	Vector *m_vec;
	size_t m_heap_size;
	int m_magic;
};

static void MaxHeapify(Heap* _heap,size_t _index)
{
	int l_val,r_val,index_val,largest_val;
	size_t l,r,largest;
	l = 2*_index+1;
	r = 2*_index+2;
	VectorGet(_heap->m_vec,_index,&index_val);
	if(l < _heap->m_heap_size)
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
	if(r < _heap->m_heap_size)
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
	size_t heap_size;
	int i;
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
	for(i = (heap_size-1)/2; i >= 0; --i)
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
	size_t itemNum;
	int i,temp_first;
	ADTErr error = ERR_OK;
	if(IS_INVALID(_heap))
	{
		return ERR_NOT_INITIALIZED;
	}
	error=VectorAdd(_heap->m_vec,_element);
	if(error != ERR_OK)
	{
		return error;
	}
	VectorGet(_heap->m_vec,0,&temp_first);
	VectorItemsNum(_heap->m_vec,&itemNum);
	VectorSet(_heap->m_vec,0,_element);
	VectorSet(_heap->m_vec,itemNum-1,temp_first);
	++(_heap->m_heap_size);
	for(i = (_heap->m_heap_size)/2; i >= 0; --i)
	{	
		MaxHeapify(_heap,i);
	}
	return error;
	
}
	
ADTErr HeapMax(const Heap* _heap, int *_element)
{
	if(IS_INVALID(_heap) || NULL == _element)
	{
		return ERR_NOT_INITIALIZED;
	}
	return VectorGet(_heap->m_vec,0,_element);
}
	

ADTErr HeapExtractMax(Heap* _heap, int *_element)
{
	int temp_last ,test,i;
	if(IS_INVALID(_heap) || NULL == _element)
	{
		return ERR_NOT_INITIALIZED;
	}
	if(_heap->m_heap_size == 0)
	{
		return ERR_UNDERFLOW;
	}
	VectorGet(_heap->m_vec,_heap->m_heap_size-1,&temp_last);
	VectorGet(_heap->m_vec,0,_element);
	VectorSet(_heap->m_vec,0,temp_last);
	VectorDelete(_heap->m_vec,&test);
	--(_heap->m_heap_size);
	if(test != temp_last)
	{
		return ERR_GENERAL;
	}
	for(i = _heap->m_heap_size/2; i >= 0; --i)
	{	
		MaxHeapify(_heap,i);
	}
	return ERR_OK;
}

int HeapSize(const Heap* _heap)
{
	if(IS_INVALID(_heap))
	{
		return -1;
	}
	return _heap->m_heap_size;
} 

void HeapPrint(const Heap* _heap)
{
	if(IS_INVALID(_heap))
	{
		return ;
	}
	VectorPrint(_heap->m_vec);
}
/*
int main(){
	int  i;
	int arr[]={1,2,3,4,5,36,77,81,29,120};
	Vector *v=VectorCreate(2,2);
	Heap *h;
	for (i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
	{
		VectorAdd(v,arr[i]);
	}
	h = HeapBuild(v);
	HeapPrint(h);
	return 0;
}
*/
























