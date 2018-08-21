#include<stdio.h>



char GetLastChar(const char *_str)
{
	if(*_str=='\0')
	{
		return*(_str-1);
	}
	GetLastChar(_str+1);
}

int main(){

	char* a="yitshak";
	char b;
	//strcp1(a,b);
	//printf("%s\n",a);
	b=GetLastChar(a);
	printf("%c\n",b);
	
	return 0;
}



