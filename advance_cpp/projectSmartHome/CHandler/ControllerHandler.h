#ifndef __CONTROLLERHANDLER_H__
#define __CONTROLLERHANDLER_H__

#include <map>
#include<vector>
#include "EventKey.h"
#include "IAgent.h"

class ControllerHandler: private UncopyAble
{
public :
	ControllerHandler();
	~ControllerHandler();
	void Insert(IAgent* _agent, const EventKey& _key);
	//bool Find(const EventKey& _key);
private:
	std::map<EventKey, std::vector<IAgent*>> m_controllerContainer;
};
#endif
