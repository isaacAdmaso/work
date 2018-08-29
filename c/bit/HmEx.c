#include "HmEx.h"
#include<stdio.h>
#include<stdlib.h>




int packOne(char *_str)
{
	int i,j;
	union Packing_u ch;
	
	if(_str == NULL)
	{
		return -1;
	}
	for(i = 0 , j=0;_str[i] != '\0';i+=2,++j)
	{
		ch.pack.side1=(_str[i]-'a');
		if(_str[i+1] != '\0')
		{
			ch.pack.side2=(_str[i+1]-'a');
		}
		_str[j] = ch.pack.side1 | ch.pack.side2;
	}
	return j;
}

int packTwo(char *_str,int _size)
{
	int i, j;
	char ch1, ch2;

	if(_str == NULL)
	{
		return -1;
	}
	
	for(i = 0,j = 0;i < _size;i+= 2,++j)
	{
		ch1=_str[i] - 'a';
		ch1<<=(sizeof(char)/2);
		if(i+1 < _size)
		{
			ch2=_str[i+1]-'a';
		}
		else
		{
			ch2 = 0;
		}
		_str[j] =  ( ch1 | ch2 ) ;
	}		
	
	return j;
}



























