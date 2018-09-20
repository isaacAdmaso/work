#ifndef Appointment_diary_h
#define Appointment_diary_h
#include<stdlib.h>
#include<stdio.h>

enum status_e {ok_e, memory_error_e, bad_parameter_e};

typedef struct {
	float begin_time;
	float end_time;
	unsigned int room_num;
} Meeting_t;

typedef Meeting_t* meetptr;

typedef struct {
	meetptr* day;
	unsigned int capacity;
	unsigned int NOM;
}Calendar_t;

enum status_e insertFromFile(const char* _fileName,Calendar_t* _dairy);
enum status_e writeToFile(Calendar_t* _dairy,const char* _fileName);
meetptr creatMeet(float begin_t,float end_t,unsigned int room_n) ;
Calendar_t* creatAD(unsigned int _capacity);
void left_S(Calendar_t* _day_mtng,int mtng_index);
void swap(Meeting_t* x,Meeting_t* y);
void right_S(Calendar_t* _day_mtng,int mtng_index);
enum status_e  Insert(Calendar_t* _dairy,meetptr _meet);
enum status_e  remove_meet(Calendar_t* _dairy,float a_begin_time);
int find(Calendar_t* _dairy,float a_begin_time);
void destroycal(Calendar_t* _dairy);
void print_Cal(Calendar_t* _dairy);
#endif
