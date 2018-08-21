#include<stdio.h>


void Gcd(int _num1, int _num2)
{
	if ( _num2 <=0)
	{
		printf("%d",_num1);
		return;
	}
	if (_num1>_num2)
	{
		Gcd(_num2,_num1-_num2);
	}else
	{
		Gcd(_num2,_num2-_num1);
	}
}

int main()
{
	int n=78;
	int k=37;
	Gcd(k,n);
	return 0;
}
