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
    int sockfd, len, n = 3; 
    char buffer[MAXLINE]; 
    char str[MAXLINE]; 
    struct sockaddr_in servaddr, cliaddr; 
    
    printf("starting server\n");
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
      
    memset(&servaddr, 0, sizeof(servaddr)); 
      
    servaddr.sin_family    = AF_INET; 
    servaddr.sin_port = htons(atoi(argv[1])); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
      
    if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 ) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    printf("entering while. socket id is :%d\n",sockfd);
    while (n > 2){
        n = recvfrom(sockfd, (char *)buffer, MAXLINE, 0, ( struct sockaddr *) &cliaddr,(unsigned int *) &len);
        if(n <= 0 ){
            perror("rec fail");
            exit(EXIT_FAILURE); 
        } 
        buffer[n] = '\0'; 
        printf("Client msg: '%s' client sockaddr len is %d  client ip is: '%s'     client port is: %d\n", str,len,inet_ntoa(cliaddr.sin_addr),ntohs(cliaddr.sin_port));
        printf("retrun msg\n");
        scanf("%s",str); 
        printf("eko : '%s', of size %ld to socketId: %d\n", str,strlen(str)+1,sockfd);

        n = sendto(sockfd, (const char *)str, strlen(str)+1, 0, (const struct sockaddr *) &cliaddr,sizeof(cliaddr)); 
        if(n < 0 ){
            printf("%d ",n);
            perror("sendto fail");
            exit(EXIT_FAILURE); 
        } 
        printf("enter 0 to stop!");
        scanf("%d",&n);
        if(!n)
            break;
    } 
    close(sockfd); 
    return 0; 
} 