#ifndef _XOPEN_SOURCE 
#define _XOPEN_SOURCE  500
#endif
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <sys/stat.h> 
#include <sys/types.h>
#include <fcntl.h> 
#define ET 1000
#define MAX 128
#define PATH "./MyFifo"

int main(int argc, char *argv[])
{
    char readBuf[MAX] = "\0";
    FILE* temp = NULL;
    char fileN[MAX];
    int n,delete = 0,numToRead = 0,create = 0,op,vFlag = 0,sWorkSim,fd;
    extern char *optarg;
	extern int optind;
    
    while ((op = getopt(argc, argv, "dr:cvf:s:")) != -1)
    {
		switch (op) 
        {
		case 'd':
            delete = 1;
			break;
		case 'r':
            numToRead = atoi(optarg);
			break;
        case 'c':
            create = 1;
			break;
        case 'v':
            vFlag = 1;
			break;
        case 'f':
            strcpy(fileN,optarg);
			break;
        case 's':
            sWorkSim = atoi(optarg);
			break;
        case '?':
			break;
		}
    }

    if (create)
    {
        if (vFlag)
        {
           printf("\ncreate Named Pipe \n");
        }
        if((temp = fopen(PATH,"r")) != NULL)
        {
            fclose(temp);
            perror("already exist");
            exit(1);
        }
        if(mkfifo(PATH,0666))
        {
            perror("make fifo");
        }
    }
    fd = open(PATH,  O_RDONLY); 
    while ((n = read(fd, readBuf, numToRead)) > 0)
    {
        readBuf[n] = '\0';
        printf("\nsleep Read\n");
        usleep(sWorkSim*ET);
        printf("\nReceived string: %ld\n", strlen(readBuf));
        printf("\nReceived string: %s\n", readBuf);

    }
    close(fd);
    
    if(delete)
    {
        if (vFlag)
        {
           printf("\nNamed Pipe %s deleted\n",fileN);
        }
        remove(PATH);
    }
    return 0;
}

    