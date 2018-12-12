/**
 * @file binIO.cpp
 * @brief 
 * @version 0.1
 * @date 2018-12-11
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <stdio.h>
#include "binIO.h"
using namespace std;


binIO_t&    binIO_t::operator,(int len)
{
    switch(m_shiftMode)
    {
        case 1:
            if(0 > fwrite(m_tempBuffPtr,1,len,pFile))
                throw writeErr_e;
            break;
        case 0:
            if( 0 >= fread(m_tempBuffPtr,1,len,pFile))
                throw readErr_e;
        default:
            break;
    }
    return *this;
}
binIO_t&    binIO_t::operator>>(void* _buff)
{
    m_shiftMode = 0;
    m_tempBuffPtr = _buff;
    return *this;
}
binIO_t&    binIO_t::operator<<(const void* _buff)
{
    m_shiftMode = 1;
    m_tempBuffPtr =(void*) _buff;

    return *this;
}


