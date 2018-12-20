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
	int sockfd; 
	Addr addr = {PORT,IP};
	char msg[MAXLINE]; 
	struct sockaddr_in	 servaddr; 
	CS_t cs = CLIENT;

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 

	memset(&servaddr, 0, sizeof(servaddr)); 

	if (argc < 3){
		addr.m_port = PORT;
		strcpy(addr.m_ip,  IP);
	}else{
		addr.m_port =  atoi(argv[1]);
		strcpy(addr.m_ip,  argv[2]);
	}

	InitAdd(&servaddr,&addr);
    
    if((connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))) < 0){
        perror ("unable connect");
		exit(EXIT_FAILURE); 
    }
	
    printf("enter msg:\n");
    fgets (msg , MAXLINE , stdin);

    Send(sockfd,msg,strlen(msg)+1,cs);
    Rec(sockfd,cs);
	close(sockfd); 

	return 0; 
} 
