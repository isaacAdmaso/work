/**
 * @file String.cpp
 * @brief Hw 
 * @version 0.1
 * @date 2018-11-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <iostream>
#include <string.h>
#include "String.h"

using namespace std;

char* String_t::createFrom(const char* _str)
{
    if(_str)
    {
        char* temp = new char[strlen(_str)+1];
        strcpy(temp,_str);
        return temp;
    }
    return NULL;
}



String_t::String_t()
{
    m_str = NULL;
    cout << "\nCTOR\n";
}

String_t::String_t(const char* _str)
{
    m_str = createFrom(_str);
    cout << "\nCTOR\n";
}

String_t::String_t(const String_t& _s)
{
    m_str = createFrom(_s.m_str);
    cout << "\nCTOR\n";
}

String_t::~String_t()
{
    delete[] m_str;
    m_str = NULL;
    cout << "\nDTOR\n";
}

String_t& String_t::operator=(const String_t& _s)
{
    if(this != &_s)
    {
        delete[] m_str;
        m_str = createFrom(_s.m_str);
    }
    return *this;
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
        std::cout << "\n" << m_str <<"\n";
}

