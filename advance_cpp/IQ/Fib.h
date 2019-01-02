/**
 * @file Fib.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __FIBONACCI_H__
#define __FIBONACCI_H__
#include <map>

class Fib
{
private:
    std::map<int,int> m_FibTlb;
    typedef std::map<int,int>::iterator itr_t;
    int Get_Fib_Rec(int _n);
public:
    int Get_Fib(int _n);
};



#endif //__FIBONACCI_H__