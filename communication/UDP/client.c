#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
  
#define MAXLINE 4096 

  
int main(int argc,char* argv[]) { 
    int sockfd, n = 1, len; 
    char buffer[MAXLINE]; 
    char str[MAXLINE]; 
    struct sockaddr_in   addr; 
  
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    }
        memset(&addr, 0, sizeof(addr)); 
          
        addr.sin_family = AF_INET; 
        addr.sin_port = htons(atoi(argv[1])); 
        addr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    
    while(n){
        printf("enter message:");
        scanf("%s",str);

    
        n = sendto(sockfd, (const char *)str, strlen(str),0, (const struct sockaddr *) &addr, sizeof(addr)); 
        if(n < 0){
            perror("sendto errr");
            exit(EXIT_FAILURE); 
        }
        printf("message sent to server.\n"); 
            
        n = recvfrom(sockfd, (char *)buffer, MAXLINE, 0, (struct sockaddr *) &addr, (unsigned int *)&len); 
        if(n < 0){
            perror("recv errr");
            exit(EXIT_FAILURE); 
        }
        buffer[n] = '\0'; 
        printf("Server : %s\n", buffer); 
        printf("to stop enter 0! ");
        scanf("%d",&n);
    }
      
    close(sockfd); 
    return 0; 
}
