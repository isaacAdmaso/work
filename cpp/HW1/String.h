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
#include <stddef.h>
#include <string.h>


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
    size_t getLength();
    void setString(const char* _str);
    const char* getString();
    int cmpString(const String_t& _s);
    void printString();

};




#endif /*__STRING_H__ */