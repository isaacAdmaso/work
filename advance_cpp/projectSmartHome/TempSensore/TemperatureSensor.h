#ifndef __TEMPERATURESENSOR_H__
#define __TEMPERATURESENSOR_H__

#include <string>
#include "IAgent.h"


class TemperatureSensor: public IAgent
{
public:
	TemperatureSensor(const AgentConfig& _agentConfig);
	virtual ~TemperatureSensor();
	virtual bool Init();
	//virtual bool Connect();
	// Send event to the agent from the server 
	//virtual bool TakeEvent(const std::string& _eventType);
private:
	std::string m_config;
	int m_lowTemp;
	int m_upperTemp;
	int m_period;
private:
	void HandleConfigLine(const std::string& _config);
};

#endif
