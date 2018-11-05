#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <errno.h>
#include <time.h>
#include "PingPong.h"
#define STRPARM "vcdf:n:s:"


int main(int argc, char *argv[])
{
    key_t key;
    Input_Op inputOp;
    int semaId,shmId;
    union semun semInitVal;
    struct sembuf semUP = {0,1,0},semDown = {0,-1,0};
    char* str;


    Get_Op_Prm(&inputOp,STRPARM,argc,argv);
    PRINT_V((inputOp.m_vFlag),("ftok"));
    Key_Init(&inputOp,&key);
    
    PRINT_V(inputOp.m_vFlag,"msgget");
    semaId = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666);

    semInitVal.val = 1;
    if(semctl(semaId,0,SETVAL,semInitVal) == -1)
    {
        perror("semSetVAl");
        return 1;
    }

    PRINT_V(inputOp.m_vFlag,"semId");
    shmId = shmget(key,MAX,MODE);
    PRINT_V(inputOp.m_vFlag,"semId");
    str = (char*)shmat(shmId,NULL,0);
    if (semop(semaId, &semDown, 1) == -1)
    {
        semctl(semaId, 0, IPC_RMID);
        perror("\nsemOP down\n");
        return 1;
    }
    printf("\nEnter string\n");
    fgets(str,MAX,stdin);
    printf("\nwritten str is %s\n",str);

    if (semop(semaId, &semUP, 1) == -1)
    {
        semctl(semaId, 0, IPC_RMID);
        perror("\nsemOP up\n");
        return 1;
    }
    shmdt(str);
    return 0;
}


