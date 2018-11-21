/**
 * @file Reader.c ping
 * @brief   process image ,manage input
 * @version 0.1
 * @date 2018-11-19
 * 
 * @copyright Copyright (c) 2018
 * 
    #include "logger.h"
    #include <dlfcn.h>
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "MyMsq.h"
#include "test.h"
#include "Reader.h"
#include "Parser.h"

#define OUTPUT "./log.txt"
#define INFILE "./file.txt"
#define MAX 1024



/**
#define MODULE "MODULE"
#define INPUTFNAME "./file.txt"
 * argv[0] is input file path,
 * argv[1] output path Dir,
 * argv[2] parser dynemic lib,
 * argv[3] parser function name
 * argv[4]  message queue id
 * argv[5]  size of struct after parse
 * 
 */

/*
int Reader(char *_inFp ,msq_t _msq)
*/
int main()
{
    FILE *inFp,*outFp;
    char lineCDR[MAX];
    char placeSave[MAX];
    void *handle;
/*
    ,*parsRt;
    PtrFunc Parser_Func;
 */
    size_t sendSize;
    msq_t msq;




    msq = Msq_CrInit(MSGQUE_NAME_DEFAULT,1);
/*
    Msq_Register(msq,MSG_TYPE_REGISTRAR);
    Zlog_Init("Confile.txt");
    char outputPath[MAX];
    snprintf(outputPath,MAX,"%s",OUTPUT);
    ZLOG("last",LOG_TRACE,"hope will work");
*/
    inFp  = fopen(INFILE,"r");
    outFp = fopen(OUTPUT,"w");

    if(!inFp || !outFp)
    {
  /*
        ZLOG("last",LOG_TRACE,"hope will work");
    */
        perror("\nfailed to open File\n");
        exit(-1);
    }
    /**TODO check open 
     *
        handle = dlopen(argv[3], RTLD_LAZY);
        Parser_Func = (PtrFunc) dlsym(handle, PFUNC);
    sendSize = (size_t)atoi(SIZE_ST);
    */
    sendSize = Cdr_Size();
/*
    ZLOG("last",LOG_TRACE,"hope will work");
  */
    while(!feof(inFp))
	{
        
        fgets(lineCDR,MAX,inFp);
		if(feof(inFp))
		{
			break;
		}
        handle = Parser1(lineCDR);
        Print_Cdr(handle);
        Msq_Send(msq,MSG_TYPE_READ,handle,sendSize);
        sprintf(placeSave,"%p |%d\n",(void*)inFp,(int)ftell(inFp));
        fputs(placeSave,outFp);
        lineCDR[0] = '\0';
        
    }
    /*
    Zlog_Destroy();
    dlclose(handle);
    */
    printf("\n%ld,%d\n",Msq_Nmsgs(msq),msq);

    fclose(inFp);
    fclose(outFp);
    return 0;
}