/**
 * @file MyServer.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-19
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __MYSERVER1_H__
#define __MYSERVER1_H__
#include <vector>
#include <string>
#include "Msgq.h"
#include "uncopy.h"
#include "IAgent.h"
#include "IServer.h"
#include "AgentHandler.h"


class MyServer:public IServer
{
public:
    MyServer(std::vector<IAgent::AgentConfig>& _agents);
    virtual void PublishEvent();
    virtual void Run();
    //for debug
    virtual void Print();
private:
    const static std::string msg_name; 
    AgentHandler m_agentManager;
    Msgq m_msgq;
};

#endif //__MYSERVER1_H__