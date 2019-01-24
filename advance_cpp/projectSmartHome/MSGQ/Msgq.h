/**
 * @file Msgq.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-08
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __MSGQ_H__
#define __MSGQ_H__
#include <string>


class Msgq
{
public:

    Msgq(std::string _msqName,size_t _maxmsg = 20 ,size_t _msgsize = 1024);
    ~Msgq();
    int Msq_Send(void* _toSend,size_t _sizeMsg);
    int Msq_Receive(void* _toGet,size_t _sizeMsg);

private:
    int m_mq;
    std::string m_mqName;
};


#endif //__MSGQ_H__