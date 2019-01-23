/**
 * @file ServerFactory.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __SERVERFACTORY__
#define __SERVERFACTORY__
#include <string>
#include <vector>
#include "IServer.h"
#include "uncopy.h"


class ServerFactory: private Uncopy
{
public:
	~ServerFactory();
	IServer* MakeServer(const std::string& _lib ,std::vector<IAgent::AgentConfig>& _agents);

private:
	typedef IServer* (*CreateServer)(void* _agents);
};

#endif //__SERVERFACTORY__
