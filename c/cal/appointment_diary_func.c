#include<stdlib.h>
#include<stdio.h>
#include "appointment_dairy.h"

const NOC = 1024;


meetptr creatMeet(float begin_t,float end_t,unsigned int room_n) 
{	
	meetptr meet=0;
	if(begin_t>=end_t || begin_t<0 || end_t >24) return NULL;
	meet = (Meeting_t*)malloc(sizeof(Meeting_t));
	if(meet==NULL) return NULL;
	
	meet ->begin_time = begin_t;
	meet ->end_time = end_t;
	meet ->room_num = room_n;
	return meet;
}

Calendar_t* creatAD(unsigned int _capacity) {
	 Calendar_t* day_Mtng=0;
	 day_Mtng = (Calendar_t*)malloc(sizeof(Calendar_t));
	 if(day_Mtng==NULL) {
	 	return NULL;
	 }
	 if (_capacity ==0) _capacity = 1;
	 
	 day_Mtng ->day = (meetptr*)malloc(_capacity*sizeof(meetptr));
	 
	 if(day_Mtng ->day == NULL) {
	 	free(day_Mtng);
	 	return NULL;
	 }
	 day_Mtng ->NOM = 0;
	 day_Mtng ->capacity = _capacity;
	 return day_Mtng;
}

void left_S(Calendar_t* _day_mtng,int mtng_index) {
	int i;
	if(_day_mtng!=NULL) {
		if(_day_mtng->day!=NULL) {
			for(i=mtng_index;i<_day_mtng->NOM-1;++i) {
				_day_mtng->day[i] = _day_mtng->day[i+1];
			}
		}
	}
}

void swap(Meeting_t* x,Meeting_t* y) {
	Meeting_t temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void right_S(Calendar_t* _day_mtng,int mtng_index) {
	int i;
	meetptr  temp=0;
	
	temp=(Meeting_t*)malloc(sizeof(Meeting_t));
	if(_day_mtng!=NULL) {
		if(_day_mtng->day!=NULL) {
			for(i=mtng_index;i<_day_mtng->NOM;++i) {
				swap(temp, _day_mtng->day[i]);
			}
		}
		_day_mtng->day[_day_mtng->NOM] = temp;
		_day_mtng->NOM +=1;
	}
	free(temp);
}

enum status_e  Insert(Calendar_t* _dairy,meetptr _meet) {
	meetptr* temp = _dairy->day;
	int i;
	if(_dairy == NULL || _dairy->day == NULL) {
		if(_meet != NULL) free(_meet);			
		return bad_parameter_e;
	}
	if(_dairy->capacity == _dairy->NOM) {
		temp = (meetptr*)realloc(_dairy->day,(_dairy->capacity*2)*sizeof(meetptr));
		if(temp ==NULL) {
			free(_meet);
			return memory_error_e;
		}else{
			_dairy->day = temp;
			_dairy->capacity *=2;
		}
	}
	if (_dairy->NOM==0) {
		_dairy->day[0]=_meet;
		_dairy ->NOM +=1;
		return ok_e;
	}else if(_dairy->day[0]->begin_time >= _meet->end_time) {
		right_S(_dairy,0);
		_dairy->day[0]=_meet;
		return ok_e;
	}else if(_dairy->day[_dairy->NOM-1]->end_time <= _meet->begin_time) {
		_dairy->day[_dairy->NOM] = _meet;
		_dairy->NOM+=1;
		return ok_e;
	}else{
		for(i=1;i<_dairy->NOM;++i) {
			if(_meet->end_time <= _dairy->day[i]->begin_time) {
				if(_meet ->begin_time >= _dairy->day[i-1]->end_time) {
					right_S(_dairy,i);
					_dairy->day[i] = _meet;
					return ok_e;
				}
			}
		}
	}
	free(_meet);
	return bad_parameter_e;
}
		
int find(Calendar_t* _dairy,float a_begin_time) {
	int i,found = -1;
		for(i=0;i<_dairy->NOM;++i) {
			if(_dairy->day[i]->begin_time == a_begin_time) {
				found=i;
				break;
			}
		}
	return found;
}



	 
enum status_e  remove_meet(Calendar_t* _dairy,float a_begin_time) {
	int index_meet=find(_dairy,a_begin_time);
	meetptr temp=_dairy->day[index_meet];
	if (index_meet==-1) return bad_parameter_e;
	free(_dairy->day[index_meet]);
	left_S(_dairy,index_meet);
	_dairy->NOM-=1;
	return ok_e;
}

			

void destroycal(Calendar_t* _dairy) {
	int i;
	if(_dairy!=NULL) {
		if(_dairy->day!=NULL) {
			for(i=0;i<_dairy->NOM;++i) {
				free(_dairy->day[i]);
			}
			free(_dairy->day);
		}
		free(_dairy);
	}
}


void print_Cal(Calendar_t* _dairy) {
	int i;
	for(i=0;i<_dairy->NOM;++i) {
		printf("Meeting %d)\n  Start in %f\n  End in %f\n  Room #no: %d\n ",i+1,_dairy->day[i]->begin_time,_dairy->day[i]->end_time,_dairy->day[i]->room_num);
	}
}
		
enum status_e insertFromFile(char* _fileName,Calendar_t* _dairy)
{
	FILE* fp;
	meetptr newMeet=NULL;
	float begin,end;
	unsigned int room;
	enum status_e insertErr;
	fp = fopen(_fileName,"r");
	if(fp == NULL)
	{
		return bad_parameter_e;
	}
	while(fscanf (fp, "%f", &begin) != EOF)
	{	
		fscanf (fp, "%f", &end);
		fscanf (fp, "%u", &room);
		newMeet=creatMeet(begin,end,room);
		if(newMeet == NULL) 
		{
			return memory_error_e;
		}
		insertErr=Insert(_dairy,newMeet);
		if(insertErr != ok_e)
		{
			return insertErr;
		}
	}
	return ok_e;
}



enum status_e writeToFile











		
		
		
		
		
		
		
