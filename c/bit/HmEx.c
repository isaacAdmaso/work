#include<stdio.h>
#include "HmEx.h"
void packOne(char *_str,int _size)
{
	int i;
	Packing_u ch;
	if(_str == NULL)
	{
		return;
	}
	for(i = 0;i < _size/2;++i)
	{
		ch.side1=(str[i]-'a');
		ch.side2=(str[i+1]-'a');
		str[i] = ch;
	}
	if(_size % 2 == 1)
	{
		ch.side1 =str[_size]; 
		str[i+1] = ch.side1;
	}
}
/*
void packTwo(char *_str,int _size)
{
	if(_str == NULL)
	{
		return;
	}
*/	
