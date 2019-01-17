#include "MyServer.h"

MyServer::MyServer()
{
}

MyServer::~MyServer()
{
}


void MyServer::SubscribeController(IAgent* _agent, const EventKey& _eventkey)
{
	m_controllerHandler.Insert(_agent, _eventkey);
}

void MyServer::SubscribeSensor(IAgent* _agent, const EventKey& _eventkey)
{
	m_sensorHandler.Insert(_agent, _eventkey);
}
