#include "CS.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>




int main(int argc,char* argv[]) { 
	int sockfd,sockfdOther, loop = 1; 
	char msg[MAXLINE]; 
	struct sockaddr_in servaddr, cliaddr; 
	unsigned int len = sizeof(cliaddr);
	Addr addr = {0,"0"};
	CS_t cs = SERVER;


	addr.m_port = (argc < 2)? PORT: atoi(argv[1]);
	

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 
	printf("socket created with fd: %d\n",sockfd);

	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
	
	InitAdd(&servaddr,&addr);
	if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ){ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	printf("bind: ip: %s\tport: %d\n",inet_ntoa(servaddr.sin_addr),ntohs(servaddr.sin_port));

	if (listen(sockfd, 1) != 0){
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	}
	printf("Listen..........\n");
	if ((sockfdOther = accept(sockfd, (struct sockaddr *) &cliaddr, &len)) < 0){
		perror("accept failed"); 
		exit(EXIT_FAILURE); 
	}
	printf("accept connection to ip: %s\tport: %d\n",inet_ntoa(cliaddr.sin_addr),ntohs(cliaddr.sin_port));
	Rec(sockfdOther,cs); 
	printf("enter msg:\n");
	fgets (msg , MAXLINE , stdin);
	Send(sockfdOther,msg,strlen(msg),cs);
	shutdown(sockfd,0);
	close(sockfd);
	return 0; 
} 
