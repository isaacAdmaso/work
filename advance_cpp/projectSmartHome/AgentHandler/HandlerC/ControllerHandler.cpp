/**
 * @file ControllerHandler.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-19
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "ControllerHandler.h"



void ControllerHandler::Print()
{
    for (std::map<EventKey, std::vector<IAgent*> >::iterator it=m_controllerContainer.begin(); it!=m_controllerContainer.end(); ++it)
    {
		((EventKey)it->first).PrintEvent();
    	std::cout<<std::endl;
    	for (std::vector<IAgent*>::iterator itVec=(it->second).begin(); itVec!=(it->second).end(); ++itVec)
		{
			std::cout<< (*itVec)->m_agentData <<std::endl;
		}
    	std::cout<<std::endl;
	}
}

void ControllerHandler::Insert(IAgent* _agent, const EventKey& _eventkey)
{
	m_controllerContainer[_eventkey].push_back(_agent);
}

