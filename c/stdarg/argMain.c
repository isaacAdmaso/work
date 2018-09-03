#include "arg.h"
#include<stdio.h>
#include<string.h>



	

int main(int argc,char* argv[])
{
	int x = atoi(argv[2]);
	int d = atoi(argv[3]);
	char *str=argv[1];
	PirntF(str,x,d);
	
	
	return 0;
}

