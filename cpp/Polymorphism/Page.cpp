/**
 * @file Page.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-05
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Page.h"


size_t Page_t::capacity = 2;


size_t  Page_t::read(void *_buf, size_t _count)
{
    return  Page_t::ReadnWrite(m_Ptr, _buf,_count);        
}


size_t  Page_t::read(size_t _pos,void *_buf, size_t _count)
{
    if(_pos < m_maxWrite)
    {
        m_current = _pos;
       return  Page_t::ReadnWrite(m_Ptr, _buf,_count);        
    }
    return 0;
}


size_t  Page_t::write(const void *_buf, size_t _count)
{
    return Page_t::ReadnWrite(_buf, m_Ptr,_count);
    
}

size_t  write(size_t _pos,const void *_buf, size_t _count)
{
    if(_pos < m_maxWrite)
    {
        m_current = _pos;
       return  Page_t::ReadnWrite(m_Ptr, _buf,_count);        
    }
    return 0;
}


static size_t Page_t::ReadnWrite(void* _buf, void* _ptr,size_t _count)
{
    if(_count > (m_capacity - m_current))
    {
        memcpy(_ptr + m_current, _buf, (m_capacity - m_current));
        m_current = m_capacity;
        m_maxWrite = m_capacity;
        return (m_capacity - m_current);
    }
    memcpy(_ptr + m_current,_buf, _count )
    m_current += _count;
    if(m_current > m_maxWrite)  
        m_maxWrite = m_current;
    return _count;

}
