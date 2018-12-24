#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>
#include <errno.h>
#include <signal.h>
#include <stdint.h>
#include <fcntl.h>
#include "CS.h" 
#include "errorHandle.h"
#include "list_functions.h"




#define CLIENTNUM  1000


int got_usr1 = 0;
void sigusr1_handler(int sig);
void SigInit(struct sigaction* sa);
void ServerInit(int*  sockfd, struct sockaddr_in* servaddr,int argc,char* argv[]);
void AddClient(List* list,int sockfd);
void SendRecv(List* list, char* msg);
void ExitClean(List* list, int* sockfd);






int main(int argc,char* argv[]) { 
	int sockfd; 
	char msg[MAXLINE] = "Hello from Server"; 
	struct sockaddr_in servaddr; 
	struct sigaction sa;
	List* list = NULL;

	list = List_Create();

	SigInit(&sa);

	ServerInit(&sockfd,&servaddr,argc,argv);

	while(!got_usr1){
		AddClient(list,sockfd);
		SendRecv(list,msg);
	}
	ExitClean(list, &sockfd);
	return 0; 
} 










void sigusr1_handler(int sig)
{
	got_usr1 = 1;
}

void SigInit(struct sigaction* sa){
	int rtVal;

	sa->sa_handler = sigusr1_handler;
	sa->sa_flags = 0;
	rtVal = sigemptyset(&(sa->sa_mask));
	HANDLE_ERR_NO_EXIT(rtVal == -1, rtVal, "sigaction");

	rtVal = sigaction(SIGINT, sa, NULL);
	HANDLE_ERR_NO_EXIT(rtVal == -1, rtVal, "sigaction ");

}

void ServerInit(int*  sockfd, struct sockaddr_in* servaddr,int argc,char* argv[]){
	int rtVal,optVal = 1;
	Addr addr = {0,"0"};
	Block_t nBlock = NO_BLOCK;
	CS_t cs = SERVER;



	*sockfd = socket(AF_INET, SOCK_STREAM, 0);
	HANDLE_ERR_EXIT(*sockfd < 3,*sockfd,"create sock");


	rtVal = setsockopt(*sockfd,SOL_SOCKET,SO_REUSEADDR,&optVal,sizeof(optVal));
	HANDLE_ERR_EXIT(rtVal < 0,rtVal,"reuse");

	rtVal = SetSockBlock(*sockfd, nBlock);
	HANDLE_ERR_EXIT(!rtVal,*sockfd,"SetSockBlock");

	printf("socket created with fd: %d\n", *sockfd);

	memset(servaddr, 0, sizeof(*servaddr)); 

	InitAdd(servaddr,&addr,argc,argv,cs);
	
	rtVal = bind(*sockfd, (const struct sockaddr *)servaddr, sizeof(*servaddr));
	HANDLE_ERR_EXIT(rtVal < 0,rtVal,"bind ");
	printf("bind: ip: %s\tport: %d\n",inet_ntoa(servaddr->sin_addr),ntohs(servaddr->sin_port));

	rtVal = listen(*sockfd, CLIENTNUM);
	HANDLE_ERR_EXIT(rtVal != 0,rtVal,"listen ");
	printf("Server Listen..........\n");
} 



void AddClient(List* list,int sockfd){
	unsigned int len;
	int tempSocket, rtBool, rtVal;
	Block_t nBlock = NO_BLOCK;
	struct sockaddr_in cliaddr;

	len = sizeof(struct sockaddr_in);
	if(List_Size(list) <  CLIENTNUM){
		memset(&cliaddr, 0, len); 
		tempSocket = accept(sockfd, (struct sockaddr *) &cliaddr, &len);
		rtBool = ((tempSocket < 0) && (errno != EAGAIN) && (errno != EWOULDBLOCK));
		HANDLE_ERR_EXIT(rtBool,tempSocket,"accept");

		if(tempSocket > 0){
			rtVal = SetSockBlock(tempSocket,nBlock);
			HANDLE_ERR_EXIT(!rtVal,tempSocket,"SetSockBlock");
/*
			printf("accept connection to ip: %s\tport: %d\n",inet_ntoa(cliaddr.sin_addr),ntohs(cliaddr.sin_port));
*/
			rtVal = List_PushTail(list, (void*)(intptr_t)tempSocket);
			HANDLE_ERR_EXIT(rtVal != 0,rtVal,"list push");
		}
	}
}


void SendRecv(List* list, char* msg){
	ListItr bItr,eItr,tempItr;
	CS_t cs = SERVER;
	int rtBool,rtVal,tempSocket;

	bItr = ListItr_Begin(list);
	tempItr = bItr;
	eItr = ListItr_End(list);

	while(!ListItr_Equals(tempItr,eItr)){

		tempSocket = (intptr_t)ListItr_Get(tempItr);
		bItr = ListItr_Next(bItr);

		rtVal = Rec(tempSocket,cs);
		rtBool = ((rtVal < 0) && (errno != EAGAIN) && (errno != EWOULDBLOCK));
		HANDLE_ERR_EXIT(rtBool,rtVal,"receive ");
		if( rtVal > 0 ){
			rtVal = Send(tempSocket,msg,strlen(msg),cs);
			rtBool = ((rtVal < 0) && (errno != EAGAIN) && (errno != EWOULDBLOCK));
			HANDLE_ERR_EXIT(rtBool,rtVal,"send");

		}else if (rtVal == 0){
			close(tempSocket);
			ListItr_Remove(tempItr);
		}
		tempItr = bItr;
	}
}

void ExitClean(List* list, int* sockfd){
	ListItr bItr,eItr,tempItr;
	int tempSocket;

	bItr = ListItr_Begin(list);
	eItr = ListItr_End(list);
	while(!ListItr_Equals(tempItr,eItr)){
		tempSocket = (intptr_t)ListItr_Get(tempItr);
		bItr = ListItr_Next(bItr);
		close(tempSocket);
		ListItr_Remove(tempItr);
		tempItr = bItr;
	}
	List_Destroy(&list,NULL);
	shutdown(*sockfd,0);
	close(*sockfd);
	printf("\nall resources closed\n");
}
