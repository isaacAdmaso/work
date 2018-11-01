#include "PrintCtl.h"
#include <unistd.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


#define IN_FLAGS "pdvr"
#define FLAG_ERR_STR "no good try -p or -r or -d"



int main(int argc, char *argv[])
{
    int op = -1,delete = 0,pause = 0,verb = 0,resume = 0,semId;
    key_t key;
    struct sembuf semUP = {0,1,IPC_NOWAIT},semDown = {0,-1,IPC_NOWAIT};
    extern char *optarg;
	extern int optind;


    while ((op = getopt(argc,argv, IN_FLAGS)) != -1)
    {
		switch (op) 
        {
        case 'p':
            pause = 1;
			break;
        case 'd':
            delete = 1;
			break;
        case 'v':
            verb = 1;
			break;
        case 'r':
            resume = 1;
            break;
        case '?':
            fprintf(stderr,FLAG_ERR_STR);
			return 1;
		}
    }
    if((key = ftok(KEY_PATE, KEY_ID)) == -1)
    {
        PRINT_V(verb,"\nftok\n");
        perror("\nftok\n");
        return 1;
    }
    if ((semId = semget(key, 1, 0)) == -1)
    {
        PRINT_V(verb,"\nsemget\n");
        perror("semget");
        return 1;
    }
    if(pause)
    {
        PRINT_V(verb,"\npause\n");
        if (semop(semId, &semDown, 1) == -1)
        {
            semctl(semId, 0, IPC_RMID);
            return 1;
        }
    }
    if(resume)
    {
        PRINT_V(verb,"\nresume\n");
        if (semop(semId, &semUP, 1) == -1)
        {
            semctl(semId, 0, IPC_RMID);
            return 1;
        }
    }
    if (delete)
    {
        PRINT_V(verb,"\ndeleted\n");
        if (semctl(semId, 0, IPC_RMID, NULL) == -1) 
        {
            perror("semctl");
            return 1;
        }

    }

    return 0;
}
