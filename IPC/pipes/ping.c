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
    char*buf[] = {"MSG0","MSG1","MSG2","MSG3","MSG4","MSG5","MSG6","MSG7","MSG8","MSG9","MSG10","MSG11"};

    FILE* temp = NULL;
    char fileN[MAX];
    int i,delete = 0,numOfMSG = 0,create = 0,op,vFlag = 0,sWorkSim,fd;
    extern char *optarg;
	extern int optind;
    
    while ((op = getopt(argc, argv, "dn:cvf:s:")) != -1)
    {
		switch (op) 
        {
		case 'd':
            delete = 1;
			break;
		case 'n':
            numOfMSG = atoi(optarg);
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
        if((temp = fopen(PATH,"w")) != NULL)
        {
            fclose(temp);
            perror("already exist");
        }
        if(mkfifo(PATH,0666))
        {
            perror("make fifo");
        }
    }

    fd = open(PATH, O_WRONLY); 
    

    for(i = 0;i < numOfMSG;++i)
    {
        printf("\nsleep write\n");
        usleep(sWorkSim*ET);
        write(fd,buf[i],strlen(buf[i]));
        printf("\nTo-Write %ld\n",strlen(buf[i]));
        printf("\nTo-Write %s\n",buf[i]);
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

  
   