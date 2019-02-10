/**
 * @file Location.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __DEVICELOCATION_H__
#define __DEVICELOCATION_H__

#include <string>

struct Location
{
	Location()
    {}
	Location(int floor,int room)
    :m_floor(floor),
    m_room(room)
    {}
	void Set(int floor = 1,int room = 1)
    {
        m_floor = floor; 
        m_room = room; 
    }

    bool operator==(const Location& _loc)const
    {
        return((m_floor == _loc.m_floor)&&(m_room == _loc.m_room));
    }
    
    bool operator<(const Location& _loc)const
    {
        if(m_floor < _loc.m_floor)
        {
            return true;
        }
        else if (m_floor > _loc.m_floor)
        {
            return false;
        }
        else
        {
            return (m_room < _loc.m_room);
        }
    }

	int m_floor;
	int m_room;
};


#endif //__DEVICELOCATION_H__