#include<stdio.h>

int Sum(int _num)
{
	if(_num == 0)
	{
		return 0;
	}
	return _num%10+Sum(_num/10);
}


int main()
{
	int n =325;
	printf("%d",Sum(n));
}
