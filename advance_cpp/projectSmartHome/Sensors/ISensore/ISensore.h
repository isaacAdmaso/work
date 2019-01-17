/**
 * @file ISensore.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __ISENSORE_H__
#define __ISENSORE_H__
#include <string>
#include "IAgent.h"


class ISensore: public IAgent 
{
public:
    ISensore(const AgentConfig& _agentConfig);
    virtual ~ISensore();
    virtual bool Init();
	bool SendEvent();

protected:
	std::string m_config;
};

#endif //__ISENSORE_H__