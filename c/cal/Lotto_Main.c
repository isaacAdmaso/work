#include "Lotto.h"
#include<stdlib.h>
#include<stdio.h>
#include <time.h> 
#define No_of_Guesses 6
#define No_of_rows 5
#define No_of_cul 10


int main() {
	int i,j,temp_i,temp_j,rand_guess,count = 0;
	int* arr_Lt_num=0;
	int** lotto_arr=0;
	arr_Lt_num = creatarr_lotto_no(No_of_Guesses);
	lotto_arr=creatLotto(No_of_rows,No_of_cul);
	if(lotto_arr==0 || arr_Lt_num==0) {
		printf("memory error!!");
		}
	srand (time(0));
	while(count<No_of_Guesses) {
		rand_guess = rand()%48 +1;
		if(serch_arr(arr_Lt_num,No_of_Guesses,rand_guess)) {
			arr_Lt_num[count]=rand_guess;
			count++;
		}
	}
	for(i=0;i<count;++i) { 
		if(arr_Lt_num[i]>9) {
			temp_j=arr_Lt_num[i]%10;
			temp_i=arr_Lt_num[i]/10;
			lotto_arr[temp_i][temp_j]=1;
		}else{
			lotto_arr[0][temp_i]=1;
		}
	}
	
		
	for(i=0;i<No_of_rows;++i) {
		for(j=0;j<No_of_cul;++j) {
			if(lotto_arr[i][j]==0) {
				printf("-");
			}else{
				printf("+");
			}
		}
		printf("\n");
	}
	
	return 0;
}
	
	
	
	
	
	
	
	
			
