/**
 * @file memPool.cpp
 * @brief 
 * @version 0.1
 * @date 2018-12-05
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "memPool.h" 


bool memPool_t::setCurrPos(size_t _memSize)
{
    size_t pSize = 0,i;
    vector<memPage_t*>::iterator it = m_vec.begin();


    for (i = 0; it != m_vec.end(); ++it, ++i)
    {
        pSize = (*it)->getCapacity();
        if(pSize > _memSize)
        {
            inPage = i;
            return (*it)->setCurrPos(_memSize);
        }
        _memSize -= pSize;
    }
    return false;
}


size_t memPool_t::getCurrPos()
{
    size_t offset = 0,i;
    vector<memPage_t*>::iterator it = m_vec.begin();


    for (i = 0;i < inPage ; ++it ,++i)
    {
        offset +=  (*it)->getCapacity();
    }
    return ((m_vec[inPage])->getCurrPos() + offset);
}


    
size_t  memPool_t::realSize()
{
    size_t sumSize = 0;
    vector<memPage_t*>::iterator it = m_vec.begin();

    for (; it != m_vec.end(); ++it)
    {
        sumSize +=  (*it)->getCapacity();
    }
    return (m_vec.back())->realSize() + sumSize;
}

 
size_t  memPool_t::read(void *_buf, size_t _count)
{
    size_t count = 0,i ,realS;
    vector<memPage_t*>::iterator it = m_vec.begin();

    for(i = 0;i <= inPage;++i,++it);

    if((realSize() - getCurrPos()) == 0)
        return 0;

    count =  (*it)->realSize() - (*it)->getCurrPos();
    if(count >= _count)
        return (*it)->read(_buf,_count);

    (*it)->read(_buf,count);
    _count -= count;
    ++it;

    for (i = inPage + 1; it != m_vec.end(); ++it, ++i)
    { 
        realS = (*it)->realSize();
        if(_count < realS)
        {
            inPage = i;
            count += (*it)->read(0,_buf,_count);
            break;
        }
        (*it)->read(0,_buf,realS);
        _count -= realS;
    }
    return count;
}

size_t  memPool_t::read(size_t _pos,void *_buf, size_t _count)
{
    if(setCurrPos(_pos))
        return read(_buf,_count);
    return 0;
}

size_t  memPool_t::write(const void *_buf, size_t _count)
{
    size_t count = 0,i;
    vector<memPage_t*>::iterator it = m_vec.begin();

    for(i = 0;i <= inPage;++i,++it);

    count = (*it)->write(_buf,_count);
    ++it;
    for (i = inPage + 1; it != m_vec.end(); ++it, ++i)
    {
        if((_count - count) <= 0)
            break;
        count += (*it)->write(0,_buf,_count - count);
    }
    if(count < _count)
    {
        createFrom(_count - count);
    }
    count += (*(m_vec[++inPage])).write(_buf,_count - count);
    return count;

}
size_t  memPool_t::write(size_t _pos,const void *_buf, size_t _count)
{
    if(setCurrPos(_pos))
        return write(_buf,_count);
    return 0;    
}


