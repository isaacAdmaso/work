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




#define CLIENTNUM  1


volatile sig_atomic_t got_usr1;
void sigusr1_handler(int sig);



int main(int argc,char* argv[]) { 
	int sockfd,tempSocket,optVal = 1,rtVal,rtBool; 
	char msg[MAXLINE] = "Hello from Server"; 
	struct sockaddr_in servaddr, cliaddr; 
	unsigned int len = sizeof(cliaddr);
	Addr addr = {0,"0"};
	CS_t cs = SERVER;
	Block_t nBlock = NO_BLOCK;
	struct sigaction sa;
	List* list = NULL;
	ListItr bItr,eItr,tempItr;
	
	
	got_usr1 = 0;
	list = List_Create();

	sa.sa_handler = sigusr1_handler;
	sa.sa_flags = 0;
	sigemptyset(&(sa.sa_mask));
	rtVal = sigaction(SIGUSR1, &sa, NULL);
	HANDLE_ERR_NO_EXIT(rtVal == -1, rtVal, "sigaction fail");

	

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	HANDLE_ERR_EXIT(sockfd < 3,sockfd,"create sock");


	rtVal = setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&optVal,sizeof(optVal));
	HANDLE_ERR_EXIT(rtVal < 0,rtVal,"reuse");
	printf("socket created with fd: %d\n",sockfd);

	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 

	InitAdd(&servaddr,&addr,argc,argv);
	
	rtVal = bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr));
	HANDLE_ERR_EXIT(rtVal < 0,rtVal,"bind ");
	printf("bind: ip: %s\tport: %d\n",inet_ntoa(servaddr.sin_addr),ntohs(servaddr.sin_port));

	rtVal = listen(sockfd, CLIENTNUM);
	HANDLE_ERR_EXIT(rtVal != 0,rtVal,"listen ");
	printf("Listen..........\n");

	while(!got_usr1){
		len = sizeof(struct sockaddr_in);
		tempSocket = accept(sockfd, (struct sockaddr *) &cliaddr, &len);
		rtBool = ((tempSocket < 0) && (errno != EAGAIN) && (errno != EWOULDBLOCK));
		HANDLE_ERR_EXIT(rtBool,tempSocket,"accept");

		if(tempSocket > 0){
			rtVal = SetSockBlock(tempSocket,nBlock);
			HANDLE_ERR_EXIT(!rtVal,tempSocket,"SetSockBlock");

			printf("accept connection to ip: %s\tport: %d\n",inet_ntoa(cliaddr.sin_addr),ntohs(cliaddr.sin_port));
			
			rtVal = List_PushTail(list, (void*)(intptr_t)tempSocket);
			HANDLE_ERR_EXIT(rtVal != 0,rtVal,"list push");
		}
		
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

			}else if(!rtVal){
				close(tempSocket);
				ListItr_Remove(tempItr);
			}
			tempItr = bItr;
		}
	}
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
	shutdown(sockfd,0);
	close(sockfd);
	printf("\nall resources closed\n");
	return 0; 
} 

void sigusr1_handler(int sig)
{
	(void)sig; // silence unused variable warning

	got_usr1 = 1;
}
