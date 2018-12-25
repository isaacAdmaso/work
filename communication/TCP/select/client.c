/**
 * @file client.c
 * @brief 
 * @version 0.1
 * @date 2018-12-21
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>
#include <errno.h>
#include "CS.h" 
#include "errorHandle.h"

#define MAXAMOUNT   1000
#define DIS         -1
#define CONN        2

const char clientMsg[] =  "Hello from client #%d\n";

void SeAndRe(int* sockfd,int clientN, char* msg,CS_t cs);
void ClientInit(int* sockfdArr,struct sockaddr_in*	 servaddr,int argc,char* argv[]);
void ConnectServer(int* sockfd, struct sockaddr_in*  servaddr);
void ClientRun(int* sockfd, char* msg,int numC);



int main(int argc,char* argv[]) { 
	int sockfdArr[MAXAMOUNT],i; 
	char msg[MAXLINE]; 
	struct sockaddr_in	 servaddr; 

    ClientInit(sockfdArr, &servaddr, argc, argv);
	
    srand(time(NULL));
    while(1){
        for(i = 0;i < MAXAMOUNT; ++i){
            ConnectServer(sockfdArr + i,&servaddr);
            ClientRun(sockfdArr + i,msg,i);
        }
    }
	return 0; 
}





void ClientInit(int* sockfdArr,struct sockaddr_in*	 servaddr,int argc,char* argv[]){
	Addr addr = {PORT,IP};
    int i;
	CS_t cs = CLIENT;


    memset(servaddr, 0, sizeof(*servaddr)); 
	InitAdd(servaddr,&addr,argc,argv,cs);
    for(i = 0;i < MAXAMOUNT; ++i)
        sockfdArr[i] = DIS;

}

void SeAndRe(int* sockfd,int clientN, char* msg,CS_t cs){
    int rtVal;
    snprintf ( msg, MAXLINE, clientMsg,clientN);
    fwrite (msg , sizeof(char), strlen(msg), stdout);

    rtVal = Send(*sockfd,msg,strlen(msg),cs);
    HANDLE_ERR_EXIT(rtVal < 0,rtVal,"send");
    if(rtVal <= 0){
        close(*sockfd);
        *sockfd = -1;
    }
    rtVal = Rec(*sockfd,cs);
    HANDLE_ERR_EXIT(rtVal < 0,rtVal,"receive");
    if(rtVal == 0){
        close(*sockfd);
        *sockfd = -1;
    }
}

void ConnectServer(int* sockfd, struct sockaddr_in*  servaddr){
    int rtVal,randomN;

    randomN = rand()%10;
    if( (*sockfd == DIS) ){
        if(randomN < 3){
            rtVal = Conn(sockfd,servaddr);
            if(!HANDLE_ERR_NO_EXIT(rtVal < 0,rtVal,"connection")){
                printf("connected to ip: %s\tport: %d\n",inet_ntoa(servaddr->sin_addr)
                    ,ntohs(servaddr->sin_port));
            }
        }
    }
}

void ClientRun(int* sockfd, char* msg,int numC){
    int randomN;
	CS_t cs = CLIENT;

    randomN = rand()%10;
    if( *sockfd > CONN ){
        if(randomN < 1){
            shutdown(*sockfd,0);
            close(*sockfd);
            *sockfd = -1; 
        }else if(randomN < 4){
            SeAndRe(sockfd,numC, msg, cs);
        }
    }
}