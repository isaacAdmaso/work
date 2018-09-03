#include<stdio.h>
#include<string.h>
#include<stdarg.h>




int PirntF(char *_str, ...)
{
	int lenT,len;
	char *st,st2[32];
	const char* key = "%";
	char toPrint[512];
	
	va_list args;
	va_start(args,_str);
	lenT=strlen(_str);
	st = strtok(_str,key);
	strcpy(toPrint,st);
	_str = _str+strlen(st)+1;
	len=strlen(st)+1;
	while(len < lenT)
	{
		switch(*(_str))
		{
			case 'd':
				sprintf(st2,"%d",va_arg(args,int));
				strcat(toPrint,st2);
				break;
			case 'f':
				sprintf(st2,"%f",va_arg(args,double));
				strcat(toPrint,st2);
				break;
			case 's':
				strcat(toPrint,va_arg(args,char*));
			case '%':
				strcat(toPrint,key);
				break;
			default:
				return -1;
		}
		st = strtok(NULL,key);
		if(st == NULL)
		{
			puts(toPrint);
			return 0;
		}
		strcat(toPrint,st+1);
		_str+=strlen(st)+1;
		len+=strlen(st)+1;
	}
	puts(toPrint);
	return 0;
}
/*	
int main(){
	int age=31,b=2,c=3;
	float d=1.1,e=2.2,f=1.88;
	char name[]="yitshak", str[512]="Hello %d c %s my hight is %f,my age is %d";
	PirntF(str,age,name,f);
	
	
	return 0;
}

*/
