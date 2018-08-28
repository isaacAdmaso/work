#include<stdio.h>
#include<string.h>
#include "HmEx.h"



int packOne(char *_str,int _size)
{
	int i;
	union Packing_u ch;
	if(_str == NULL)
	{
		return -1;
	}
	for(i = 0;i < _size/2;++i)
	{
		ch.pack.side1=(_str[i]-'a');
		ch.pack.side2=(_str[i+1]-'a');
		_str[i] = ch.pack;
	}
	if(_size % 2 == 1)
	{
		ch.pack.side1 =_str[_size]; 
		_str[i+1] = ch.pack.side1;
	}
	return i;
}
/*
void packTwo(char *__str,int _size)
{
	if(__str == NULL)
	{
		return;
	}
*/	
