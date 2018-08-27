#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ReadBinFile(const char* fName) {
	int age2, h2, lng, i;
	char* name2;
	FILE* fp;	fp = fopen(fName, "r");

	for(i=0; i<2;++i) {
		fread(&lng, sizeof(int), 1, fp); 
		name2 = malloc(lng);
		fread(name2, sizeof(char), lng, fp); 
		fread(&age2, sizeof(int), 1, fp);
		fread(&h2, sizeof(int), 1, fp);
		printf("Person name %s, age = %d hight = %d\n", name2, age2, h2 );
		free(name2);
	}
	fclose(fp);

}


int main()
{
	int age1, h1,  lng, i;
	char name1 [32];
	char fName[32];
	FILE* fp;
	
	printf("Please , enter file name: ");
	scanf("%s",fName); 

	fp = fopen(fName, "w");

	for(i=0; i<2;++i) {
		printf("Please , person nme, age and hight : ");
		scanf("%ReadBinFiles%d%d", name1, &age1, &h1); 
		lng = strlen(name1)+1;
		fwrite(&lng, sizeof(int), 1, fp); 
		fwrite(name1, sizeof(char), lng, fp); 
		fwrite(&age1, sizeof(int), 1, fp);
		fwrite(&h1, sizeof(int), 1, fp);
	}
	fclose(fp);

	ReadBinFile(fName);
	
	
	

	return 0;
}

	
	
