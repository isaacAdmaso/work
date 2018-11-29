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
#include <stdio.h>
#include <ctype.h>
#include "String.h"

using namespace std;

char* String_t::createFrom(const char* _str)
{
    if(_str)
    {
        char* temp = new char[strlen(_str)+1];
        if(!temp)
            strcpy(temp,_str);
        return temp;
    }
    char* rtVal = new char[1];
    strcpy(rtVal,"");
    return rtVal;
}



String_t::String_t()
{
    m_str = createFrom(NULL);
}

String_t::String_t(const char* _str)
{
    m_str = createFrom(_str);
}

String_t::String_t(const String_t& _s)
{
    m_str = createFrom(_s.m_str);
}

String_t::~String_t()
{
    delete[] m_str;
    /*m_str = NULL; double delete will crash the program*/
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


size_t String_t::getLength()const
{
    return strlen(m_str);
}

void String_t::setString(const char* _str)
{
    delete[] m_str;
    m_str = createFrom(_str);    
}

const char* String_t::getString()const
{
    return m_str;
}

int String_t::cmpString(const String_t& _s)const
{
    int rtVal;
    
    return ((rtVal = strcmp(m_str, _s.m_str)) > 0) ? 1: (rtVal == 0) ? 0: -1;
}


 String_t& String_t::operator+= (const String_t& _s)
 {
    char temp[MAX];

    snprintf(temp,MAX,"%s%s",m_str,_s.m_str);
    delete[]m_str;
    m_str = createFrom(temp);
    return *this;
}

String_t& String_t::operator+= (const char* _str)
{
    char temp[MAX];
    if (_str)
    {
        snprintf(temp,MAX,"%s%s",m_str,_str);
        delete[]m_str;
        m_str = createFrom(temp);
    }
    return *this;
}


void   String_t::prepend(const String_t& _s)
{
    char temp[MAX];

    snprintf(temp,MAX,"%s%s",_s.m_str,m_str);
    delete[] m_str;
    m_str = createFrom(temp);
}


void   String_t::prepend(const char* _str)
{
    char temp[MAX];
    if(_str)
    {
        snprintf(temp,MAX,"%s%s",_str,m_str);
        delete[] m_str;
        m_str = createFrom(temp);
    }

}


bool     String_t::operator <  (const String_t& _s)const
{
    return(strcmp(m_str, _s.m_str) < 0) ? true:false;
}


bool     String_t::operator >  (const String_t& _s)const
{
    return(strcmp(m_str, _s.m_str) > 0) ? true:false;
}


bool     String_t::operator >= (const String_t& _s)const
{
    return(strcmp(m_str, _s.m_str) >= 0) ? true:false;

}


bool     String_t::operator <= (const String_t& _s)const
{
    return(strcmp(m_str, _s.m_str) <= 0) ? true:false;

}


bool     String_t::operator == (const String_t& _s)const
{
    return(!strcmp(m_str, _s.m_str)) ? true:false;

}


bool     String_t::operator != (const String_t& _s)const
{
    return(strcmp(m_str, _s.m_str)) ? true:false;
}


bool     String_t::contains(const char* _subStr)const
{
    if(!_subStr)
    {
        return false;
    }
    return (strstr(m_str,_subStr))?true:false;
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

