/**
 * @file String.cpp
 * @brief Hw 
 * @version 0.1
 * @date 2018-11-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <string.h>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "String.h"

using namespace std;

bool String_t::caseSens = INIT_VAL;
size_t   String_t::capacity = MIN;


String_t& String_t::operator=(const String_t& _s)
{
    if(this != &_s)
    {
        if(m_capacity < _s.m_strlen)
        {
            delete[] m_str;
            createFrom(_s.m_str);
        }
        strcpy(m_str,_s.m_str);
        m_strlen = _s.m_strlen;
    }
    return *this;
}


void String_t::setString(const char* _str)
{
    if(_str){
        m_strlen = strlen(_str) +1;
        if(m_capacity < m_strlen){
            delete[] m_str;
            createFrom(_str);
        }else{
            strcpy(m_str,_str);
        }
    }else{
        m_strlen = 1;
        *m_str ='\0';         
    }
}


String_t& String_t::operator+= (const String_t& _s)
{
    char temp[MAX]; 
    
    snprintf(temp,MAX,"%s%s",m_str,_s.m_str);
    m_strlen +=_s.m_strlen-1;

    if(m_capacity < m_strlen){
        delete[]m_str;
        createFrom(temp);
        return *this;

    }else{
        strcpy(m_str,temp); 
    }
    return *this;
}

String_t& String_t::operator+= (const char* _str)
{
    char temp[MAX];
    if (_str)
    {
        m_strlen +=strlen(_str) - 1;
        snprintf(temp,MAX,"%s%s",m_str,_str);
        if(m_capacity < m_strlen){
            delete[]m_str;
            createFrom(temp);
        }else{
            strcpy(m_str,temp);
        }
    }
    return *this;
}


String_t&   String_t::prepend(const String_t& _s)
{
    char temp[MAX];
    m_strlen += _s.m_strlen-1;
    snprintf(temp,MAX,"%s%s",_s.m_str,m_str);

    if(m_capacity < m_strlen) {
        delete[] m_str;
        createFrom(temp);
    }else{
        strcpy(m_str,temp);
    }
    return *this;
}


String_t&   String_t::prepend(const char* _str)
{
    char temp[MAX];
    if(_str)
    {
        snprintf(temp,MAX,"%s%s",_str,m_str);
        m_strlen = strlen(temp)+1;
        if(m_capacity < m_strlen)   {
            delete[] m_str;
            createFrom(temp);
        }else{
            strcpy(m_str,temp);
        }
    }
    return *this;
}



bool     String_t::contains(const char* _subStr)const
{
    if(!_subStr)
    {
        return false;
    }
    if(caseSens)
        return (strstr(m_str,_subStr))?true:false;
    return (strcasestr(m_str,_subStr))?true:false;
    
}

char&    String_t::operator [] (size_t _idx)
{
    size_t len = strlen(m_str);

    if(_idx >= len)
        return m_str[len + 1];
    return m_str[_idx];
}

char     String_t::operator [] (size_t _idx)const
{
    if(_idx >= strlen(m_str))
        return '\0';
    return m_str[_idx];
}


void    String_t::upper()
{
    char* temp = m_str;
    int i = 0;

    while(*temp) 
    {
        m_str[i] = toupper(*temp);
        ++i;
        ++temp;
    }
}

void    String_t::lower()
{
    char* temp = m_str;
    int i = 0;

    while(*temp) 
    {
        m_str[i] = tolower(*temp);
        ++i;
        ++temp;
    }
}

istream& operator >> (istream& _os,String_t _s)
{
    char tempStr[MAX];

    _os >> tempStr;
    _s.setString(tempStr);
    return _os;
}

ostream&  operator << (ostream& _os,const String_t _s)
{
    _os <<"String: "<<_s.getString()<<endl;
    return _os;
}

