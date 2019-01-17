/**
 * @file HVAC.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */
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
	virtual bool Do();
};

#endif //__HVAC_H__
