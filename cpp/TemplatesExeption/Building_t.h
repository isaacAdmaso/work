/**
 * @file Building_t.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __BUILDING_H__
#define __BUILDING_H__

template <class T>


class Building_t
{
private:
    T           idBuilding;
    const int         m_id;
    static int  id;

public:
    ~Building_t(){}
    Building_t():m_id(id){}
    Building_t(T newT):m_id(id){ idBuilding = newT;}
    Building_t(Building_t& oldB):m_id(id){ idBuilding = oldB.idBuilding;}
    Building_t&  operator = (const Building_t& _b){idBuilding = newT;}
    void        setBuildingID(T newT) { idBuilding = newT;}
    T&          getBuildingID()const { return &idBuilding;}
};

template <class T> 
int Building_t<T>::id = 0;


#endif //__BUILDING_H__