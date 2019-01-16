#ifndef __EVENTKEY__
#define __EVENTKEY__

#include <string>
class EventKey
{
public:
	//EventKey(const EventKey& _param);
	//EventKey& operator=( const EventKey& _param );
	EventKey();
	~EventKey();
	bool operator<(const EventKey& _secondEventKey)const;
public:
	std::string m_eventType;
	std::string m_floor;
	std::string m_room;
};

#endif
