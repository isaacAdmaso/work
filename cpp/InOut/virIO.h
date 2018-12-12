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

#include <stdio.h>
#include <string>

using namespace std;




class virIO_t
{
   
private:
    int     status;
    
protected:
    string      m_path;
    string      m_mode;
    FILE        *pFile;


public:
    enum io_state{
        ok_e, 
		cant_open_file_e, 
		bad_access_e,
		writeErr_e,
        readErr_e
    };
    virtual     ~virIO_t() = 0;
    virIO_t():status(0),pFile(0){}
    virIO_t(string &_nameF,string &mode):status(0){openHelper(_nameF,mode);}

    void        setStatus(int _stat){status = _stat;}
    virtual int         getStatus(){return status;}
    void        openHelper(string _nameF,string mode);
    void        setPos(size_t _pos){ fseek(pFile,_pos,SEEK_SET);}
    size_t      getPos(){return ftell(pFile);}
    void        openFile(string _nameF,string mode){openHelper(_nameF,mode);}
    string      getPath()const {return m_path;}
    string      getMode()const {return m_mode;}
    size_t      getLength()const {size_t curr,end;curr = ftell(pFile);fseek (pFile, 0, SEEK_END);end = ftell(pFile);fseek (pFile, curr, SEEK_SET); return end;}
    virtual virIO_t&    operator>>(char& _val) = 0;
    virtual virIO_t&    operator>>(short& _val) = 0;
    virtual virIO_t&    operator>>(int& _val) = 0;
    virtual virIO_t&    operator>>(long& _val) = 0;
    virtual virIO_t&    operator>>(float& _val) = 0;
    virtual virIO_t&    operator>>(unsigned char& _val) = 0;
    virtual virIO_t&    operator>>(unsigned short& _val) = 0;
    virtual virIO_t&    operator>>(unsigned int& _val) = 0;                       
    virtual virIO_t&    operator>>(unsigned long& _val) = 0;
    virtual virIO_t&    operator>>(double& _val) = 0;
    virtual virIO_t&    operator<<(char _val) = 0;
    virtual virIO_t&    operator<<(short _val) = 0;
    virtual virIO_t&    operator<<(int _val) = 0;
    virtual virIO_t&    operator<<(long _val) = 0;
    virtual virIO_t&    operator<<(float _val) = 0;
    virtual virIO_t&    operator<<(unsigned char _val) = 0;
    virtual virIO_t&    operator<<(unsigned short _val) = 0;
    virtual virIO_t&    operator<<(unsigned int _val) = 0;
    virtual virIO_t&    operator<<(unsigned long _val) = 0;
    virtual virIO_t&    operator<<(double _val) = 0;
};


inline void virIO_t::openHelper(string _nameF,string mode)
{
    if(!(pFile  = fopen(_nameF.c_str(),mode.c_str())))
        throw cant_open_file_e;
}




#endif //__VIRTUAL_H__