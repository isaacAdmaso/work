/**
 * @file EventListener.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __EVENTLISTENER_H__
#define __EVENTLISTENER_H__

#include "EventKey.h"

class IEventListener
{
public:
    virtual ~IEventListener();
    virtual void Notify(const EventKey& _eKey) = 0;
};


#endif //__EVENTLISTENER_H__