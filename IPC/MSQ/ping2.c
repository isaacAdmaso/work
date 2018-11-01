#include "pingpong.h"
#define TYPE 3
#define STRPARM "vcdf:n:es:"


int main(int argc, char *argv[])
{
    key_t key = {0};
    MSQID msqid = 0;
    MymsgBuf msgBuf;
    Input_Op inputOp = {0};


    Init(&inputOp,argc,argv);
    Get_Op_Prm(&inputOp,STRPARM);
    msgBuf.m_type = TYPE;
    msgBuf.m_mBufId.m_pid = getpid();

    PRINT_V((inputOp.m_vFlag),("ftok"));
    Key_Init(&inputOp,&key);
/*
    if(strcmp(inputOp.m_fileN,DEF))
    {
        if((key = ftok(inputOp.m_fileN, KEY_ID)) == -1)
        {
            perror("ftok");
            exit(1);
        }

    }
    else
    {
        if((key = ftok(KEY_PATE, KEY_ID)) == -1)
        {
            perror("ftok");
            exit(1);
        }
    }
*/
    PRINT_V(inputOp.m_vFlag,"msgget");
    Msq_Init(&msqid,key);
/**struct chanel key 
     * 
    if ((msqid = msgget(key,MODE | IPC_CREAT)) == -1)
    {
        perror("msgget");
        exit(1);
    }
*/

    while(1)
    {   
        PRINT_V((inputOp.m_vFlag),"\nEnter lines of text, ^D to quit:\n");
    /*
        if(fgets(msgBuf.m_mBufId.m_msg, MAX, stdin) == NULL)
        {
            break;
        }

        numOfBytes = strlen(msgBuf.m_mBufId.m_msg);
        if(msgBuf.m_mBufId.m_msg[numOfBytes - 1] == '\n')
        {
            msgBuf.m_mBufId.m_msg[numOfBytes - 1] = '\0';
        }
        PRINT_V((inputOp.m_vFlag),"msgsnd");
        if(msgsnd(msqid, &msgBuf, numOfBytes + 1, IPC_NOWAIT) == -1)
        {
            perror("msgsnd");
        }
    */
        if(!Str_Msg_Send(&msgBuf,msqid,inputOp.m_vFlag))
        {
            return 1;
        }
        if(msgrcv(msqid, &msgBuf, sizeof msgBuf.m_mBufId, 0, 0) == -1)
        {
            perror("msgrcv");
            exit(1);
        }
        PrintPid();
        printf("\nRec srt: %s from PID: %d\n",msgBuf.m_mBufId.m_msg,msgBuf.m_mBufId.m_pid);
        fflush(0);
    }
    if(msgctl(msqid, IPC_RMID, NULL) == -1)
    {
        PRINT_V((inputOp.m_vFlag),"msgctl");
        perror("msgctl");
        exit(1);
    }
    return 0;
}
