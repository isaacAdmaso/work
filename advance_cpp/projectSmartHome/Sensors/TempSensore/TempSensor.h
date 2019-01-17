/**
 * @file TempSensor.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __TEMPSENSOR_H__
#define __TEMPSENSOR_H__

#include "IAgent.h"


class TempSensor: public IAgent
{
public:
	TempSensor(const AgentConfig& _agentConfig);
	virtual ~TempSensor();
    virtual bool Init();
	bool SendEvent();

private:
	int m_lowTemp;
	int m_upperTemp;
	int m_period;
};

#endif //__TEMPSENSOR_H__
