#ifndef _XOPEN_SOURCE 
#define _XOPEN_SOURCE  500
#endif
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>/**for pipe */
#include <wait.h>
#include <stdio.h>
#define ET 1000
#define MAX 128

int main(int argc, char *argv[])
{
    /*
    char readBuf[MAX],buf[] = "Balance factors can be kept up-to-date by knowing the previous balance factors and the change in height\
     it is not necessary to know the absolute height. For holding the AVL balance information in the traditional way\
    two bits per node are sufficient. However, later research showed if the AVL tree is implemented as a rank balanced tree with delta ranks ";
*/
    char readBuf[MAX]= "\0",*buf[] = {"Balance factors can be kept up-to-date", "by knowing the previous balance",\
     "factors and the change in height","it is not necessary to", "know the absolute height",\
      "For holding the AVL balance", "information in the traditional", "way two bits per node are sufficient"\
      , "However, later research showed if the AVL tree is", "implemented as a rank balanced tree with delta ranks"};
/*
    char readBuf[MAX] = "\0",*buf[] = {"MSG0","MSG1","MSG2","MSG3","MSG4","MSG5","MSG6","MSG7","MSG8","MSG9","MSG10","MSG11"};
  */
    int i,vFlag = 0,numOfMSG = 0,cid,n,pWorkSim = 0,cWorkSim = 0,sizeToRead = 0,fd[2];
    extern char *optarg;
	extern int optind;
    
    while ((n = getopt(argc, argv, "vn:p:c:s:")) != -1)
    {
		switch (n) 
        {
		case 'v':
            vFlag = 1;
			break;
		case 'n':
            numOfMSG = atoi(optarg);
			break;
        case 'p':
            pWorkSim = atoi(optarg);
			break;
        case 'c':
            cWorkSim = atoi(optarg);
			break;
        case 's':
            sizeToRead = atoi(optarg);
			break;
        case '?':
            
			break;
		}

    }
    if (vFlag)
    {
        printf("\npipe creat\n");
    }
    if (pipe(fd) == -1)
    { 
        perror("pipe");
    } 
    if (vFlag)
    {
        printf("\nfork\n");
    }
    cid = fork();
    if (cid < 0)
    {
        perror("fork");
    } 


    if (cid == 0)
    { 
        if (vFlag)
        {
        printf("\nChild reads from pipe\n");
        }
        close(fd[1]);        
        if (vFlag)
        {
        printf("\nClose unused write end\n");
        }


        while ((n = read(fd[0], readBuf, sizeToRead)) > 0)
        {
            readBuf[n] = '\0';
            printf("\nsleep Read\n");
            usleep(cWorkSim*ET);
            printf("\nReceived string: %ld\n", strlen(readBuf));
            printf("\nReceived string: %s\n", readBuf);

        }
        close(fd[0]);

    }
    else
    {
        if (vFlag)
        {
        printf("\nParent writes\n");
        }
        close(fd[0]);
        if (vFlag)
        {
        printf("\nClose unused read end\n");
        }
        for(i = 0;i < numOfMSG;++i)
        {
            printf("\nsleep write\n");
            usleep(pWorkSim*ET);
            write(fd[1],buf[i],strlen(buf[i]));
            printf("\nTo-Write %ld\n",strlen(buf[i]));
            printf("\nTo-Write %s\n",buf[i]);
        }
        close(fd[1]);
        waitpid(cid,NULL,0);       
    }

    return 0;
}
