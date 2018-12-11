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


using namespace std;


const char ch[] = "%c";
const char d[] = "%d";
const char h[] = "%hd";
const char l[] = "%ld";
const char f[] = "%f";
const char uch[] = "%hhu";
const char uh[] = "%hu";
const char u[] = "%u";
const char ul[] = "%ul";

class virIO_t
{
   
private:
    int     status;
    
protected:
    virtual     ~virIO_t() = 0;
    void        setStatus(int _stat){status = _stat;}
    int         getStatus(){return status;}
    
public:
    enum io_state{
        ok_e, 
		cant_open_file_e, 
		bad_access_e,
		writeErr_e,
        readErr_e
    };
    virIO_t():status(0){}
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
    //virtual virIO_t&    operator,(int len) = 0;
};




#endif //__VIRTUAL_H__