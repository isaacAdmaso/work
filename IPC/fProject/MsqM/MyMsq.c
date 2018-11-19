/**
 * @file MyMsq.h
 * @brief  handle massage queue  use system V msq
 * @version 0.1
 * @date 2018-11-18
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif

#include "MyMsq.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

#define MAX 1024


typedef struct msgbuf
{
	long  m_type;
	pid_t m_procID;
	char  m_buf[MAX];
} msgbuf;

typedef struct regbuf
{
	long	m_type;
	int 	m_procID;
} regbuf;

/**
 * @brief create or open message queue 
 * 
 * @param _premis if 0 create else open 
 */
msq_t Msq_CrInit(char* _msqName,int _premis)
{
    key_t key;
    msq_t msqid;

    if(-1 == (key = ftok(_msqName,PROJ_ID)))
    {
        return -1 ;
    }
    return ((_premis) ? (msqid = msgget(key, C_PERMIS)):(msqid = msgget(key, PERMIS)));
}

/**
 * @brief  register to message queue
 *  return -1 if error occurs in registration  
 */
int Msq_Register(msq_t _msq,long _type)
{
	regbuf reg;

    reg.m_type      = _type;
	reg.m_procID    = getpid();
	return (msgsnd(_msq, &reg, sizeof(reg) - sizeof(reg.m_type), 0));
}

/**
 * @brief  send _sizeMsg bytes pointed by _toSend using _mq 
 *  return -1 if error occurs 
 */
int Msq_Send(msq_t _mQ,long _type,void* _toSend,size_t _sizeMsg)
{
	msgbuf snd;

    snd.m_type      = _type;
    snd.m_procID    = getpid();
    memcpy(snd.m_buf, _toSend, _sizeMsg); /**<- attache the message */

    /* message size is without the message type */
    return ( msgsnd(_mQ, &snd,_sizeMsg+sizeof(snd.m_procID), 0));
}

/**
 * @brief   receive _sizeMsg bytes to _toGet using _mq  
 *  return 1 if msq empty ,-1 if error occurs ,amount of bytes in success
 */
int Msq_Receive(msq_t _mQ,long _type,void* _toGet,size_t _sizeMsg)
{
    msgbuf rcv;
    int nBytes;
    
    if(-1 == (nBytes = msgrcv(_mQ, &rcv,_sizeMsg +sizeof(rcv.m_procID), _type, 0)))
    {
        if (errno == ENOMSG)
            return 1;
    }
    memcpy(_toGet,rcv.m_buf,_sizeMsg);
    return nBytes;
}

/**
 * @brief return number of messages in queue 
 * 
 */
size_t Msq_Nmsgs(msq_t _mQ)
{
    struct msqid_ds buf;

    if (-1 == msgctl(_mQ, IPC_STAT, &buf))
    {
        return 0;
    }
    return (size_t)(buf.msg_qnum);
}

/**
 * @brief destroy msq 
 * 
 */
int Msq_Destroy(msq_t _mQ)
{
    if (-1 == msgctl(_mQ, IPC_RMID, NULL))
    {
        return 0;
    }
    return 1;
}
