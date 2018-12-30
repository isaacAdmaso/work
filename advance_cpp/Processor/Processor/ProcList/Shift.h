/**
 * @file Shift.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-30
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __SHIFT_H__
#define __SHIFT_H__
#include "ITx.h"
#include <string>


class Shift: public ITx
{
private:
    typedef std::string::iterator iter_t;
    static int shift;
    int m_shift;
    static void setShift(int _shift){shift = _shift;}
    static int m_Shift(int c);

public:
    Shift(const int _shift)
    :m_shift(_shift)
    {
    }

    virtual std::string Processor(const std::string& _str);
};


#endif //__SHIFT_H__