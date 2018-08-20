#include <stdio.h>

int power(int _n,unsigned int _k)
{
	if(_k==0)
	{
		return 1;
	}
	return power(_n,_k-1)*_n;
}

int main()
{
	int n,k,powOfNByK;
	printf("enter num: \n");
	scanf("%d",&n);
	printf("enter pow: \n");
	scanf("%d",&k);
	powOfNByK=power(n,k);
	printf("%d^%d=%d\n",n,k,powOfNByK);
	return 0;
}
