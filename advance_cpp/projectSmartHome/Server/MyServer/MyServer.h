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
#include <IAgent.h>
#include <string>
#include "uncopy.h"
#include "AgentHandler.h"
#include "IServer.h"


class MyServer:private Uncopy, public IServer
{
public:
    MyServer(std::vector<IAgent::AgentConfig>& _agents);
    virtual void Run();
    //for debug
    virtual void Print();
private:
    AgentHandler m_agentManager;
};

#endif //__MYSERVER1_H__