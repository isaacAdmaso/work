#include <stdio.h>
#include "HmEx.h"
#include<string.h>


int main ()
{
	char str[] = "abcdefghijmno"; 
	printf("%d\n",packOne(str));
	printf("%d\n",packTwo(str,strlen(str)));
	return 0;
}



