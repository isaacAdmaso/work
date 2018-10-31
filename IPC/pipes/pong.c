#include "pipo.h" 
#define STRPARM "dr:cvf:s:"

/*
*/
int main(int argc, char *argv[])
{
    char readBuf[MAX] = "\0";
    FILE* temp = NULL;
    int fd,n;   
    Input_Op inputOp;
    
    
    Init(&inputOp,argc,argv);
    Get_Op_Prm(&inputOp,STRPARM);
    
    if (inputOp.m_create)
    {
        if (inputOp.m_vFlag)
        {
           printf("\ncreate Named Pipe \n");
        }
        if((temp = fopen(inputOp.m_fileN,"r")) != NULL)
        {
            fclose(temp);
            perror("already exist\n");
            exit(1);
        }
        if(mkfifo(inputOp.m_fileN,MODE))
        {
            perror("make fifo");
        }
    }
    fd = open(inputOp.m_fileN,  O_RDONLY); 
    while ((n = read(fd, readBuf, inputOp.m_numToRead)) > 0)
    {
        readBuf[n] = '\0';
        printf("\nsleep Read\n");
        usleep(inputOp.m_sWorkSim*ET);
        printf("\nReceived string: %ld \n", strlen(readBuf));
        PrintPid();
        printf("\nReceived string: %s\n", readBuf);

    }
    close(fd);
    
    if(inputOp.m_delete)
    {
        if (inputOp.m_vFlag)
        {
           printf("\nNamed Pipe %s deleted\n",inputOp.m_fileN);
        }
        remove(inputOp.m_fileN);
    }
    return 0;
}

