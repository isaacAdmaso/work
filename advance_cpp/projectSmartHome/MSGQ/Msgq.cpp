/**
 * @file Msgq.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-08
 *        
 * 
 * Link with -lrt.



 * @copyright Copyright (c) 2019
 * 
 */
#include <errno.h>
#include <mqueue.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <string.h>          /*For memset() and strerror(_errnoN) */

#include "Msgq.h"
#include <iostream>


Msgq::Msgq(std::string _msqName,size_t _maxmsg,size_t _msgsize)
{
    struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = _maxmsg;
    attr.mq_msgsize = _msgsize;
    attr.mq_curmsgs = 0;
    
    m_mq = mq_open(_msqName.c_str(), O_CREAT | O_RDWR , 0644, &attr);
    m_mqName = _msqName;

}

Msgq::~Msgq()
{
    mq_close(m_mq);
    mq_unlink(m_mqName.c_str());
}

int Msgq::Msq_Send(void* _toSend,size_t _sizeMsg)
{
    int rtVal;

    if((rtVal = (int)mq_send(m_mq, (char*)_toSend, _sizeMsg, 0))) 
        throw rtVal;
    
    return rtVal;
}

int Msgq::Msq_Receive(void* _toGet,size_t _sizeMsg)
{
    int rtVal;
    memset( _toGet,0x00,_sizeMsg);
    std::cout<< m_mq<<std::endl;
    if(-1 == (rtVal = (int)mq_receive(m_mq,(char*)_toGet,_sizeMsg, NULL)))
        throw rtVal;

    return rtVal; 
}
