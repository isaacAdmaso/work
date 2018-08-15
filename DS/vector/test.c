#include "ADTDefs.h"
#include "vector.h"
#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>


int main(){
	size_t a;
	size_t b;
	a=3;
	b=5;
	Vector* v=VectorCreate(a,b);
	printf("%lu %lu %lu %lu",v->m_originalSize,v->m_allocatedSize,v->m_nItems,v->m_blockSize);
	
	return 0;
}
