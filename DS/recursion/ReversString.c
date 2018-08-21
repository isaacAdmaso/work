#include<stdio.h>
#include<string.h>


char* reverse(char *a,char *b)
{
	char chr[1];
	
	if(*a =='\0')
	{   
		chr[0]=*(a-1);
		chr[1]='\0';
		
		return chr;
	}
	reverse(a+1,b);
	strcat(b,chr);
	chr[0]=*(a-1);
	chr[1]='\0';
	return b;
		
}       

int main()
{
	char s1[32] = "yitshak";
	char s2[32];
	reverse(s1,s2);
	printf("%s",s2);
	return 0;
}
