#include "pingpong.h"
#define STRPARM "vf:s:"


int main(int argc, char *argv[])
{
    key_t key;
    int msqid,numOfBytes;
    MymsgBuf msgBuf;
    Input_Op inputOp = {0};


    Init(&inputOp,argc,argv);
    Get_Op_Prm(&inputOp,STRPARM);

    PRINT_V((inputOp.m_vFlag),("ftok"));
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

    PRINT_V(inputOp.m_vFlag,"msgget");
    if ((msqid = msgget(key,MODE| IPC_CREAT)) == -1)
    {
        perror("msgget");
        exit(1);
    }

    PRINT_V((inputOp.m_vFlag),"start to rec");
    while(1)
    {
        if(msgrcv(msqid, &msgBuf, sizeof msgBuf.m_mBufId, 0, 0) == -1)
        {
            perror("msgrcv");
            exit(1);
        }
        PrintPid();
        printf("\nRec srt: %s form PID: %d\n",msgBuf.m_mBufId.m_msg,msgBuf.m_mBufId.m_pid);
        fflush(0);

        PRINT_V((inputOp.m_vFlag),"\nEnter lines of text, ^D to quit:\n");
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

    }

    
    return 0;
}
