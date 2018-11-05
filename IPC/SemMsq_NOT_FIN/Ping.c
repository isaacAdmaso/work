#include "PingPong.h"
#include <unistd.h>
#include <fcntl.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <time.h>


#include "PingPong.h"
#define TYPE 3
#define STRPARM "vcdf:n:s:"


typedef struct regbuf
{
	long	m_type;
	int 	m_procID;
} regbuf;

int main(int argc, char *argv[])
{
    key_t key;
    int msgQ;
    regbuf reg;
    pid_t pid = getpid();


    if((key = ftok(".", 1)) == -1)
    {
        perror("\nftok\n");
        return 1;
    }
    if((msgQ = msgget(key, 0666)) == -1)
    {
        perror("\nmsgget\n");
        return 1;
    }
    reg.m_type = 7;
    reg.m_procID = pid;
    return 0;

    
