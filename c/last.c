#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define NUM_OF_ALPHA 128
#define NOR 3
#define NOC 256


void last(char* _fileName,int n)
{	
	int i,count=0;
	int* arr=(int*)calloc(NOR+1,sizeof(int));
	char line[NOC];
	FILE* fp = fopen(_fileName,"r");
	if(fp == NULL)
	{	
		perror("Error file is NULL");
		return;
	}
	while(!feof(fp))
	{		
		fgets(line,NOC,fp);
		if(feof(fp))
		{
			break;
		}
		count+=1;
		arr[count%(n+1)]=(int)ftell(fp);
	}
	fseek(fp,arr[(count+1)%(n+1)],0);
	for(i=0;i<n;++i)
	{	
		fgets(line,NOC,fp);
		printf("%s\n",line);
	}
	free(arr);
	fclose(fp);
}
	
void freq(char* _fileName)
{	
	char ch;
	int i,arr[NUM_OF_ALPHA]={0};
	FILE* fp = fopen(_fileName,"r");
	if(fp == NULL)
	{	
		printf("Error file: %s is NULL",_fileName);
		return;
	}
	do
	{
		ch = fgetc(fp);
		if(isalpha(ch))
		{
			arr[ch]+=1;
		}
		
	}while(ch != EOF);
	for(i=0;i<NUM_OF_ALPHA;++i)
	{
		if(arr[i]>0)
		{	
			printf("%c-%d\n",i,arr[i]);
		}
	}
	fclose(fp);
}

int main()
{	
	last("testl.c",NOR);
	freq("last");
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
