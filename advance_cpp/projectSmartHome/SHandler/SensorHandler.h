#ifndef __SENSORHANDLER_H__
#define __SENSORHANDLER_H__

#include <map>
#include "EventKey.h"
#include "IAgent.h"

class SensorHandler
{
public :
	SensorHandler();
	~SensorHandler();
	void Insert(IAgent* _agent, const EventKey& _key);
	//bool Find(const EventKey& _key);
private:
	std::map<EventKey, IAgent*> m_sensorsContainer;
};
#endif
