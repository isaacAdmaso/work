#ifndef __HMEX_H__
#define __HMEX_H__

typedef struct PackC
{
	char side1 :4;
	char side2 :4;
}PackC;

union  Packing_u
{
	PackC pack;
	char ch;
};


int packOne(char *_str,int _size);
void packTwo(char *_str,int _size);
#endif
