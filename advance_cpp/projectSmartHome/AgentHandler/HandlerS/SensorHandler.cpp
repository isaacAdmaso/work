#include <iostream>
#include "SensorHandler.h"

SensorHandler::SensorHandler()
{
}

SensorHandler::~SensorHandler()
{
}


void SensorHandler::Insert(IAgent* _agent, const EventKey& _key)
{
	std::pair<std::map<EventKey, IAgent*>::iterator, bool> isUnique;
	isUnique = m_sensorsContainer.insert(std::pair<EventKey,IAgent*>(_key, _agent));
	if(isUnique.second == false)
	{
		std::cout << "Sensor is already exist" << std::endl;
	}
}

