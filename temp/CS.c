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

#define PORT	 8080 
#define MAXLINE 1024 


void InitAddS(struct sockaddr_in* servaddr){
	servaddr->sin_family = AF_INET; // IPv4 
	servaddr->sin_addr.s_addr = INADDR_ANY; 
	servaddr->sin_port = htons(PORT); 
}

void InitAddC(struct sockaddr_in* servaddr){
    servaddr->sin_family = AF_INET; 
	servaddr->sin_port = htons(PORT); 
	servaddr->sin_addr.s_addr = inet_addr( "127.0.0.1" );
	
}

int Rec(int sockfd,struct sockaddr_in* cliaddr,int* len){
	int n;
	char buffer[MAXLINE]; 
	n = recvfrom(sockfd, buffer, MAXLINE,0, ( struct sockaddr *) cliaddr, len);
	buffer[n] = '\0'; 
	printf("Msg rec : %s\n", buffer); 
	return n;
}

int Send(int sockfd,const char* msg,struct sockaddr_in* cliaddr,int* len){
	return sendto(sockfd, msg, strlen(msg),0, (const struct sockaddr *) cliaddr,*len); 
}




