/**
 * @file FireSensor.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __FIRESENSOR_H__
#define __FIRESENSOR_H__

#include "IAgent.h"

class FireSensor: public IAgent
{
public:
	FireSensor(const AgentConfig& _agentConfig);
	virtual ~FireSensor();
    virtual bool Init();
	virtual bool Do();
};

#endif //__FIRESENSOR_H__
