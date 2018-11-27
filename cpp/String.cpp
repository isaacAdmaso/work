/**
 * @file String.cpp
 * @brief Hw 
 * @version 0.1
 * @date 2018-11-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include "String.h"
#include <string.h>
#include <iostream>






String_t::String_t()
{
    m_str = NULL;
}

String_t::String_t(const char* _str)
{
    m_str = createFrom(_str);
}

String_t::String_t(const String_t& _s)
{
    m_str = createFrom(((String_t)_s).getString());
}

String_t::~String_t()
{
    delete[] m_str;
    m_str = NULL;
}

void String_t::operator=(const String_t& _s)
{
    if(this != &_s)
    {
        delete[] m_str;
        m_str = createFrom(((String_t)_s).getString());
    }
}

size_t String_t::getLength()
{
    if(m_str)
        return strlen(m_str);
    return 0;
}

void String_t::setString(const char* _str)
{
    delete[] m_str;
    m_str = createFrom(_str);    
}
const char* String_t::getString()
{
    return m_str;
}
int String_t::cmpString(const String_t& _s)
{
    int rtVal;
    if(m_str && _s.m_str)
    {
        return ((rtVal = strcmp(m_str, _s.m_str)) > 0) ? 1: (rtVal == 0) ? 0: -1;
    }
    else if (m_str)
    {
        return 1;
    }
    else 
    {
        return -1;
    }

}
void String_t::printString()
{
    if (m_str)
        cout << m_str;
}


