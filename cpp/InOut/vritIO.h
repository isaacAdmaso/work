/**
 * @file vritIO.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-11
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __VIRTUAL_H__
#define __VIRTUAL_H__
#include <stddef.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class virIO_t
{
   
private:
    FILE    *pFile;
    int     status;
    string  m_path;
    string  m_mode;
    void    openHelper(string _nameF,string mode);

    virtual ~virIO_t() = 0;
public:
    enum io_state{
        ok_e, 
		cant_open_file_e, 
		bad_access_e,
		writeErr_e,
        readErr_e
    };
    virIO_t():pFile(0),status(0){}
    virIO_t(string _nameF,string mode){openHelper(_nameF,mode);}
    void        setPos(size_t _pos){ fseek(pFile,_pos,SEEK_CUR);}
    void        openFile(string _nameF,string mode){openHelper(_nameF,mode);}
    string      getPath()const {return m_path;}
    string      getMode()const {return m_mode;}
    size_t      getLength()const {fseek (pFile, 0, SEEK_END); return ftell (pFile);}
    virtual virIO_t&    operator<<(char _val) = 0;
    virtual virIO_t&    operator>>(char _val) = 0;
    virtual virIO_t&    operator<<(short _val) = 0;
    virtual virIO_t&    operator>>(short _val) = 0;
    virtual virIO_t&    operator<<(int _val) = 0;
    virtual virIO_t&    operator>>(int _val) = 0;
    virtual virIO_t&    operator<<(int _val) = 0;
    virtual virIO_t&    operator>>(int _val) = 0;
    virtual virIO_t&    operator<<(int _val) = 0;
    virtual virIO_t&    operator>>(int _val) = 0;
    virtual virIO_t&    operator<<(int _val) = 0;
    virtual virIO_t&    operator>>(int _val) = 0;
    virtual virIO_t&    operator<<(int _val) = 0;
    virtual virIO_t&    operator>>(int _val) = 0;
    virtual virIO_t&    operator<<(int _val) = 0;
    virtual virIO_t&    operator>>(int _val) = 0;
    virtual virIO_t&    operator<<(unsigned char _val) = 0;
    virtual virIO_t&    operator>>(unsigned char _val) = 0;
    virtual virIO_t&    operator<<(unsigned short _val) = 0;
    virtual virIO_t&    operator>>(unsigned short _val) = 0;
    
};

virIO_t::~virIO_t()
{
    fclose(pFile);
}

inline void virIO_t::openHelper(string _nameF,string mode)
{
    try{
        if(!(pFile  = fopen(_nameF.c_str(),mode.c_str())))
        {
            throw cant_open_file_e;
        }
    }
    catch(enum virIO_t::io_state ex){
        status = cant_open_file_e;
    }
}


#endif //__VIRTUAL_H__