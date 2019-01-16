#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>
#include "EventKey.h"

class Event
{
public:
	Event();
	~Event();
	//Event(const Event& _param);
	//Event& operator=(const Event& _param);
public:
	EventKey m_key;
	std::string m_time;
	std::string m_data;
};
#endif // __EVENT_H__
