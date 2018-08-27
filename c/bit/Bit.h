#ifndef __BIT_H__
#define __BIT_H__


enum status_e {on_e = 0,off_e,error_e};

typedef struct BitMap_t
{
	int *m_bit;
	unsigned int m_nf;
};

typedef struct BitMap BitMap_t;
typedef int(*bitF)(BitMap_t*,int);





BitMap_t* createMap(const unsigned int NOF);
enum status_e onBit(BitMap_t* _bM,unsigned int _bitNum);
enum status_e offBit(BitMap_t* _bM,unsigned int _bitNum);
enum status_e isBitOn(BitMap_t* _bM,unsigned int _bitNum);
void destroyMap(BitMap_t* _bM);
 
void printMap(BitMap_t* _bM);

#endif
