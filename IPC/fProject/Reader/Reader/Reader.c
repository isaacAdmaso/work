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
#include "Reader.h"
#include "Parser.h"




/**
 * argv[0]  executable 
 * argv[1] = INFILE is input file path,
 * argv[2] = OUTPUT output path Dir,
 * argv[3]  message queue id
 * 
 */
int main(int argc, char *argv[])
{
    FILE *inFp,*outFp;
    char lineCDR[MAX_LINE];
    char placeSave[MAX_FNAME];
    void *handle;
    size_t sendSize;
    msq_t msq;

    inFp  = fopen(argv[1],"r");
    outFp = fopen(argv[2],"w");
    
    if(-1 == (msq = Msq_CrInit(argv[3],0)))
    {
        perror("\nfailed to conect MSQ\n");
        exit(-1);
    }


    if(!inFp || !outFp)
    {
        perror("\nfailed to open File\n");
        exit(-1);
    }
    
    sendSize = Cdr_Size();

    while(!feof(inFp))
	{
        
        fgets(lineCDR,MAX_LINE,inFp);
		if(feof(inFp))
		{
			break;
		}
        handle = Parser1(lineCDR);
        Print_Cdr(handle);
        Msq_Send(msq,MSG_TYPE_READ,handle,sendSize);
        sprintf(placeSave,"%s|%ld\n",argv[1],(unsigned long)ftell(inFp));
        fputs(placeSave,outFp);
        
    }
    
    fclose(inFp);
    fclose(outFp);
    exit(EXIT_SUCCESS);
}

/*
#define MODULE "MODULE"
#define INPUTFNAME "./file.txt"
int Reader(char *_inFp ,msq_t _msq)
*/
/*
    ,*parsRt;
    PtrFunc Parser_Func;
 */
/*
    Msq_Register(msq,MSG_TYPE_REGISTRAR);
    Zlog_Init("Confile.txt");
    char outputPath[MAX];
    snprintf(outputPath,MAX,"%s",OUTPUT);
    ZLOG("last",LOG_TRACE,"hope will work");
*/

/*
        ZLOG("last",LOG_TRACE,"hope will work");
    */
   /**TODO check open 
     *
        handle = dlopen(argv[3], RTLD_LAZY);
        Parser_Func = (PtrFunc) dlsym(handle, PFUNC);
    sendSize = (size_t)atoi(SIZE_ST);
    */
   /*
    ZLOG("last",LOG_TRACE,"hope will work");
  */
 /*
    Zlog_Destroy();
    dlclose(handle);
    */