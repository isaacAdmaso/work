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

/*
void printMap(BitMap_t* _bM)
{
	unsigned int i,k;
	char str_bin[32];
	unsigned int arrSize = NOF/(sizeof(unsigned int)*8)+1;
	if(IS_INVALID(_bM))
	{
		return;
	}
	for(i=0;i<arrSize;++i)
	{
		while(_bM->m_bit[i] != 0)
		{
			if(_bM->m_bit[i]%2)
			{
				strcpy(str_bin,"0");
			}
			else
			{
				strcpy(str_bin,"1");
			}
		}
	}
	printf("%s",str_bin);		
}
*/



