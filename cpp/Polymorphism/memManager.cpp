/**
 * @file memManager.cpp
 * @brief 
 * @version 0.1
 * @date 2018-12-04
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "memManager.h"




size_t   memManager_t::read(void *_buf, size_t _count){

    memcpy(_buf,m_CurrentPtr,_count);

    m_CurrentPtr += _count;

    if((size_t)(m_CurrentPtr) > (size_t)m_maxWritten)
        m_maxWritten = m_CurrentPtr;

    return _count;
}

size_t    memManager_t::read(size_t _pos,void *_buf, size_t _count)
{
    m_CurrentPtr = m_StartPos + _pos;
    return this->read(_buf,_count);
}

size_t    memManager_t::write(void *_buf, size_t _count)
{
    memcpy(m_CurrentPtr,_buf,_count);

    m_CurrentPtr += _count;

    if((size_t)(m_CurrentPtr) > (size_t)m_maxWritten)
        m_maxWritten = m_CurrentPtr;

    return _count;
}

size_t    memManager_t::write(size_t _pos,void *_buf, size_t _count)
{
    m_CurrentPtr = m_StartPos + _pos;

    return this->write(_buf,_count);
}
