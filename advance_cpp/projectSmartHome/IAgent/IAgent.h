#ifndef __IAGENT_H__
#define __IAGENT_H__

#include <string>
#include "IServer.h"
#include "UncopyAble.h"
class IServer;


class IAgent: private UncopyAble
{
public:
struct AgentConfig
{
	IServer*	m_server;
	std::string		m_id;
	std::string		m_type;
	std::string		m_log;
	std::string		m_floor;
	std::string		m_room;
	std::string		m_configData;
};
typedef struct AgentConfig AgentConfig;
public:
	IAgent();
	virtual ~IAgent();
	virtual bool Init(const AgentConfig& _agentConfig) = 0;
	//virtual bool Connect() = 0;
        // Send event to the agent from the server 
	//virtual bool TakeEvent(const std::string& _eventType) = 0;
protected:
	std::string m_id;
	std::string m_type;
	std::string m_log;
	std::string m_floor;
	std::string m_room;
	IServer*	m_server;
};

#endif
