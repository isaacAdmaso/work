/**
 * @file Reader.c
 * @brief   process image ,manage input
 * @version 0.1
 * @date 2018-11-19
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dlfcn.h>
#include "logger.h"
#define MODULE "MODULE"

#include "MyMsq"

#define MAX 1024
#define TYPE 1


typedef void* (*PtrFunc)(char* _lineCDR);


/**argv[0] is input file path,
 * argv[1] output path Dir,
 * argv[2] parser dynemic lib,
 * argv[3] parser function name
 * argv[4] is message queue id
 * argv[5] is size of struct after parse
 * 
 */
int main(int argc, char const *argv[])
{
    FILE *inFp,*outFp;
    char outputPath[MAX];
    char lineCDR[MAX];
    char placeSave[MAX];
    void *handle,*parsRt;
    size_t sendSize;
    PtrFunc Parser_Func;
    msq_t msg;

    Zlog_Init("Confile.txt");
    ZLOG("last",LOG_TRACE,"hope will work");

    inFp  = fopen(argv[0],"r");
    snprintf(outputPath,MAX,"%s/%d",argv[1],getpid());
    outFp = fopen(outputPath,"w");

    if(!inFp || !outFp)
    {
        ZLOG("last",LOG_TRACE,"hope will work");
        perror("\nfailed to open File\n");
        exit(-1);
    }
    /**TODO check open */
    handle = dlopen(argv[2], RTLD_LAZY);
    Parser_Func = (PtrFunc) dlsym(handle, argv[3]);

    msg = atoi(argv[4]);
    sendSize = (size_t)atoi(argv[5]);
    /*
    ZLOG("last",LOG_TRACE,"hope will work");
    */
    while(!feof(inFp))
	{
        
        if(!(read(inFp,lineCDR,MAX))) 
        { 
            break ;
        }
        parsRt = Parser_Func(lineCDR);
        Msq_Send(msg,TYPE,parsRt,sendSize);
        snprintf(placeSave,MAX,"%d|%d",(int)inFp,(int)ftell(inFp));
        write(outFp, placeSave,strlen(placeSave));

    }
    Zlog_Destroy();
    dlclose(handle);
    fclose(inFp);
    fclose(outFp);
    return 0;
}