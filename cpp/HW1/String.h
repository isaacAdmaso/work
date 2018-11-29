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

#define MAX 1024


using namespace std;


class String_t 
{
private:
    char* m_str;
    inline char* createFrom(const char* _str);

public:
    ~String_t(){delete[] m_str;/*m_str = NULL; double delete will crash the program*/}  
    String_t(){m_str = createFrom(NULL);}
    String_t(const char* _str){m_str = createFrom(_str);}
    String_t(const String_t& _s){m_str = createFrom(_s.m_str);}
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
    char&    operator [] (size_t _idx);
    size_t      getLength()const;
    void        setString(const char* _str);
    const char* getString()const;
    int         cmpString(const String_t& _s)const;
    void        upper();
    void        lower();
    void        prepend(const String_t& _s);
    void        prepend(const char* _str);
    void        printString()const;
    static bool     caseSens;
    static size_t   capacity;

};

inline char* String_t::createFrom(const char* _str)
{
    if(_str)
    {
        char* temp = new char[strlen(_str)+1];
        if(temp)
            strcpy(temp,_str);
        return temp;
    }
    char* rtVal = new char[1];
    strcpy(rtVal,"");
    return rtVal;
}
ostream&  operator << (ostream& _os,const String_t _s);
istream& operator >> (istream& _is,String_t _s);



#endif /*__STRING_H__ */