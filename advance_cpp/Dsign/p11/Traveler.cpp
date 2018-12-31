/**
 * @file Traveler.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-31
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Traveler.h"

Traveler::Traveler(ITrole* _r)
:m_role(_r)
{
}


void Traveler::Goal()
{
    m_role->Gole();
}