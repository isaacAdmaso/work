/**
 * @file Traveler.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-31
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __TRAVELER_H__
#define __TRAVELER_H__
#include "Irole.h"
#include "ITrole.h"


class Traveler:public Irole
{
private:
    ITrole* m_role;
public:
    Traveler(ITrole* _r);
    void Goal();
};


#endif //__TRAVELER_H__