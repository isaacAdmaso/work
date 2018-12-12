/**
 * @file asciiIO.h
 * @brief 
 * @version 0.1
 * @date 2018-12-11
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __ASCII_IO_H
#define __ASCII_IO_H
#include <stddef.h>
#include <stdio.h>
#include "virIO.h"



class asciiIO_t: virtual public virIO_t
{
private:
    
    template <typename T,typename U> asciiIO_t& opHelperW(T _val,U _format);
    template <typename T,typename U> asciiIO_t& opHelperR(T& _val,U _format);
    asciiIO_t(asciiIO_t& _a){}
    asciiIO_t& operator = (const asciiIO_t _a);




public:
    asciiIO_t(){}
    asciiIO_t(string &_nameF,string &mode):virIO_t(_nameF,mode){}
    

    virtual int         getStatus(){return virIO_t::getStatus();}
    virtual ~asciiIO_t(){}
    virtual asciiIO_t&    operator>>(char& _val){return opHelperR(_val,"%c");}
    virtual asciiIO_t&    operator>>(short& _val){return opHelperR(_val,"%hd");}
    virtual asciiIO_t&    operator>>(int& _val){return opHelperR(_val,"%d");}
    virtual asciiIO_t&    operator>>(long& _val){return opHelperR(_val,"%ld");}
    virtual asciiIO_t&    operator>>(float& _val){return opHelperR(_val,"%f");}
    virtual asciiIO_t&    operator>>(unsigned char& _val){return opHelperR(_val,"%hhu");}
    virtual asciiIO_t&    operator>>(unsigned short& _val){return opHelperR(_val,"%hu");}
    virtual asciiIO_t&    operator>>(unsigned int& _val){return opHelperR(_val,"%u");}
    virtual asciiIO_t&    operator>>(unsigned long& _val){return opHelperR(_val,"%ul");}
    virtual asciiIO_t&    operator>>(double& _val){return opHelperR(_val,"%f");}
    virtual asciiIO_t&    operator<<(char _val){return opHelperW(_val,"%c");}
    virtual asciiIO_t&    operator<<(short _val){return opHelperW(_val,"%hd");}
    virtual asciiIO_t&    operator<<(int _val){return opHelperW(_val,"%d");}
    virtual asciiIO_t&    operator<<(long _val){return opHelperW(_val,"%ld");}
    virtual asciiIO_t&    operator<<(float _val){return opHelperW(_val,"%f");}
    virtual asciiIO_t&    operator<<(unsigned char _val){return opHelperW(_val,"%hhu");}
    virtual asciiIO_t&    operator<<(unsigned short _val){return opHelperW(_val,"%hu");}
    virtual asciiIO_t&    operator<<(unsigned int _val){return opHelperW(_val,"%u");}
    virtual asciiIO_t&    operator<<(unsigned long _val){return opHelperW(_val,"%ul");}
    virtual asciiIO_t&    operator<<(double _val){return opHelperW(_val,"%f");}
};

template <typename T,typename U> asciiIO_t& asciiIO_t::opHelperW(T _val,U _format)
{
    if(0 > fprintf(pFile,_format,_val))
        throw writeErr_e;

    return *this;
}

template <typename T,typename U> asciiIO_t& asciiIO_t::opHelperR(T& _val,U _format)
{
    if(0 >= fscanf(pFile,_format,&_val))
        throw readErr_e;
    
    return *this;
}
    

#endif //__ASCII_IO_H