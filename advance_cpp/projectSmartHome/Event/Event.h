/**
 * @file Event.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-08
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __EVENT_H__
#define __EVENT_H__
#include <string>
#include "EventKey.h"


class Event
{
public:
    Event();
    
private:
    EventKey    m_key;
    std::string m_time;
    std::string m_date;
};



#endif //__EVENT_H__