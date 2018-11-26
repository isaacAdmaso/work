/**
 * @file Dispatcher.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-11-22
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __DISPATCHER_H__
#define __DISPATCHER_H__



#define MSGQUE_REGISTRAR	"REGISTRAR"

/* The values of message types are imporant - the registrar MUST be between other two */
#define MSG_TYPE_READ		  5
#define MSG_TYPE_REGISTRAR	  7
#define MSG_TYPE_DISPATCH  	  9

typedef struct Dispatcher_t Dispatcher_t;

/**
 * @brief create dispatcher
 * TODO add int nManagers
 */
Dispatcher_t* Dispatcher_Create(int _msqId, size_t _capacity, size_t _nThreads);


/**
 * @brief  destroy dispatcher
 * 
 */
void Dispatcher_Destroy(Dispatcher_t* _dispatch);

/**
 * @brief dispatch
 * 
 */
void* Dispatcher_Run(void* _dispatch);


void* Dispatcher_ManagerPtr(Dispatcher_t* _disp);



#endif /*__DISPATCHER_H__*/ 