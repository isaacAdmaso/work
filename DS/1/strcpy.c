#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void strcp1(char* _to,const char* _from)
{
	if(*_from == '\0')
	{
		return;
	}
	if(*_to=='\0')
	{
		_to[0]=_from[0];
		strcp1(_to+1,_from+1);
		return;
	}
	strcp1(_to+1,_from);
}

void strcp2(char* _to,const char* _from)
{
	if(*_from == '\0')
	{
		return;
	}
	_to[0]=_from[0];
	strcp2(_to+1,_from+1);
}

int main(){

	char a[32]="yitshak";
	char b[]="admaso";
	//strcp1(a,b);
	//printf("%s\n",a);
	strcp2(a,b);
	printf("%s",a);
	
	return 0;
}



