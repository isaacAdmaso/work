/**
 * @file Bus.h
 * @brief derived bus class from  BaseClass
 * @version 0.1
 * @date 2018-12-02
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __BUS_H__
#define __BUS_H__
#include "BaseClass.h"

class Bus_t:public BaseClass
{
private:
    static String_t name;
    static int      seats;
    static int      line;
    int             m_seats;
    int             m_line;

public:
    ~Bus_t(){}
    Bus_t();
    Bus_t(int _capacity);
    Bus_t(Bus_t& _bus);
    void setBcapacity(int _bCapacity){(*this).setCapacity(_bCapacity);}
    int setLine(int _line){return m_line = _line;}
    int setnSeat(int _seat){return m_seats = _seat;}
    int getLine()const{return m_line;}
    int getnSeat()const{return m_seats;}
};

inline Bus_t::Bus_t():BaseClass()
{
    (*this).setName(name);
    m_seats = seats;
    m_line = line;
}

inline Bus_t::Bus_t(int _capacity):BaseClass(_capacity)
{
    (*this).setName(name);
    m_seats = seats;
    m_line = line;
}

inline Bus_t::Bus_t(Bus_t& _bus):BaseClass(_bus)
{
    (*this).setName(name);
    m_seats = seats;
    m_line = line;
}




#endif /*__BUS_H__*/