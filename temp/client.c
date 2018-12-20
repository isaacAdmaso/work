// Client side implementation of UDP client-server model 
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

int main() { 
	int sockfd; 
	char buffer[MAXLINE]; 
	char *hello = "Hello from client"; 
	struct sockaddr_in	 servaddr; 

	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 

	memset(&servaddr, 0, sizeof(servaddr)); 
	
	InitAddC(&servaddr);
	int n, len; 
	
	sendto(sockfd, (const char *)hello, strlen(hello), 
		0, (const struct sockaddr *) &servaddr, 
			sizeof(servaddr)); 
	printf("Hello message sent.\n"); 
		
	n = recvfrom(sockfd, (char *)buffer, MAXLINE, 
				0, (struct sockaddr *) &servaddr, 
				&len); 
	buffer[n] = '\0'; 
	printf("Server : %s\n", buffer); 
	printf("server ip is: '%s'     server port is: %d\n",inet_ntoa(servaddr.sin_addr),ntohs(servaddr.sin_port));

	close(sockfd); 
	return 0; 
} 
