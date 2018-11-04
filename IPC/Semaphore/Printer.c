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

#define IN_FLAGS "n:s:v"
#define FLAG_ERR_STR "SYNOPSIS -n (# of prints) -s (work simulation) -v"


union semun {
    int val;               
    struct semid_ds *buf;   
    unsigned short *array;         
};


int main(int argc, char *argv[])
{
    int op = -1,numOfPrints = 0,sleep = 0,verb,semId,i;
    key_t key;
    struct sembuf semUP = {0,1,0},semDown = {0,-1,0};
    union semun semInitVal ;
    extern char *optarg;
	extern int optind;

    while ((op = getopt(argc,argv, IN_FLAGS)) != -1)
    {
		switch (op) 
        {
        case 'n':
            numOfPrints = atoi(optarg);
			break;
        case 's':
            sleep = 1000*atoi(optarg);
			break;
        case 'v':
            verb = 1;
			break;
        case '?':
            fprintf(stderr,FLAG_ERR_STR);
			return 1;
		}
    }

    PRINT_V(verb,"\nftok\n");
    if((key = ftok(KEY_PATE, KEY_ID)) == -1)
    {
        fprintf(stderr,"ftok");
        return 1;
    }
    PRINT_V(verb,"\nsemget\n");
    if((semId = semget(key,1,MODE)) == -1)
    {
        perror("semget");
        return 1;
    }
    semInitVal.val = 1;
    if(semctl(semId,0,SETVAL,semInitVal) == -1)
    {
        perror("semSetVAl");
        return 1;
    }

    for (i = 0;i < numOfPrints;++i)
    {
        if (semop(semId, &semDown, 1) == -1)
        {
            semctl(semId, 0, IPC_RMID);
        }
        printf("\nMessage num %d\n",i+1);
        if (semop(semId, &semUP, 1) == -1)
        {
            semctl(semId, 0, IPC_RMID);
            return 1;
        }
        usleep(sleep);
    }

    return 0;
}