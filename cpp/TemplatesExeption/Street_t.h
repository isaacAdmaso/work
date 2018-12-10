/**
 * @file Street_t.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __STREET_H__
#define __STREET_H__
#include <vector>

using namespace std;



template <class U,class T>

class Street_t
{
private:
    vector<T>   buildings;
    U               m_id;
public:
    ~Street_t(){}
    Street_t(){}
    Street_t(Street_t& _s){buildings = _s.buildings;m_id = _s.m_id;}
    Street_t&  operator = (const Street_t& _s){buildings = _s.buildings;}
    void setStreetID(U _newId){m_id = _newId;}
    U&  getStreetID(){return m_id;}
    void AddBuilding2Street(T& building){buildings.push_back(building);}
    T& getBuilding(int i){return buildings[i];}
};



#endif //__STREET_H__