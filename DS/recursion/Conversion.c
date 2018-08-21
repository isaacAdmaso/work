#include<stdio.h>

void Conversion(int _num,int _base)
{
	if(_num==0)
	{
		return;
	}
	Conversion(_num/_base,_base);
	printf("%d",_num%_base);
}



int main()
{
	int n = 6;
	int b =2;
	Conversion(n,b);
	return 0;
}
