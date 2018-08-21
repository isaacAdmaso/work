#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comp_h(char x,char y)
{
	return y==x;
}


int comp(char* _str,int _n)
{	
	char* chr;
	if(_n<=1)
	{
		return 1;
	}
	if(comp_h(_str[0],_str[_n-1]))
	{
		return comp(_str+1,_n-2);
	}
	return 0;
}	

int main()
{
 	char* str="qweewq";
 	size_t len=6;
 /*	printf("enter string: ");
 	scanf("%s",str);
 	len =  strlen(str);*/
 	printf("%d",comp(str,len));
 	return 0;
 }
