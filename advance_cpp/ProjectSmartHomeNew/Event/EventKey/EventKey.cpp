/**
 * @file EventKey.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "EventKey.h"
#include <iostream> //for debug


EventKey::EventKey()
{
}

EventKey::~EventKey()
{
}

EventKey::EventKey(const std::string& eventType, const Location& _loc)
:m_eventType(eventType),
m_loc(_loc)
{}

void  EventKey::SetEvent(const std::string& eventType,const Location& _loc)
{
	m_eventType = eventType; 
	m_loc = _loc;
}


void EventKey::PrintEvent()
{
	std::cout<< std::endl<<m_eventType<< std::endl<<m_loc.m_floor<< std::endl<<m_loc.m_room<<std::endl;
}

bool EventKey::operator<(const EventKey& _secondEventKey)const
{
	if (m_eventType == _secondEventKey.m_eventType)
	{
		return m_loc <  _secondEventKey.m_loc;
	}
	
	return m_eventType.compare(_secondEventKey.m_eventType);
}

