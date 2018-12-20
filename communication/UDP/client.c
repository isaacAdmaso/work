#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h>
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include "clientserver.h"
  
#define MAXLINE 4096 
#define PORT    8080
#define INTADD  "127.0.0.1"




void RunClient(int _sockfd,Socket_t* _client){
    int n = 1,len;
    char buf[MAXLINE], msg[MAXLINE];
   
    while(1){
        printf("enter message:");
        scanf("%s",msg);
        n = sendto(_sockfd, (const char *)msg, strlen(msg),0, (const struct sockaddr *) _client, sizeof(*_client)); 
        if(n < 0){
            perror("sendto errr");
            exit(EXIT_FAILURE); 
        }
        printf("message sent to server.\n"); 
        

        n = recvfrom(_sockfd, (char *)buf, MAXLINE, 0, (struct sockaddr *) _client, (unsigned int *)&len); 
        if(n < 0){
            perror("recv errr");
            exit(EXIT_FAILURE); 
        }
        printf("Server msg: '%s' server sockaddr len is %d  server ip is: '%s'     client port is: %d\n", msg,len,inet_ntoa(_client->sin_addr),ntohs(_client->sin_port));
        
        buf[n] = '\0'; 
        printf("Server : %s\n", buf); 
        printf("to stop enter 0! ");
        scanf("%d",&n);
        if(!n)
            break;
    }

}


  
int main(int argc,char* argv[]) { 
    int  sockfd; 
    Socket_t   addr; 
  
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    }
          
    memset(&addr, 0, sizeof(addr)); 
    InitSocket(&addr,atoi(argv[1]),INTADD);
        

    RunClient(sockfd, &addr);
    
    
      
    close(sockfd); 
    return 0; 
}
