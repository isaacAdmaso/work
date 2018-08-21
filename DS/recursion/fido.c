#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
int fib1(int _n)
{
	if (_n <= 1)
	{
		return _n;
	}
	return fib1(_n-1)+fib1(_n-2);
}

int fib2(int _n)
{
	int i;
	int fib1=0,fib2=1,fibON;
	for(i=0;i<_n-1;++i)
	{
		fibON=fib1+fib2;
		fib1=fib2;
		fib2=fibON;
	}
	return fibON;
}





int main(int argc, char* argv[])
{	
	int num=atoi(argv[1]);
	printf("recursion(fib1)\n %d\nloop(fib2)\n %d\n",fib1(num),fib2(num));
	return 0;
}
