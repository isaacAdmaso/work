#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif

#include "MyMsq.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 1024 





int main()
{
    msq_t mq;
    char rcv[MAX];


    mq = Msq_CrInit(".",0);
    Msq_Receive(mq,1,(void*)rcv,MAX);
    printf("\n%s\n",rcv);
    strcpy(rcv,"yeh great success! mf burt");
    Msq_Send(mq,1,(void*)rcv,strlen(rcv));

    
        
    return 0;
}
