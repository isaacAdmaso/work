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
    char msg[MAX] = "great success!!!";

    mq = Msq_CrInit(".",1);
    Msq_Send(mq,1,(void*)msg,strlen(msg));
    sleep(10);
    Msq_Receive(mq,1,(void*)msg,MAX);
    printf("\n%s\n",msg);
    sleep(1);
    Msq_Destroy(mq);



        
    return 0;
}
