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
    size_t     m_size;
    static size_t  capacity;

    memManager_t& operator = (const memManager_t _m);


protected:
    virtual ~memManager_t(){delete [] m_StartPos;}

public:
    memManager_t():m_CurrentPtr(new char[capacity]),m_StartPos(m_CurrentPtr),m_maxWritten(m_StartPos),m_size(capacity){}

    memManager_t(size_t _memSize):m_CurrentPtr(new char[_memSize]),m_StartPos(m_CurrentPtr),m_maxWritten(m_StartPos),m_size(_memSize){}

    void setNewMem(size_t _memSize){this->~memManager_t();m_StartPos = m_CurrentPtr = new char[_memSize];m_size = _memSize;m_maxWritten = m_StartPos;}

    void setMemPtr(size_t _memSize){m_CurrentPtr = (m_StartPos + _memSize);}

    bool isEmpty(){return (m_StartPos+m_size) == m_maxWritten;}

    size_t  nLeftSize(){return (m_size - (m_maxWritten - m_StartPos));}
    
    virtual inline size_t  read(void *_buf, size_t _count);
    
    virtual inline size_t  read(size_t _pos,void *_buf, size_t _count);

    virtual inline size_t  write(void *_buf, size_t _count);

    virtual inline size_t  write(size_t _pos,void *_buf, size_t _count);

};
size_t inline  memManager_t::read(void *_buf, size_t _count){

    memcpy(_buf,m_CurrentPtr,_count);

    m_CurrentPtr += _count;

    if((size_t)(m_CurrentPtr) > (size_t)m_maxWritten)
        m_maxWritten = m_CurrentPtr;

    return _count;
}
size_t inline   memManager_t::read(size_t _pos,void *_buf, size_t _count)
{
    m_CurrentPtr = m_StartPos + _pos;

    return this->read(_buf,_count);
}
size_t inline   memManager_t::write(void *_buf, size_t _count)
{
    memcpy(m_CurrentPtr,_buf,_count);

    m_CurrentPtr += _count;

    if((size_t)(m_CurrentPtr) > (size_t)m_maxWritten)
        m_maxWritten = m_CurrentPtr;

    return _count;
}

size_t inline   memManager_t::write(size_t _pos,void *_buf, size_t _count)
{
    m_CurrentPtr = m_StartPos + _pos;

    return this->write(_buf,_count);
}



#endif //__MANAGER_H__