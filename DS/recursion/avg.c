#include<stdio.h>

double AvgHlp(double* _arr,/*double* _temp,*/int _size)
{
	if (_size == 1)
	{
		return _arr[0];
	}
	return  _arr[0]+AvgHlp(_arr+1,_size-1);
}

double Avg(double* _arr,/*double* _temp,*/int _size)
{
	double temp;
	temp = AvgHlp(_arr,_size);
	return temp/_size;
}


int main()
{
	double a[]={6,6,6,6,6,6,6};
	printf("%f",Avg(a,6));
}
