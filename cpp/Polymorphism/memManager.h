/**
 * @file memManager.h
 * @brief 
 * @version 0.1
 * @date 2018-12-04
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __MANAGER_H__
#define __MANAGER_H__
#include <stdlib.h>
#include <string.h>

using namespace std;


class memManager_t
{
private:
    char*   m_CurrentPtr;
    char*   m_StartPos;
    char*   m_maxWritten;
    size_t     m_size;

    memManager_t& operator = (const memManager_t _m);
    memManager_t( memManager_t& _m){}


protected:
    virtual ~memManager_t(){delete [] m_StartPos;}
    virtual bool setCurrPos(size_t _memSize);

public:
    memManager_t(){}

    memManager_t(size_t _memSize):m_CurrentPtr(new char[_memSize]),m_StartPos(m_CurrentPtr),m_maxWritten(m_StartPos),m_size(_memSize){}


    virtual size_t getCurrPos(){return (m_CurrentPtr - m_StartPos);}

    virtual bool isEmpty(){return m_StartPos == m_maxWritten;}

    virtual bool isFull(){return (m_StartPos+m_size) == m_maxWritten;}

    virtual size_t  nLeftSize(){return (m_size - (m_maxWritten - m_StartPos));}

    virtual size_t  realSize(){return size_t(m_maxWritten - m_StartPos);}
    
    virtual  size_t  read(void *_buf, size_t _count);
    
    virtual  size_t  read(size_t _pos,void *_buf, size_t _count);

    virtual  size_t  write(const void *_buf, size_t _count);

    virtual  size_t  write(size_t _pos,const void *_buf, size_t _count);

};

#endif //__MANAGER_H__