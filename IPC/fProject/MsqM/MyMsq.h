/**
 * @file MyMsq.h
 * @brief  handle massage queue  use system V msq all return 0 if error
 * @version 0.1
 * @date 2018-11-18
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __MSQ_H__
#define __MSQ_H__


#include <stddef.h>
#define PERMIS      0666
#define C_PERMIS    0666 | IPC_CREAT | IPC_EXCL
#define PROJ_ID     1



typedef int msq_t;

/**create or open message queue 
 * @param _premis if 0 create else join
 * return msq if success else -1 
 */
msq_t Msq_CrInit(char* _msqName,int _premis);

/**
 * @brief  register to message queue
 *  return -1 if error occurs in registration  
 */
int Msq_Register(msq_t _msq,long _type);

/**
 * @brief  send _sizeMsg bytes pointed by _toSend using _mq 
 *  return -1 if error occurs
 */
int Msq_Send(msq_t _mQ, long _type,void* _toSend,size_t _sizeMsg);

/**
 * @brief   receive _sizeMsg bytes to _toGet using _mq  
 *  return 1 if msq empty ,-1 if error occurs ,amount of bytes in success
 */
int Msq_Receive(msq_t _mQ,long _type,void* _toGet,size_t _sizeMsg);

/**
 * @brief return number of messages in queue 
 * 
 */
size_t Msq_Nmsgs(msq_t _mQ);

/**Destroy msq */
int Msq_Destroy(msq_t _mQ);

#endif /*__MSQ_H__*/    


