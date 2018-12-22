/**
 * @file client.c
 * @brief 
 * @version 0.1
 * @date 2018-12-21
 * 
 * @copyright Copyright (c) 2018
 * 
 */



#include "CS.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>

#define MAXAMOUNT   1
#define DIS         -1
#define CONN        2


void SeAndRe(int sockfd,int clientN, char* msg,CS_t cs);


int main(int argc,char* argv[]) { 
	int sockfdArr[MAXAMOUNT],i,randomN = -1; 
	Addr addr = {PORT,IP};
	char msg[MAXLINE]; 
	struct sockaddr_in	 servaddr; 
	CS_t cs = CLIENT;

	memset(&servaddr, 0, sizeof(servaddr)); 
	InitAdd(&servaddr,&addr,argc,argv);
    for(i = 0;i < MAXAMOUNT; ++i)
        sockfdArr[i] = DIS;

    srand(time(NULL));
    while(1){
        for(i = 0;i < MAXAMOUNT; ++i){
            randomN = rand()%10;
            if( (sockfdArr[i] == DIS) ){
                if(randomN < 3){
                    Conn(&(sockfdArr[i]),&servaddr);
                }
            }else if( sockfdArr[i] > CONN ){
                if(randomN < 1){
                    close(sockfdArr[i]); 
                }else if(randomN < 4){
                    SeAndRe(sockfdArr[i],i, msg, cs);
                }
            }
        }
    }
	return 0; 
} 

void SeAndRe(int sockfd,int clientN, char* msg,CS_t cs){
    snprintf ( msg, MAXLINE, "Hello from client #%d\n",clientN);
    fwrite (msg , sizeof(char), strlen(msg), stdout);
    if(Send(sockfd,msg,strlen(msg),cs) <= 0 ){
        printf("%d\n",sockfd);
        perror ("unable to send");
        exit(EXIT_FAILURE); 
    }
    if(Rec(sockfd,cs) < 0 ){
        perror ("unable to receive");
        exit(EXIT_FAILURE); 
    }
}
