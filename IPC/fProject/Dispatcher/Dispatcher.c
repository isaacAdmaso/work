/**
 * @file Dispatcher.c pong
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-11-20
 * 
 * @copyright Copyright (c) 2018
#include "Parser.h"
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "MyMsq.h"
#include "CDR.h"
#include "test.h"

#define MAXTST 64





/*
int Reader(char *_inFp ,msq_t _msq)
*/
int main()
{
    void *handle;
    char *strField;
    size_t szField;
    size_t sendSize;
    msq_t msq;


    msq = Msq_CrInit(MSGQUE_NAME_DEFAULT,0);
    sendSize = Cdr_Size();
    handle = malloc(sendSize);

    Msq_Receive(msq,MSG_TYPE_READ,handle,sendSize);
    Print_Cdr(handle);
    Cdr_Get(handle,'I',(void**)&strField);
    Cdr_Get(handle,'d',(void**)&szField);
    printf("\n%s | %ld\n",strField,szField);
    printf("\n%ld,%d\n",Msq_Nmsgs(msq),msq);

    return 0;
}
