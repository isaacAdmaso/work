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
#include <string>
#include "virIO.h"



class asciiIO_t: virtual public virIO_t
{
private:
    string  m_path;
    string  m_mode;
    FILE        *pFile;
    void    openHelper(string _nameF,string mode);
    template <typename T,typename U> asciiIO_t& opHelperW(T _val,U _format);
    template <typename T,typename U> asciiIO_t& opHelperR(T& _val,U _format);
    asciiIO_t(asciiIO_t& _a){}
    asciiIO_t& operator = (const asciiIO_t _a);




public:
    asciiIO_t():pFile(0){}
    asciiIO_t(string &_nameF,string &mode){openHelper(_nameF,mode);}
    void        setPos(size_t _pos){ fseek(pFile,_pos,SEEK_SET);}
    size_t      getPos(){return ftell(pFile);}
    void        openFile(string _nameF,string mode){openHelper(_nameF,mode);}
    string      getPath()const {return m_path;}
    string      getMode()const {return m_mode;}
    size_t      getLength()const {size_t curr,end;curr = ftell(pFile);fseek (pFile, 0, SEEK_END);end = ftell(pFile);fseek (pFile, curr, SEEK_SET); return end;}


    virtual int         getStatus(){return virIO_t::getStatus();}
    virtual ~asciiIO_t(){fclose(pFile);}
    virtual asciiIO_t&    operator>>(char& _val){return opHelperR(_val,ch);}
    virtual asciiIO_t&    operator>>(short& _val){return opHelperR(_val,h);}
    virtual asciiIO_t&    operator>>(int& _val){return opHelperR(_val,d);}
    virtual asciiIO_t&    operator>>(long& _val){return opHelperR(_val,l);}
    virtual asciiIO_t&    operator>>(float& _val){return opHelperR(_val,f);}
    virtual asciiIO_t&    operator>>(unsigned char& _val){return opHelperR(_val,uch);}
    virtual asciiIO_t&    operator>>(unsigned short& _val){return opHelperR(_val,uh);}
    virtual asciiIO_t&    operator>>(unsigned int& _val){return opHelperR(_val,u);}
    virtual asciiIO_t&    operator>>(unsigned long& _val){return opHelperR(_val,ul);}
    virtual asciiIO_t&    operator>>(double& _val){return opHelperR(_val,f);}
    virtual asciiIO_t&    operator<<(char _val){return opHelperW(_val,ch);}
    virtual asciiIO_t&    operator<<(short _val){return opHelperW(_val,h);}
    virtual asciiIO_t&    operator<<(int _val){return opHelperW(_val,d);}
    virtual asciiIO_t&    operator<<(long _val){return opHelperW(_val,l);}
    virtual asciiIO_t&    operator<<(float _val){return opHelperW(_val,f);}
    virtual asciiIO_t&    operator<<(unsigned char _val){return opHelperW(_val,uch);}
    virtual asciiIO_t&    operator<<(unsigned short _val){return opHelperW(_val,uh);}
    virtual asciiIO_t&    operator<<(unsigned int _val){return opHelperW(_val,u);}
    virtual asciiIO_t&    operator<<(unsigned long _val){return opHelperW(_val,ul);}
    virtual asciiIO_t&    operator<<(double _val){return opHelperW(_val,f);}
};

inline void asciiIO_t::openHelper(string _nameF,string mode)
{
    if(!(pFile  = fopen(_nameF.c_str(),mode.c_str())))
        throw cant_open_file_e;
}


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