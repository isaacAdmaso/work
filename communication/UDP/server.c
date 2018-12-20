#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>
#include "CS.h" 




int main(int argc,char* argv[]) { 
	int sockfd, loop = 1; 
	char msg[MAXLINE]; 
	struct sockaddr_in servaddr, cliaddr; 
	Addr addr = {0,"0"};
	CS_t cs = SERVER;


	addr.m_port = (argc < 2)? PORT: atoi(argv[1]);
	

	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
	
	InitAdd(&servaddr,&addr);
	if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ){ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 

	while(loop){

		Rec(sockfd,&cliaddr,cs); 
		printf("enter msg:\n");
		fflush(stdout);
		fgets (msg , MAXLINE , stdin);
		Send(sockfd,(const char*) msg,& cliaddr,cs);
		printf("enter 0 to stop else run:\n");
		fflush(stdout);
		scanf("%d",&loop);
	}
	close(sockfd); 

	return 0; 
} 
