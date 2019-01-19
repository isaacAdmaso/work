/**
 * @file ControllerHandler.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __CONTROLLERHANDLER_H__
#define __CONTROLLERHANDLER_H__

#include <map>
#include <vector>
#include "EventKey.h"
#include "IAgent.h"
#include "uncopy.h"

class ControllerHandler: private Uncopy
{
public:
	void Insert(IAgent* _agent, const EventKey& _key);
	void Run();
	//for debug
	void Print();
private:
	std::map<EventKey, std::vector<IAgent*> > m_controllerContainer;
};
#endif
