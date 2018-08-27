#include "Bit.h"
#include<stdio.h>
#include<stdlib.h>
#define MAGIC 536365635285
#define IS_INVALID(q) ((q) == NULL)


BitMap_t* createMap(const unsigned int NOF)
{
	BitMap_t* bitM == NULL;
	bitM = (BitMap_t*)malloc(sizeof(BitMap_t));
	if(NULL == bitM)
	{
		return NULL;
	}
	bitM->m_bit = (int*)calloc((NOF/(sizeof(int)*8)+1),sizeof(int));
	if(bitM->m_bit == NULL)
	{
		free(bitM);
		return NULL;
	}
	bitM->m_nf = NOF;
	return bitM;
}

void destroyMap(BitMap_t* _bM)
{
	if(!IS_INVALID(_bM))
	{
		if(!IS_INVALID(bitM->m_bit))
		{
			free(bitM->m_bit);
		}
		free(_bM);
	}
}



