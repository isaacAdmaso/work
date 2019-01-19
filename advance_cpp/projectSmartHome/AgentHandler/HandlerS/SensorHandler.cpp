/**
 * @file SensorHandler.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-19
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include "SensorHandler.h"


void SensorHandler::Print()
{
    for (std::map<EventKey, IAgent*>::iterator it=m_sensorsContainer.begin(); it!=m_sensorsContainer.end(); ++it)
    {
		((EventKey)it->first).PrintEvent();
    	std::cout<<std::endl<<\
		(it->second)->m_agentData <<std::endl;
	}
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

void SensorHandler::Run()
{
    for (std::map<EventKey, IAgent*>::iterator it=m_sensorsContainer.begin(); it!=m_sensorsContainer.end(); ++it)
    {
		(it->second)->Do();
	}
}