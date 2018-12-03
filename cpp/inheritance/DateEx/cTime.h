/**
 * @file cTime.h
 * @brief describes the object
 * @version 0.1
 * @date 2018-12-03
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef __CTIME_H__
#define __CTIME_H__
#include <iostream>
#include <time.h>
using namespace std;


class cTime_t
{
private:
    time_t 	m_time_date;
   	struct tm* 	m_current_time;
    static bool formart;
    char* m_line;
public:
    ~cTime_t(){delete [] m_line;}
    cTime_t(){m_time_date = time(0); m_current_time = localtime(&m_time_date);m_line = new char[64];}

    cTime_t(const cTime_t& _w):m_current_time(_w.m_current_time){m_line = new char[64];}
    
    inline char* getTime()const;
    
    void setTime(){m_time_date = time(0); m_current_time = localtime(&m_time_date);}
    int getHours()const{return   m_current_time->tm_hour;}
    int getMinutes()const{return m_current_time->tm_min;}
    int getSeconds()const{return m_current_time->tm_sec;}
    cTime_t&  operator += (const cTime_t& _w);
    cTime_t&  operator + (const cTime_t& _w);

};

ostream&  operator << (ostream& _os,const cTime_t _w);


inline char* cTime_t::getTime()const
{
    if(formart) {
        strftime(m_line, sizeof m_line, "%H:%M:%S", m_current_time);
    }else
        strftime(m_line, sizeof m_line, "%I:%M:%S  %p", m_current_time);
    return m_line;
}

inline cTime_t&  cTime_t::operator += (const cTime_t& _w)
{
    m_current_time->tm_sec += _w.m_current_time->tm_sec;
    if(m_current_time->tm_sec >= 60)
        m_current_time->tm_min += 1;


    m_current_time->tm_min += _w.m_current_time->tm_min;
    if(m_current_time->tm_min >= 60)
        m_current_time->tm_hour += 1;


    m_current_time->tm_hour += _w.m_current_time->tm_hour;
    if(m_current_time->tm_hour >= 24)
        m_current_time->tm_hour -= 24;
 
    return *this;
}
inline cTime_t&  cTime_t::operator + (const cTime_t& _w)
{

    m_current_time->tm_sec += _w.m_current_time->tm_sec;
    if(m_current_time->tm_sec >= 60)
    {
        m_current_time->tm_min += 1;
        m_current_time->tm_sec -=60;
    }


    m_current_time->tm_min += _w.m_current_time->tm_min;
    if(m_current_time->tm_min >= 60)
    {
        m_current_time->tm_hour += 1;
        m_current_time->tm_sec -=60;
    }


    m_current_time->tm_hour += _w.m_current_time->tm_hour;
    if(m_current_time->tm_hour >= 24)
        m_current_time->tm_hour -= 24;
 
    return *this;
}

#endif /*__CTIME_H__*/