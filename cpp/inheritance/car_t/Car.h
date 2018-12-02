/**
 * @file Car.h
 * @brief derived car class from  BaseClass
 * @version 0.1
 * @date 2018-12-02
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __CAR_H__
#define __CAR_H__
#include "BaseClass.h"


class Car_t:public BaseClass
{
private:
    int m_speed;
    static int speed;
    static String_t name;
    void InitCar();

public:
    ~Car_t(){}
    Car_t();
    Car_t(int _capacity);
    Car_t(const Car_t& _car);
    void setCcapacity(int _cCapacity){(*this).setCapacity(_cCapacity);}
    int accelerate(int _accelerate){return m_speed += _accelerate;}
    int reduceSpeed(int _speed){return m_speed -= _speed;}
    int getSpeed(){return m_speed;}
    int setSpeed(int _speed){return m_speed = _speed;}

};



inline Car_t::Car_t():BaseClass()
{
    (*this).setName(name);
    (*this).m_speed = speed;
}

inline Car_t::Car_t(int _capacity):BaseClass(_capacity)
{
    (*this).setName(name);
    (*this).m_speed = speed;
}

inline Car_t::Car_t(const Car_t& _car):BaseClass(_car)
{
    (*this).setName(name);
    (*this).m_speed = _car.m_speed;
}




#endif /*__CAR_H__*/