#include<stdio.h>
#include<ctype.h>

char FirstCapitalL(char* _str)
{
	if(*_str == '\0' || isupper(*_str))
	{
		return *_str; 
	}
	FirstCapitalL(_str+1);
}

int main()
{
	char s1[]="yitshAk";
	char s2[]="yitshak";
	char s3[]="Yitshak";
	char s4[]="yitshaK";
	printf("%c\n",FirstCapitalL(s1));
	printf("%c\n",FirstCapitalL(s2));
	printf("%c\n",FirstCapitalL(s3));
	printf("%c\n",FirstCapitalL(s4));
	return 0;
}
