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
    string  m_path;
    string  m_mode;
    FILE        *pFile;
    void*   m_tempBuffPtr;  /**save given buffer for (Read or Write) */
    int     m_shiftMode;      /**0 >> ,1 << */
    void    openHelper(string _nameF,string mode);
    template <typename T> binIO_t& opHelperW(T& _val);
    template <typename T> binIO_t& opHelperR(T& _val);
    binIO_t(binIO_t& _a){}
    binIO_t& operator = (const binIO_t _a);




public:
    binIO_t():pFile(0),m_tempBuffPtr(0),m_shiftMode(-1){}
    binIO_t(string &_nameF,string &mode):m_tempBuffPtr(0),m_shiftMode(-1){openHelper(_nameF,mode);}
    void        setPos(size_t _pos){ fseek(pFile,_pos,SEEK_SET);}
    size_t      getPos(){return ftell(pFile);}
    void        openFile(string _nameF,string mode){openHelper(_nameF,mode);}
    string      getPath()const {return m_path;}
    string      getMode()const {return m_mode;}
    size_t      getLength()const {fseek (pFile, 0, SEEK_END); return ftell(pFile);}


    virtual ~binIO_t()  {fclose(pFile);}
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

inline void binIO_t::openHelper(string _nameF,string mode)
{
    if(!(pFile  = fopen(_nameF.c_str(),mode.c_str())))
        throw cant_open_file_e;
}

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