#include<stdio.h>


size_t MyStrlen(char* str)
{
	if (*str == '\0')
	{
		 return 0;
	 }
	 return MyStrlen(str + 1)+1;
}



int main()
{
 	char* str;
 	size_t len;
 	printf("enter string: ");
 	scanf("%s",str);
 	len =  MyStrlen(str);
 	printf("%ld",len);
 	return 0;
 }
