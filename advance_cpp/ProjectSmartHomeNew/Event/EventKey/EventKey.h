/**
 * @file EventKey.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-19
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __EVENTKEY_H__
#define __EVENTKEY_H__

#include "Location.h"
#include <string>

class EventKey
{
public:
	EventKey();
	~EventKey();
	EventKey(const std::string& eventType,const Location& _loc);
	bool operator<(const EventKey& _secondEventKey)const;
	bool operator==(const EventKey& _secondEventKey)const;
	void SetEvent(const std::string& eventType,const Location& _loc);
	/**for debug */
	void PrintEvent();
private:
	std::string m_eventType;
	Location 	m_loc;

};

#endif //__EVENTKEY_H__
