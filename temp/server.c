// Server side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>
#include "CS.h" 




int main() { 
	int sockfd; 
	char *msg = "Hello from server"; 
	struct sockaddr_in servaddr, cliaddr; 
	int len, n; 
	
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
	
	InitAddS(&servaddr);
	if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ){ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	n = Rec(sockfd,&cliaddr,&len); 
	printf("client ip is: '%s'     client port is: %d\n",inet_ntoa(cliaddr.sin_addr),ntohs(cliaddr.sin_port));
	Send(sockfd,(const char*) msg,& cliaddr,& len);
	printf("Hello message sent.\n"); 
	
	return 0; 
} 
