#ifndef __HVAC_H__
#define __HVAC_H__

#include <string>
#include "IAgent.h"


class HVAC: public IAgent
{
public:
	HVAC(const AgentConfig& _agentConfig);
	virtual ~HVAC();
	virtual bool Init();
private:
	std::string m_config;
	std::string m_lowTemp;
	std::string m_upperTemp;
private:
	void HandleConfigLine(const std::string& _config);
};

#endif
