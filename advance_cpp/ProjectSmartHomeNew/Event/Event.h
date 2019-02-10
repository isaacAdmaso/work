/**
 * @file Event.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-16
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
	Event(Event& _e);
	Event(const std::string& eventType,const Location& _loc);
	~Event();
	void SetEvent(const std::string& eventType ,const Location& _loc);
	bool operator<(const Event& _secondEvent)const;
	/**for debug */
	void PrintEvent();
private:
	EventKey m_key;
	std::string m_time;
	std::string m_date;
	void GeTime();
};
#endif // __EVENT_H__
