/**
 * @file Event.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <time.h>		    //for time and date
#include <sys/time.h>		//for time and date
#include <stdio.h>          //for sprintf
#include <iostream>         //for debug
#include <unistd.h>
#include "Event.h"


Event::Event()
{
}


Event::Event(Event& _e)
:m_key(_e.m_key)
{
    GeTime();
}

void Event::GeTime()
{
    struct timeval tv;
    time_t nowtime;
    struct tm *nowtm;
    char time[64];
	char date[64];
	char eTime[64]; 

    gettimeofday(&tv, NULL);
    nowtime = tv.tv_sec;
    nowtm = localtime(&nowtime);

    strftime(date, sizeof date, "%Y-%m-%d", nowtm);
    strftime(time, sizeof time, "%H:%M:%S", nowtm);
    sprintf(eTime, "%s.%.3ld", time, tv.tv_usec/1000);
    Event* ptr =  const_cast<Event*> (this);
	ptr->m_time = eTime;
	ptr->m_date = date;	
}

Event::Event(const std::string& eventType,const Location& _loc)
:m_key(eventType,_loc)
{
    GeTime();
}

Event::~Event()
{
}

void Event::SetEvent(const std::string& eventType ,const Location& _loc)
{
    m_key.SetEvent(eventType,_loc);
    GeTime();
}
bool Event::operator<(const Event& _secondEvent)const
{
    return m_key < _secondEvent.m_key;
}

/**for debug */
void Event::PrintEvent()
{
    m_key.PrintEvent();
    std::cout<<m_time<<std::endl<<m_date<<std::endl<<std::flush;

}
