/**
 * @file binIO.h
 * @brief 
 * @version 0.1
 * @date 2018-12-11
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __BINARY_IO_H
#define __BINARY_IO_H
#include <stddef.h>
#include <stdio.h>
#include <string>
#include "virIO.h"



class binIO_t: virtual public virIO_t
{
private:
    void*   m_tempBuffPtr;  /**save given buffer for (Read or Write) */
    int     m_shiftMode;      /**0 >> ,1 << */
    template <typename T> binIO_t& opHelperW(T& _val);
    template <typename T> binIO_t& opHelperR(T& _val);
    binIO_t(binIO_t& _a){}
    binIO_t& operator = (const binIO_t _a);




public:
    binIO_t():m_tempBuffPtr(0),m_shiftMode(-1){}
    binIO_t(string &_nameF,string &mode):virIO_t(_nameF,mode),m_tempBuffPtr(0),m_shiftMode(-1){}
   

    virtual ~binIO_t()  {}
    virtual int         getStatus(){return virIO_t::getStatus();}
    virtual binIO_t&    operator>>(char& _val){return opHelperR(_val);}
    virtual binIO_t&    operator>>(short& _val){return opHelperR(_val);}
    virtual binIO_t&    operator>>(int& _val){return opHelperR(_val);}
    virtual binIO_t&    operator>>(long& _val){return opHelperR(_val);}
    virtual binIO_t&    operator>>(float& _val){return opHelperR(_val);}
    virtual binIO_t&    operator>>(unsigned char& _val){return opHelperR(_val);}
    virtual binIO_t&    operator>>(unsigned short& _val){return opHelperR(_val);}
    virtual binIO_t&    operator>>(unsigned int& _val){return opHelperR(_val);}
    virtual binIO_t&    operator>>(unsigned long& _val){return opHelperR(_val);}
    virtual binIO_t&    operator>>(double& _val){return opHelperR(_val);}
    virtual binIO_t&    operator<<(char _val){return opHelperW(_val);}
    virtual binIO_t&    operator<<(short _val){return opHelperW(_val);}
    virtual binIO_t&    operator<<(int _val){return opHelperW(_val);}
    virtual binIO_t&    operator<<(long _val){return opHelperW<long>(_val);}
    virtual binIO_t&    operator<<(float _val){return opHelperW(_val);}
    virtual binIO_t&    operator<<(unsigned char _val){return opHelperW(_val);}
    virtual binIO_t&    operator<<(unsigned short _val){return opHelperW(_val);}
    virtual binIO_t&    operator<<(unsigned int _val){return opHelperW(_val);}
    virtual binIO_t&    operator<<(unsigned long _val){return opHelperW(_val);}
    virtual binIO_t&    operator<<(double _val){return opHelperW(_val);}
    virtual binIO_t&    operator,(int len);
    virtual binIO_t&    operator>>(void* _buff);
    virtual binIO_t&    operator<<(const void* _buff);

};

template <typename T> binIO_t& binIO_t::opHelperW(T& _val)
{
    if(0 > fwrite(&_val,sizeof(T),1,pFile))
        throw writeErr_e;

    return *this;
}

template <typename T> binIO_t& binIO_t::opHelperR(T& _val)
{
    if(0 >= fread(&_val,sizeof(T),1,pFile))
        throw readErr_e;

    return *this;
}
    

#endif //__BINARY_IO_H