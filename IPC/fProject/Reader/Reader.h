/**
 * @file Reader.h
 * @brief read from file and send struct trow msq 
 * @version 0.1
 * @date 2018-11-20
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __READER_H__
#define __READER_H__


#define MSG_TYPE_PING		  5
#define MSG_TYPE_REGISTRAR	  7
#define MSG_TYPE_PONG	  	  9


typedef void* (*PtrFunc)(char* _lineCDR);

#endif /*__READER_H__*/