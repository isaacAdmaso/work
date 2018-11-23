/**
 * @file Insight.c
 * @brief 
 * @version 0.1
 * @date 2018-11-22
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include "Trigger.h"
#include "Dispatcher.h"


#define EXECUTABLE              "./Reader.out"
#define INFILE                  "./file.txt"
#define OUTPUT                  "./log.txt"
#define MSGQUE_NAME_DEFAULT     "../../../"




int main()
{
    Trigger_t     *trigger      = NULL;
    Dispatcher_t  *dispatch     = NULL;
    char    executable[]        = EXECUTABLE;
    char    inFile[]            = INFILE;
    char    outFile[]           = OUTPUT;
    char    msqName[]           = MSGQUE_NAME_DEFAULT;

    trigger     = Trigger_Create(executable,inFile,outFile,msqName,NULL);
    dispatch    = Dispatcher_Create(msqName);


    Triger_Run(trigger);
    Dispatcher_Run(dispatch);



    return 0;
}



