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


class memManager_t
{
private:
    char*   m_CurrentPtr;
    char*   m_StartPos;
    char*   m_maxWritten;
    int     m_size;
    static int  capacity;

    memManager_t& operator = (const memManager_t _m);


protected:
    ~memManager_t(){delete [] m_StartPos;}
public:
    memManager_t():m_CurrentPtr(new char[capacity]),m_StartPos(m_CurrentPtr),m_maxWritten(m_StartPos),m_size(capacity){}

    memManager_t(int _memSize):m_CurrentPtr(new char[_memSize]),m_StartPos(m_CurrentPtr),m_maxWritten(m_StartPos),m_size(_memSize){}

    void setNewMem(int _memSize){this->~memManager_t();m_StartPos = m_CurrentPtr = new char[_memSize];m_size = _memSize;m_maxWritten = m_StartPos;}

    void setMemPtr(int _memSize){m_CurrentPtr = (m_StartPos + _memSize);}
    bool isEmpty(){return (m_StartPos+m_size) == m_maxWritten;}
    int  leftSize(){return (m_size - (m_maxWritten - m_StartPos));}
    int  read(void *_buf, int _count){memcpy(_buf,m_CurrentPtr,_count);m_CurrentPtr += _count;if((int)(m_CurrentPtr) > (int)m_maxWritten){m_maxWritten = m_CurrentPtr;}return _count;}
    int  read(int _pos,void *_buf, int _count){m_CurrentPtr = m_StartPos + _pos;memcpy(_buf,m_CurrentPtr,_count);m_CurrentPtr += _count;if((int)(m_CurrentPtr) > (int)m_maxWritten){m_maxWritten = m_CurrentPtr;}return _count;}

};




#endif /*__MANAGER_H__*/