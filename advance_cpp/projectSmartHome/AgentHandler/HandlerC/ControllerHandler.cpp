#include "ControllerHandler.h"


ControllerHandler::ControllerHandler()
{
}

ControllerHandler::~ControllerHandler()
{
}

void ControllerHandler::Insert(IAgent* _agent, const EventKey& _eventkey)
{
	m_controllerContainer[_eventkey].push_back(_agent);
}

