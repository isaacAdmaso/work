/**
 * @file City_t.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __CITY_H__
#define __CITY_H__
#include <list>
using namespace std;


template <class T,class U>

class City_t
{
private:
    list<T>   street;
    U               m_id;
public:
    ~City_t(){}
    City_t(){}
    City_t(City_t& _s){street = _s.street;m_id = _s.m_id;}
    City_t&  operator = (const Street_t<T,U>& _s){street = _s.street;}
    void    setCityID(U& _newId){m_id = _newId;}
    U& getCityID(){return m_id;}
    void AddStreet(T& newStreet){street.push_back(newStreet);}
    T& getStreet() {street.pop_front();}
};


#endif //__CITY_H__