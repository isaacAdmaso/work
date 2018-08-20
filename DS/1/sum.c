#include<stdio.h>

int sum_arr(int* _arr,int _size)
{
	if(_size==0)
	{
		return 0;
	}
	return *_arr+sum_arr(_arr+1,_size-1);
}
int main()
{
	int sum,arr[]={1,23,3,5,3,78};
	sum = sum_arr(arr,sizeof(arr)/sizeof(arr[0]));
	printf("%d\n",sum);
	return 0;
}
