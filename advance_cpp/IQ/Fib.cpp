/**
 * @file Fib.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Fib.h"

int Fib::Get_Fib(int _n)
{
    int rtVal = 0;

    if(_n < 0 )
    {
        return rtVal;
    }   

    itr_t it = m_FibTlb.find(_n);
    if(it != m_FibTlb.end())
    {
        rtVal = it->second;
    }
    else
    {
        rtVal = Fib::Get_Fib_Rec(_n);
        m_FibTlb[_n] = rtVal;
    }
    return rtVal;
}

int Fib::Get_Fib_Rec(int _n)
{
    if (_n == 0)
        return 1;
    if (_n == 1)
        return 1;
    itr_t it = m_FibTlb.find(_n);
    if(it != m_FibTlb.end())
    {
        return it->second;
    }   
    return Get_Fib_Rec(_n - 1) + Get_Fib_Rec(_n - 2);
}
