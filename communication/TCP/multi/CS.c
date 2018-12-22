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



void InitAdd(struct sockaddr_in* servaddr,Addr* _addr,int argc,char* argv[]){
	if (argc >= 3){
		_addr->m_port =  atoi(argv[1]);
		strcpy(_addr->m_ip,  argv[2]);
	}
    servaddr->sin_family = AF_INET; 
	servaddr->sin_port = htons(_addr->m_port); 
	servaddr->sin_addr.s_addr = inet_addr( _addr->m_ip );
}

int Rec(int sockfd,CS_t cs){
	int n;
	char buffer[MAXLINE],name[NAMESZ]; 
    
    n = recv(sockfd, buffer, MAXLINE,0);
	(cs) ?strcpy(name,"SERVER") :strcpy(name,"CLIENT") ; 
	buffer[n] = '\0'; 
	printf("%s Msg rec : %s  nbyts: %d\n",name, buffer,n); 
	return n;
}

int Send(int sockfd,const char* msg,size_t len,CS_t cs){
	int n;
	char name[NAMESZ]; 

	n = send(sockfd, msg, len,0); 
    (cs) ?strcpy(name,"SERVER") :strcpy(name,"CLIENT") ; 
	printf("my msg is: %s nbyts is: %d\n",msg,n);
	return n;
}


void Conn(int* sockfd,struct sockaddr_in* servaddr){

	if ( (*sockfd = socket(AF_INET, SOCK_STREAM, 0) ) < 0 ) { 
				perror("socket creation failed"); 
				exit(EXIT_FAILURE); 
	}  
	printf("socket created with fd: %d\n",*sockfd);
	if((connect(*sockfd,(struct sockaddr *)servaddr,sizeof(*servaddr))) < 0){
		perror ("unable connect");
		exit(EXIT_FAILURE); 
	}
	printf("connected to ip: %s\tport: %d\n",inet_ntoa(servaddr->sin_addr),ntohs(servaddr->sin_port));
}
