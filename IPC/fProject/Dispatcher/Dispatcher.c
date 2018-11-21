/**
 * @file Dispatcher.c pong
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-11-20
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "MyMsq.h"
#include "test.h"
#include "Manager.h"

#define MAXTST 64





int main()
{
    void *handle;
    size_t sendSize;
    msq_t msq;
    Manager_t* manager;

    
    msq = Msq_CrInit(MSGQUE_NAME_DEFAULT,0);
    sendSize = Cdr_Size();
    handle = malloc(sendSize);
    manager = Manager_Create();
    assert(manager);
    
    Msq_Receive(msq,MSG_TYPE_READ,handle,sendSize);
    Manager_Upsert(manager,handle);
    Manager_Print(manager);
    printf("\nend of line\n");


    return 0;
}
