#include "Bit.h"
#include<stdio.h>

const unsigned int NOF = 44;


int main()
{	
	BitMap_t* b_m;
	int option;
	unsigned int nof;
	enum status_e check_valid;
	bitF bitFunc[3] = {onBit,offBit,isBitOn};
	b_m = createMap(NOF);
	if(b_m == NULL)
	{
		return 1;
	}
	while(1)
	{
		/*printMap(b_m);*/
		printf("enter: 1 to select feature,\n       2 to unselect feature,\n       3 to check if feature is selected(bigger number to quit): \n");
		scanf("%d",&option);
		if(option>3 || option == 0)
		{
			break;
		}
		printf("enter number between 1 to %d: \n",NOF+1);
		scanf("%d",&nof);
		check_valid = bitFunc[option -1](b_m,nof-1);
		if(check_valid != error_e)
		{
			printf("0 is ON ,1 is OFF) %d\n",check_valid);
		}
		else
		{
			break;
		}
	}
	destroyMap(b_m);
	return 0;
} 
	
