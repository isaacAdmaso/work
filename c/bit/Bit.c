#include "Bit.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define IS_INVALID(q) ((q) == NULL)

const int NOF;

BitMap_t* createMap(const unsigned int NOF)
{
	BitMap_t* bitM = NULL;
	bitM = (BitMap_t*)malloc(sizeof(BitMap_t));
	if(NULL == bitM)
	{
		return NULL;
	}
	bitM->m_bit = (unsigned int*)calloc((NOF/(sizeof(unsigned int)*8)+1),sizeof(unsigned int));
	if(NULL == bitM->m_bit)
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
		if(!IS_INVALID(_bM->m_bit))
		{
			free(_bM->m_bit);
		}
		free(_bM);
	}
}
enum status_e onBit(BitMap_t* _bM,unsigned int _bitNum)
{
	unsigned int bitShift;
	unsigned int index;
	if(IS_INVALID(_bM) || _bitNum > NOF)
	{
		return error_e;
	}
	bitShift = 1;
	index = (_bitNum) / (sizeof(unsigned int)*8);
	bitShift = bitShift << ((_bitNum) % (sizeof(unsigned int)*8));
	_bM->m_bit[index] = _bM->m_bit[index] | bitShift;
	return on_e;
}

enum status_e offBit(BitMap_t* _bM,unsigned int _bitNum)
{
	unsigned int bitShift;
	unsigned int index;
	if(IS_INVALID(_bM) || _bitNum > NOF)
	{
		return error_e;
	}
	bitShift = 1;
	index = (_bitNum) / (sizeof(unsigned int)*8);
	bitShift = bitShift << ((_bitNum) % (sizeof(unsigned int)*8));
	bitShift = ~ bitShift;
	_bM->m_bit[index] = _bM->m_bit[index] & bitShift;
	return off_e;
}

enum status_e isBitOn(BitMap_t* _bM,unsigned int _bitNum)
{
	unsigned int bitShift;
	unsigned int index;
	if(IS_INVALID(_bM) || _bitNum > NOF)
	{
		return error_e;
	}
	bitShift = 1;
	index = (_bitNum) / (sizeof(unsigned int)*8);
	bitShift = bitShift << ((_bitNum) % (sizeof(unsigned int)*8));
	if((_bM->m_bit[index] & bitShift) != 0)
	{
		return on_e;
	}
	return off_e;
}

	
void printMap(BitMap_t* _bM)
{
	unsigned int i;
	unsigned int nof;
	char *p;
	if(NULL == _bM )
	{ 
		return;
	}
	nof = _bM->m_nf; 
	p = (char*)malloc(2*(nof+1)*sizeof(char));
	if(p == NULL)
	{
		return;
	}
	for(i = nof;i > 0; ++i)
	{
		if(isBitOn(_bM,i-1) == off_e)
		{
			*(p+i) = '0';
		}
		else
		{
			*(p+i) = '1';
		}
	}
	*(p+nof+1)= '\0';
	printf("%s",p);
}








