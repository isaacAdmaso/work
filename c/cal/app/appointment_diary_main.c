#include "appointment_diary.h"
#include<stdio.h>
#include<stdlib.h>

const char FILE_IO_NAME[] = "diary.txt" ;

int main()
{
	float begin,end;
	enum status_e temp_enum;
	int temp,option,cont =1;
	unsigned int capacity,room;
	meetptr meet=0;
	Calendar_t* d_dairy =0;
	do
	{
	printf("Enter capacity: ");
	scanf("%u",&capacity);
	} while(capacity <=0);
	
	d_dairy = creatAD(capacity);
	temp_enum=insertFromFile(FILE_IO_NAME,d_dairy);
	while(cont) {
		printf("	Choose option: \n");
		printf("	1: Insert meeting into dairy \n");
		printf("	2: Print dairy    \n");
		printf("	3: Remove meeting  \n");
		printf("	4: Find meeting    \n");
		printf("	Any another number - stop \n");
	
		scanf("%d", &option);
/*		switch (option) {
			case 1:*/
		if(option == 1) {
				printf("enter start and end time,and room number: \n");
				scanf("%f\n",&begin);
				scanf("%f\n",&end);
				scanf("%u",&room);
				meet = creatMeet(begin,end,room);
				if(meet == NULL) {
					printf("failed to creat meeting!!!\n");
					/*break;*/
				}else{				 
					temp_enum = Insert(d_dairy,meet); 	
					if(temp_enum != ok_e) {
						printf("failed to insert!!!\n");
					}
				}
				/*break;*/
		}else if(option == 2) {
			/*case 2:*/
				print_Cal(d_dairy);/*	break;*/
		}else if(option == 3) {
		
		/*	case 3:*/
				printf("enter start time: \n");
				scanf("%f",&begin);
				temp_enum=remove_meet(d_dairy,begin);
				if(temp_enum != ok_e) {
					printf("failed!!!\n");
				}else{
					printf("meeting deleted\n");
				}
				/*break;*/
		}else if(option == 4) {
		
			/*case 4:*/
				printf("enter start time: \n");
				scanf("%f",&begin);
				temp=find(d_dairy,begin);
				if (temp == -1) {
					printf("failed!!!\n");
				}else{
					printf("Start in %f\nEnd in %f\nRoom #no: %d\n ",d_dairy->day[temp]->begin_time,d_dairy->day[temp]->end_time,d_dairy->day[temp]->room_num);
				}
				/*break;*/
		}else{
				cont = 0;
			/*default: cont = 0;	break;*/
		}
	}
	temp_enum = writeToFile(d_dairy,FILE_IO_NAME);
	destroycal(d_dairy);
	

	return 0;
}
			

	
