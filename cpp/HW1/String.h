/**
 * @file String.h
 * @brief class String HW
 * @version 0.1
 * @date 2018-11-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __STRING_H__
#define __STRING_H__
#include <iostream>
#include <stddef.h>
#include <string.h>

using namespace std;


class String_t 
{
private:
    char* m_str;
    char* createFrom(const char* _str);

public:
    ~String_t();
    String_t();
    String_t(const char* _str);
    String_t(const String_t& _s);
    String_t& operator = (const String_t& _s);
    String_t& operator+= (const String_t& _s);
    String_t& operator+= (const char* _str);
    bool     operator <  (const String_t& _s)const;
    bool     operator >  (const String_t& _s)const;
    bool     operator >= (const String_t& _s)const;
    bool     operator <= (const String_t& _s)const;
    bool     operator == (const String_t& _s)const;
    bool     operator != (const String_t& _s)const;
    bool     contains(const char* _subStr)const;
    char     operator [] (size_t _idx)const;
    size_t      getLength()const;
    void        setString(const char* _str);
    const char* getString()const;
    int         cmpString(const String_t& _s)const;
    void        upper();
    void        lower();
    void        prepend(const String_t& _s);
    void        prepend(const char* _str);
    void        printString()const;

};

ostream&  operator << (ostream& _os,const String_t _s);
istream& operator >> (istream& _is,String_t _s);



#endif /*__STRING_H__ */