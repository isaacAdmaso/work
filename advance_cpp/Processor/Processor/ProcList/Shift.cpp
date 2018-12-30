/**
 * @file Shift.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-30
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <algorithm>
#include <string>
#include "Shift.h"

int Shift::shift = 0;

int Shift::m_Shift(int _c)
{
    if(_c >= 'a' && _c <= 'z')
    {
        _c = _c + shift;
        
        if(_c > 'z'){
            _c = _c - 'z' + 'a' - 1;
        }
    }
	else if(_c >= 'A' && _c <= 'Z')
    {
		_c = _c + shift;
		
		if(_c > 'Z'){
			_c = _c - 'Z' + 'A' - 1;
		}
		
	}
    return _c;
}

std::string Shift::Processor(const std::string& _str)
{
    std::string temp = _str;
    setShift(m_shift);     
    std::transform(temp.begin(), temp.end(),
        temp.begin(), Shift::m_Shift);
    return temp;
}
