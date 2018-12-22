#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define MAX 32


void sigint_handler(int sig)
{
	/*printf("\nAhhh! SIGINT!\n") - printf is not async safe*/
    write(0,"\nAhhh! SIGINT!\n",MAX);
}

int main(void)
{
	char s[200];
    int i;
	struct sigaction sa;

	sa.sa_handler = sigint_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);

/*  before definations dont work yet */
    for(i = 0;i < 5;++i)
    {
        printf(", %d ",i);
        fflush(stdout);
        sleep(1);
    }
    /**all errors ==  -1  */
	if (sigaction(SIGINT, &sa, NULL) == -1) 
    {
		perror("sigaction");
		exit(1);
	}
    /** ^c work */
   /* raise(9);- send kill signal from within*/
    for(i = 0;i < 5;++i)
        {
            printf(", %d ",i);
            fflush(stdout);
            sleep(1);
        }
	printf("Enter a string:\n");

	if (fgets(s, sizeof s, stdin) == NULL)
		perror("fgets");
	else 
		printf("You entered: %s\n", s);

	return 0;
}
