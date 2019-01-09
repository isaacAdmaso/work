/**
 * @brief 
 * 
 */
#ifndef __EVENTKEY_H__
#define __EVENTKEY_H__
#include <string>

class EventKey
{
public:
    EventKey( std::string  m_type, std::string  m_floor, std::string  m_room);

private:
    std::string  m_type;
    std::string  m_floor;
    std::string  m_room;
};

#endif // __EVENTKEY_H__
