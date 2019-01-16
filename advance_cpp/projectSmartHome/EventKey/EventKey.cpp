#include "EventKey.h"

EventKey::EventKey()
{
}
EventKey::~EventKey()
{
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

