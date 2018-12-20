/**
 * @file clientserver.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-19
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __CS_H__
#define __CS_H__

#include <netinet/in.h> 


typedef struct sockaddr_in Socket_t;

void InitSocket(Socket_t * _cs,int _port, char* IntAddr){

    _cs->sin_family = AF_INET; 
    _cs->sin_port = htons(_port); 
    _cs->sin_addr.s_addr = inet_addr(IntAddr); 
}



#endif /*__CS_H__*/