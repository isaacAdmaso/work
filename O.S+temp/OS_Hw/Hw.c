#ifndef _XOPEN_SOURCE 
#define _XOPEN_SOURCE  500
#endif
#include <getopt.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

#define MAX 32
void sigint_handler(int sig)
{
	printf("\nin process \n");
    fflush(0);
}
/*
void sigint_handler(int _sig,siginfo_t *_siginfo,void* _null)
{
    printf("\nin process %ld\n",(long)_siginfo->si_pid);
    fflush(0);
    kill(_siginfo->si_pid,SIGUSR1);
}
*/

int main(int argc, char const *argv[])
{
    pid_t pid = getpid();
	struct sigaction sa;
    int parent,n,child;
   /* extern char *optarg;
	extern int optind;
    
    while ((n = getopt(argc, argv, "d:p:")) != -1)
    {
		switch (n) 
        {
		case 'd':
            child = atoi(*optarg);
			break;
		case 'p':
            parent = atoi(*optarg);
			break;
        case '?':
            
			break;
		}

    }*/
	sa.sa_handler = sigint_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
    printf("\ninside main\n");
    n = fork();
    if(n < 0)
    {
        write(2,"ERROR",MAX);
    }
    
    else if(n > 0)
    {
        if (sigaction(SIGUSR1, &sa, NULL) == -1) 
        {
		    perror("sigaction");
            exit(1);
        }   
        pause();
        kill(n,SIGUSR1);

        printf("\ninside of Parent\n");
        
    }
    else
    {
        if (sigaction(SIGUSR1, &sa, NULL) == -1) 
        {
	    	perror("sigaction");
	    	exit(1);
	    }
        printf("\ninside child\n");
        sleep(1);
        kill(pid,SIGUSR1);
        pause();
    }
    return 0;
}
