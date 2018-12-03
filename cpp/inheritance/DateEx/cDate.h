/**
 * @file cDate.h
 * @brief 
 * @version 0.1
 * @date 2018-12-03
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __CDATE_H__
#define __CDATE_H__
#include <time.h>
#include <iostream>
using namespace std;


class cDate_t
{
private:
    time_t 	m_time_date;
   	struct tm* 	m_current_time;
    static int formart;
    char* m_line;
public:
    ~cDate_t(){delete[] m_line;}
    cDate_t():m_time_date(time(0)),m_current_time(localtime(&m_time_date)){m_line = new char[64];}
    cDate_t(const cDate_t& _w):m_current_time(_w.m_current_time){m_line = new char[64];}
    
    inline char* getDate()const;

    void setDate(){m_time_date = time(0); m_current_time = localtime(&m_time_date);}
    int getDay()const{return    m_current_time->tm_mday;}
    int getMon()const{return    m_current_time->tm_mon + 1;}
    int getyear()const{return   m_current_time->tm_year + 1900;}
    bool isLeap()const{return   (m_current_time->tm_year + 1900)%4 == 0;}
    cDate_t&  operator + (const cDate_t& _w);

};


ostream&  operator << (ostream& _os,const cDate_t _w);


inline char* cDate_t::getDate()const
{
    switch(formart)
    {
        case 0:
            strftime(m_line, sizeof m_line, "%d:%b:%Y", m_current_time);
            break;
        case 1:
            strftime(m_line, sizeof m_line, "%d:%m:%Y", m_current_time);
            break;
        case 2:
            strftime(m_line, sizeof m_line, "%m:%d:%Y", m_current_time);
            break;
        default:
            break;
    }
    return m_line;
}

inline cDate_t&  cDate_t::operator + (const cDate_t& _w)
{

    m_current_time->tm_mday += _w.m_current_time->tm_mday;
    if(m_current_time->tm_mday >= 30)
    {
        m_current_time->tm_mon += 1;
        m_current_time->tm_mday -= 30;
    }


    m_current_time->tm_mon += _w.m_current_time->tm_mon;
    if(m_current_time->tm_min > 12)
    {
        m_current_time->tm_year += 1;
        m_current_time->tm_min -= 12;
    }

    return *this;
}



#endif /*__CDATE_H__*/