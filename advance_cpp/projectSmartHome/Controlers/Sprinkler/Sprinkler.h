/**
 * @file Sprinkler.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __SPRINKLER_H__
#define __SPRINKLER_H__

#include <string>
#include "IAgent.h"


class Sprinkler: public IAgent
{
public:
	Sprinkler(const AgentConfig& _agentConfig);
	virtual ~Sprinkler();
	virtual bool Init();
};

#endif

