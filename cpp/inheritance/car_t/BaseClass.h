/**
 * @file BaseClass.h
 * @brief for car and bus
 * @version 0.1
 * @date 2018-12-02
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __BASE_H__
#define __BASE_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "String.h"

using namespace std;



class BaseClass
{
private:
    
    const int   m_Id;
    int         m_capacity;
    bool        m_isAuto;
    String_t    m_Type;
    static int  nCars;
    static int  defCapacity;
    static bool isAuto;
    BaseClass& operator = (const BaseClass _car);

protected:
    ~BaseClass(){}
    void setIsAuto(bool _isAuto){m_isAuto = _isAuto;}
    void setName(String_t _name){m_Type = _name;}
    void setCapacity(int _capacity){m_capacity = _capacity;}

public:
    BaseClass():m_Id(nCars++),m_capacity(defCapacity),m_isAuto(isAuto){}

    BaseClass(int _capacity):m_Id(nCars++),m_capacity(_capacity),m_isAuto(isAuto){}

    BaseClass(const BaseClass& _car):m_Id(nCars++),m_capacity(_car.m_capacity),m_isAuto(_car.m_isAuto),m_Type(_car.m_Type){}

    bool            operator <  (const BaseClass& _car)const{return (m_capacity < _car.m_capacity);}
    bool            operator ==  (const BaseClass& _car)const{return (m_Type == _car.m_Type);}
    const String_t& getName()const{return m_Type;}
    bool            getIsAuto()const{return m_isAuto;}
    int             getCapacity()const{return m_capacity;}
    int             getId()const{return m_Id;}
};

ostream&    operator << (ostream& _os,const BaseClass _car);
istream&    operator >> (istream& _is,BaseClass _car);









#endif /*__BASE_H__*/