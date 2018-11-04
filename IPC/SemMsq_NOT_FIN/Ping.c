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


int main(int argc, char *argv[])
{
    key_t key = {0};
    MSQID msqid = 0;
    MymsgBuf msgBuf;
    Input_Op inputOp = {0};
    int semaId;


    Init(&inputOp,argc,argv);
    Get_Op_Prm(&inputOp,STRPARM);
    msgBuf.m_type = TYPE;
    msgBuf.m_mBufId.m_pid = getpid();
    PRINT_V((inputOp.m_vFlag),("ftok"));
    Key_Init(&inputOp,&key);

    PRINT_V(inputOp.m_vFlag,"msgget");
    Msq_Init(&msqid,key);
    semaId = InitSem(key,2);

    return 0;

    
