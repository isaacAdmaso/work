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
    void    openHelper(string _nameF,string mode);
    template <typename T> binIO_t& opHelperW(T& _val,size_t _size,size_t _count);
    template <typename T> binIO_t& opHelperR(T& _val,size_t _size,size_t _count);
    binIO_t(binIO_t& _a){}
    binIO_t& operator = (const binIO_t _a);




public:
    binIO_t():pFile(0){}
    binIO_t(string &_nameF,string &mode){openHelper(_nameF,mode);}
    void        setPos(size_t _pos){ fseek(pFile,_pos,SEEK_SET);}
    size_t      getPos(){return ftell(pFile);}
    void        openFile(string _nameF,string mode){openHelper(_nameF,mode);}
    string      getPath()const {return m_path;}
    string      getMode()const {return m_mode;}
    size_t      getLength()const {fseek (pFile, 0, SEEK_END); return ftell(pFile);}


    virtual int         getStatus(){return virIO_t::getStatus();}
    virtual ~binIO_t(){fclose(pFile);}
    virtual binIO_t&    operator>>(char& _val){return opHelperR<char>(_val,sizeof(char),1);}
    virtual binIO_t&    operator>>(short& _val){return opHelperR<short>(_val,sizeof(short),1);}
    virtual binIO_t&    operator>>(int& _val){return opHelperR<int>(_val,sizeof(int),1);}
    virtual binIO_t&    operator>>(long& _val){return opHelperR<long>(_val,sizeof(long),1);}
    virtual binIO_t&    operator>>(float& _val){return opHelperR<float>(_val,sizeof(float),1);}
    virtual binIO_t&    operator>>(unsigned char& _val){return opHelperR<unsigned char>(_val,sizeof(char),1);}
    virtual binIO_t&    operator>>(unsigned short& _val){return opHelperR<unsigned short>(_val,sizeof(short),1);}
    virtual binIO_t&    operator>>(unsigned int& _val){return opHelperR<unsigned int>(_val,sizeof(int),1);}
    virtual binIO_t&    operator>>(unsigned long& _val){return opHelperR<unsigned long>(_val,sizeof(long),1);}
    virtual binIO_t&    operator>>(double& _val){return opHelperR<double>(_val,sizeof(double),1);}
    virtual binIO_t&    operator<<(char _val){return opHelperW<char>(_val,sizeof(char),1);}
    virtual binIO_t&    operator<<(short _val){return opHelperW<short>(_val,sizeof(short),1);}
    virtual binIO_t&    operator<<(int _val){return opHelperW<int>(_val,sizeof(int),1);}
    virtual binIO_t&    operator<<(long _val){return opHelperW<long>(_val,sizeof(long),1);}
    virtual binIO_t&    operator<<(float _val){return opHelperW<float>(_val,sizeof(float),1);}
    virtual binIO_t&    operator<<(unsigned char _val){return opHelperW<unsigned char>(_val,sizeof(char),1);}
    virtual binIO_t&    operator<<(unsigned short _val){return opHelperW<unsigned short>(_val,sizeof(short),1);}
    virtual binIO_t&    operator<<(unsigned int _val){return opHelperW<unsigned int>(_val,sizeof(int),1);}
    virtual binIO_t&    operator<<(unsigned long _val){return opHelperW<unsigned long>(_val,sizeof(long),1);}
    virtual binIO_t&    operator<<(double _val){return opHelperW<double>(_val,sizeof(double),1);}
    //virtual binIO_t&    operator,(int len);
};

inline void binIO_t::openHelper(string _nameF,string mode)
{
    try{
        if(!(pFile  = fopen(_nameF.c_str(),mode.c_str())))
            throw cant_open_file_e;
    }
    catch(enum virIO_t::io_state ex){
        virIO_t::setStatus(ex);
    }
}
//size_t _size,size_t _count

template <typename T> binIO_t& binIO_t::opHelperW(T& _val,size_t _size,size_t _count)
{
    try{
        if(0 > fwrite(pFile,_val,_size,_count))
        {
            throw writeErr_e;
        }else{
            fflush(pFile);
        }
    }catch(enum virIO_t::io_state ex){
        setStatus(ex);
    }
    return *this;
}

template <typename T> binIO_t& binIO_t::opHelperR(T& _val,size_t _size,size_t _count)
{
    try{
        if(0 >= fread(pFile,_format,&_val))
            throw readErr_e;
    }catch(enum virIO_t::io_state ex){
        setStatus(ex);
    }
    return *this;
}
    

#endif //__BINARY_IO_H