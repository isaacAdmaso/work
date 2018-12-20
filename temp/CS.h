/**
 * @file CS.h
 * @brief 
 * @version 0.1
 * @date 2018-12-20
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __CS_H__
#define __CS_H__

void InitAddS(struct sockaddr_in* servaddr);

void InitAddC(struct sockaddr_in* servaddr);

int Rec(int sockfd,struct sockaddr_in* cliaddr,int* len);

int Send(int sockfd,const char* msg,struct sockaddr_in* cliaddr,int* len);


#endif /*__CS_H__*/