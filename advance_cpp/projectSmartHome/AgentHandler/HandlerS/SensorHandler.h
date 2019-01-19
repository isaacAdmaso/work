/**
 * @file SensorHandler.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __SENSORHANDLER_H__
#define __SENSORHANDLER_H__

#include <map>
#include "EventKey.h"
#include "IAgent.h"

class SensorHandler
{
public:
	void Insert(IAgent* _agent, const EventKey& _key);
	//for debug
	void Print();
private:
	std::map<EventKey, IAgent*> m_sensorsContainer;
};

#endif
