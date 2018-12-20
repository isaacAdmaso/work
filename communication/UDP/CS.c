/**
 * @file CS.c
 * @brief 
 * @version 0.1
 * @date 2018-12-20
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>
#include "CS.h" 



void InitAdd(struct sockaddr_in* servaddr,Addr* _addr){
    servaddr->sin_family = AF_INET; 
	servaddr->sin_port = htons(_addr->m_port); 
	servaddr->sin_addr.s_addr = inet_addr( _addr->m_ip );
}

int Rec(int sockfd,struct sockaddr_in* addr,CS_t cs){
	int n;
	char buffer[MAXLINE],name[NAMESZ]; 
	unsigned int len = sizeof(*addr);
	n = recvfrom(sockfd, buffer, MAXLINE,0, ( struct sockaddr *) addr, &len);

	(cs) ?strcpy(name,"SERVER") :strcpy(name,"CLIENT") ; 

	buffer[n] = '\0'; 
	printf("Msg rec : %s\n", buffer); 
	printf("'%s' ip is: '%s'     client port is: %d  n = %d\n",name,inet_ntoa(addr->sin_addr),ntohs(addr->sin_port),n);

	return n;
}

int Send(int sockfd,const char* msg,struct sockaddr_in* addr,CS_t cs){
	unsigned int len = sizeof(*addr);
	return sendto(sockfd, msg, strlen(msg),0, (const struct sockaddr *) addr,len); 
}




