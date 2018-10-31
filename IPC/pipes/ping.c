
#include "pipo.h" 
#define STRPARM "dn:cvf:s:"


int main(int argc, char *argv[])
{
    char*buf[] = {"MSG0","MSG1","MSG2","MSG3","MSG4","MSG5","MSG6","MSG7","MSG8","MSG9","MSG10","MSG11"};
    FILE* temp = NULL;
    int fd,i;   
    Input_Op inputOp = {0};
    
    
    Init(&inputOp,argc,argv);
    Get_Op_Prm(&inputOp,STRPARM);
    if (inputOp.m_create)
    {
        if (inputOp.m_vFlag)
        {
           printf("\ncreate Named Pipe \n");
        }
        if((temp = fopen(inputOp.m_fileN,"w")) != NULL)
        {
            fclose(temp);
            perror("already exist");
            return 1;
        }
        if(mkfifo(inputOp.m_fileN,MODE))
        {
            perror("make fifo");
            return 1;
        }
    }

    if (inputOp.m_vFlag)
    {
        printf("open fifo");
    }
    fd = open(inputOp.m_fileN, O_WRONLY); 
    if(fd == -1)
    {
        if (inputOp.m_vFlag)
        {
           perror("open fifo");
        }
        return 1;
    }
    

    for(i = 0;i < inputOp.m_numToRead;++i)
    {
        printf("\nsleep write\n");
        usleep(inputOp.m_sWorkSim*ET);
        write(fd,buf[i],strlen(buf[i]));
        printf("\nTo-Write %ld\n",strlen(buf[i]));
        PrintPid();
        printf("\nTo-Write %s\n",buf[i]);
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

  
   