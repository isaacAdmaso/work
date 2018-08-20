#include<stdio.h>
/*

void stars1(int _n, int _k)
{	
	
	if (_k>1)
	{
		stars1(_n,_k-1);
	
	}
	if (_n>1)
	{
		stars1(_n-1,_k);
		printf("\n");
	}
	printf("*");
	
}	

*/





void stars(int _n)
{
	if(_n==0)
	{
		printf("\n");
		return;
	}
	printf("*");
	stars(_n-1);
}

void Stars(int _n)
{	
	if(_n==0)
	{
		return;
	}

	stars(_n);
	Stars(_n-1);
}



int main()
{
	int n=5;
	Stars(n);
	return 0;
}	
