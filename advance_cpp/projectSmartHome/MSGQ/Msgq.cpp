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
#include "Msgq.h"


Msgq::Msgq(std::string _msqName)
{
    m_mqName = _msqName;
    m_mq = mq_open(_msqName.c_str(),O_RDWR);
    //HANDLE_ERR_EXIT(m_mq == -1,m_mq,"open_msg");
}

Msgq::~Msgq()
{
    mq_close(m_mq);
    mq_unlink(m_mqName.c_str());
}

int Msgq::Msq_Send(void* _toSend,size_t _sizeMsg)
{
    int rtVal;

    if(rtVal = mq_send(m_mq, (char*)_toSend, _sizeMsg, 0))
        throw rtVal;
    return rtVal;
}

ssize_t Msgq::Msq_Receive(void* _toGet,size_t _sizeMsg)
{
    ssize_t rtVal;

    if(-1 == (rtVal = mq_receive(m_mq,(char*)_toGet,_sizeMsg, NULL)))
        throw rtVal;
    return rtVal; 
}
