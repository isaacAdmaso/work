#include<stdio.h>
#include<string.h>


unsigned int reverseBits(unsigned int num)
{
	unsigned int NO_OF_BITS = sizeof(unsigned int) * 8;
	unsigned int reverse_num = 0, i, temp;

	for (i = 0; i < NO_OF_BITS; ++i)
	{
		
		if(num & (1 << i))
		{
			reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
		}
	}

	return reverse_num;
}

unsigned int rotateByN(unsigned int num,int n)
{
	unsigned int NO_OF_BITS = sizeof(unsigned int)*8;
	unsigned int i,rotate_num = 0;
	for(i=0;i<n;++i)
	{
		if(num & 1<<i)
		{
			rotate_num |= (1 << ((NO_OF_BITS-1)-(NO_OF_BITS-1 - n)+i));
		} 
	}
	return rotate_num;
}
	
/* Driver function to test above function */
int main()
{
	unsigned int x = 2; 
	printf("%u\n", reverseBits(x));
	printf("%d\n",rotateByN(x,3));
	return 0;
}
