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
#include "../../errorHandle.h"

#define MAXAMOUNT   1
#define DIS         -1
#define CONN        2

const char clientMsg[] =  "Hello from client #%d\n";

void SeAndRe(int sockfd,int clientN, char* msg,CS_t cs);


int main(int argc,char* argv[]) { 
	int sockfdArr[MAXAMOUNT],i,randomN = -1,rtVal; 
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
            printf("\nrandomN:\t%d\n",randomN);
            fflush(stdout);
            if( (sockfdArr[i] == DIS) ){
                if(randomN < 3){
                    rtVal = Conn(&(sockfdArr[i]),&servaddr);
                    HANDLE_ERR_EXIT(rtVal < 0,rtVal,"connection");
                	printf("connected to ip: %s\tport: %d\n",inet_ntoa(servaddr.sin_addr)
                        ,ntohs(servaddr.sin_port));
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
    int rtVal;
    snprintf ( msg, MAXLINE, clientMsg,clientN);
    fwrite (msg , sizeof(char), strlen(msg), stdout);

    rtVal = Send(sockfd,msg,strlen(msg),cs);
    HANDLE_ERR_EXIT(rtVal <= 0,rtVal,"send");

    rtVal = Rec(sockfd,cs);
    HANDLE_ERR_EXIT(rtVal <= 0,rtVal,"receive");
}

