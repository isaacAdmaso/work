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
#include "CS.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define MAXLINE 1024 
#define NAMESZ	16
#define PORT 8080
#define IP   "127.0.0.1"

typedef struct Addr{
    int     m_port;
    char    m_ip[16];
}Addr;

typedef enum CS{ SERVER,CLIENT }CS_t;

void InitAdd(struct sockaddr_in* servaddr,Addr* _addr,int argc,char* argv[]);

void Conn(int* sockfd,struct sockaddr_in* servaddr);

int Rec(int sockfd,CS_t cs);

int Send(int sockfd,const char* msg,size_t len,CS_t cs);


#endif /*__CS_H__*/