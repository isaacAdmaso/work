#include<stdio.h>
#include<string.h>
#include<stdarg.h>




int PirntF(const char *_str, ...)
{
	int lenT,len;
	char *st,st2[32],*st3;
	const char* key = "%";
	char *toPrint;
	
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
			return 0;
		}
		strcat(toPrint,st+1);
		_str+=strlen(st)+1;
		len+=strlen(st)+1;
	}
	printf("%s",toPrint);
	return 0;
}
	
int main(){
	int a=1,b=2,c=3;
	float d=1.1,e=2.2,f=3.3;
	const char str[512]="asdgsd -a %d ,b %d,c %d,d %f,e %f,f %f-ghr";
	PirntF(str,a,b,c,d,e,f);
	
	
	return 0;
}
	
	
	
























