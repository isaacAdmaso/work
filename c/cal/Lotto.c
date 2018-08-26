#include "Lotto.h"
#include<stdlib.h>
#include<stdio.h>



int serch_arr(int* arr,int size, int num) {
	int i;
	for(i=0;i<size;++i) {
		if(arr[i] == num) return 0;
	}
	return 1;
}

int* creatarr_lotto_no(int no_o_gues) {
	int* temp_arr =0;
	temp_arr = (int*)calloc(no_o_gues,sizeof(int));
	return temp_arr;
}	
	

int** creatLotto(int size_row,int size_cul) {
	int** temp=0;
	int i,j;
	temp =(int**)malloc(size_row*sizeof(int*));
		if (temp == 0) return NULL;
	for(i=0;i<size_row;++i) {
		temp[i] = (int*)calloc(size_cul,sizeof(int));
		if(temp[i] == 0) {
			for(j=0;j<i;j++) {
				free(temp[j]);
			}
			free(temp);
			return NULL;
		}
	}
	return temp;	
}




