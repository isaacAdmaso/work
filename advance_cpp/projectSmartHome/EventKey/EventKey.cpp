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

EventKey::EventKey(const std::string& eventType, const std::string& floor,const std::string& room)
:m_eventType(eventType),
m_floor(floor),
m_room(room)
{
}

EventKey::EventKey()
{
}

EventKey::~EventKey()
{
}

void EventKey::SetEvent(const std::string& eventType ,const std::string& floor ,const std::string& room)
{
	m_eventType = eventType; 
	m_floor = floor; 
	m_room = room; 
}


void EventKey::PrintEvent()
{
	std::cout<< std::endl<<m_eventType<< std::endl<<m_floor<< std::endl<<m_room<<std::endl;

}

bool EventKey::operator<(const EventKey& _secondEventKey)const
{
	if (m_eventType == _secondEventKey.m_eventType)
	{
		if (m_floor == _secondEventKey.m_floor)
		{
			return m_room < _secondEventKey.m_room;
		}
		
		return m_floor < _secondEventKey.m_floor;
	}
	
	return m_eventType < _secondEventKey.m_eventType;
}

