#include "HVAC.h"

HVAC::HVAC(const AgentConfig& _agentConfig)
:IAgent(_agentConfig)
,m_config(_agentConfig.m_config)
{
	//init lower and uppr temp
}
HVAC::~HVAC()
{

}
void HVAC::HandleConfigLine(const std::string& _config)
{
	std::vector<string> m_tokens;
	
	
}
bool HVAC::Init()
{
	EventKey eventKey;
	eventKey.m_eventType = "FIRE_DETECTED_ELECTRIC";
	m_server->SubscribeController(this, eventKey);
	
	eventKey.m_floor = m_floor;
	m_server->SubscribeController(this, eventKey);
	
	if(!(m_room == ""))
	{
		eventKey.m_room = m_room;
		m_server->SubscribeController(this, eventKey);
	}
	eventKey.m_eventType = "AMBIENT_TEMP";
	m_server->SubscribeController(this, eventKey);
	return true;
}
class HVAC: public IAgent
{
public:
	HVAC(const AgentConfig& _agentConfig);
	virtual ~HVAC();
	virtual bool Init();
	virtual bool Connect();
	// Send event to the agent from the server 
	//virtual bool TakeEvent(const std::string& _eventType);
private:
	std::string m_config;
	std::string m_lowerTemp;
	std::string m_upperTemp;
};
