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
#ifndef __EVENTKEY__
#define __EVENTKEY__

#include <string>
class EventKey
{
public:
	EventKey();
	EventKey(const std::string& eventType,const std::string& floor,const std::string& room);
	~EventKey();
	bool operator<(const EventKey& _secondEventKey)const;
	void SetEvent(const std::string& eventType ,const std::string& floor = "1",const std::string& room = "1");
	/**for debug */
	void PrintEvent();
private:
	std::string m_eventType;
	std::string m_floor;
	std::string m_room;
};

#endif
