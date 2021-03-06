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
#define MIN 8
#define INIT_VAL false
using namespace std;


class String_t 
{
private:
    char* m_str;
    inline void createFrom(const char* _str);
    inline void createFrom(const char* _str,size_t _start,size_t _size);
    inline unsigned int PoT(unsigned int v);
    size_t m_capacity;
    size_t m_strlen;
    static size_t   capacity;
    static bool     caseSens;


public:
    ~String_t(){delete[] m_str;/*m_str = NULL; double delete will crash the program*/}  

    String_t(){createFrom(NULL);}

    String_t(const char* _str){createFrom(_str);}
    
    String_t(const String_t& _s){createFrom(_s.m_str);}

    String_t(const String_t& _s,size_t _start,size_t _size){createFrom(_s.m_str,_start,_size);}
    
    int  cmpString(const String_t& _s)const;

    const char* getString()const{return m_str;}
    
    void        setString(const char* _str);
    
    operator   char* () {return m_str;}

    String_t   operator()(size_t start, size_t len){ return String_t(*this,start,len);}

    String_t&  operator = (const String_t& _s);
    
    String_t&  operator+= (const String_t& _s);
    
    String_t&  operator+= (const char* _str);
    
    bool     operator <  (const String_t& _s)const;
    
    bool     operator >  (const String_t& _s)const;
    
    bool     operator >= (const String_t& _s)const;

    bool     operator <= (const String_t& _s)const;

    bool     operator == (const String_t& _s)const;

    bool     operator != (const String_t& _s)const;

    bool     contains(const char* _subStr)const;

    char     operator [] (size_t _idx)const;

    char&    operator [] (size_t _idx);

    size_t      getLength()const{return strlen(m_str);}

    void        upper();

    void        lower();

    String_t&   prepend(const String_t& _s);

    String_t&   prepend(const char* _str);

    static bool  setFlag(bool _state){bool temp = caseSens;caseSens = _state;return temp;}

    static bool  getFlag(){return caseSens;}

    static size_t setCapacity(size_t _newCapacity){size_t temp = capacity;capacity = _newCapacity;return temp;}
    
    static size_t  getCapacity(){return capacity;}

    int  getFirstChar(char _ch){char *pch;pch=strchr(m_str,_ch);return (pch) ? pch - m_str:-1;}

    int  getLastChar(char _ch){char *pch;pch=strrchr(m_str,_ch);return (pch) ? pch - m_str:-1;}

};

/**up to (2^32 - 1) */
inline unsigned int String_t::PoT(unsigned int v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}


inline void String_t::createFrom(const char* _str,size_t _start,size_t _size)
{
    char temPtr[MAX];
    size_t mLen;

    if(strlen(_str) < _start)
    {
        return;
    }
    mLen = (_size < MAX)? _size + 1:MAX;
    memset(temPtr, '\0',mLen);
    strncpy(temPtr,_str + _start,mLen-1);
    createFrom(temPtr);
}

inline void String_t::createFrom(const char* _str)
{
    if(_str) {
        m_strlen = strlen(_str)+1;
        if(capacity < m_strlen) {
            m_capacity = PoT(m_strlen);
            m_str = new char[m_capacity];
        }else {
            m_capacity = capacity;
            m_str = new char[capacity];
        }
        strcpy(m_str,_str);
    }else {
        m_capacity = capacity;
        m_strlen = 1;
        m_str = new char[capacity];
        strcpy(m_str,"");
    }
}

inline int String_t::cmpString(const String_t& _s)const
{
    int rtVal;
    if(caseSens)
        return ((rtVal = strcmp(m_str, _s.m_str)) > 0) ? 1: (rtVal == 0) ? 0: -1;
    return ((rtVal = strcasecmp(m_str, _s.m_str)) > 0) ? 1: (rtVal == 0) ? 0: -1;

}


inline bool     String_t::operator <  (const String_t& _s)const
{
    if(caseSens)
        return(strcmp(m_str, _s.m_str) < 0) ? true:false;
    return (strcasecmp(m_str, _s.m_str) < 0) ? true:false;
}


inline bool     String_t::operator >  (const String_t& _s)const
{
    if(caseSens)
        return(strcmp(m_str, _s.m_str) > 0) ? true:false;
    return (strcasecmp(m_str, _s.m_str) > 0) ? true:false;
}


inline bool     String_t::operator >= (const String_t& _s)const
{
    if(caseSens)
        return(strcmp(m_str, _s.m_str) >= 0) ? true:false;
    return(strcasecmp(m_str, _s.m_str) >= 0) ? true:false;

}


inline bool     String_t::operator <= (const String_t& _s)const
{
    if(caseSens)
        return(strcmp(m_str, _s.m_str) <= 0) ? true:false;
    return(strcasecmp(m_str, _s.m_str) <= 0) ? true:false;
}


inline bool     String_t::operator == (const String_t& _s)const
{
    if(caseSens)
        return(!strcmp(m_str, _s.m_str)) ? true:false;
    return(!strcasecmp(m_str, _s.m_str)) ? true:false;
}


inline bool     String_t::operator != (const String_t& _s)const
{
    if(caseSens)
        return(strcmp(m_str, _s.m_str)) ? true:false;
    return(strcasecmp(m_str, _s.m_str)) ? true:false;
}


ostream&    operator << (ostream& _os,const String_t _s);
istream&    operator >> (istream& _is,String_t _s);



#endif /*__STRING_H__ */