/**
 * @file IDevice.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __IDEVICE_H__
#define __IDEVICE_H__
class Event_Publisher;
class Event_Listener;

class IDevice
{
public:
    virtual ~IDevice();
    virtual void Close();
    virtual void Init();
private:
    
};


#endif //__IDEVICE_H__