/**
 * @file Reader.c ping
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
#include "MyMsq"
#include "Reader.h"
#include "Parser.h"

#define OUTPUT "./"
#define MODULE "MODULE"
#define MAX 1024
#define TYPE 1
#define INPUTFNAME "./file.txt"
#define REG 



/**argv[0] is input file path,
 * argv[1] output path Dir,
 * argv[2] parser dynemic lib,
 * argv[3] parser function name
 * argv[4] is message queue id
 * argv[5] is size of struct after parse
 * 
 */

/*
int Reader(char *_inFp ,msq_t _msq)
*/
int main()
{
    FILE *inFp,*outFp;
    char outputPath[MAX];
    char lineCDR[MAX];
    char placeSave[MAX];
    void *handle;
/*
    ,*parsRt;
    PtrFunc Parser_Func;
 */
    size_t sendSize;
    msq_t msq;




    msq = Msq_CrInit("../",C_PERMIS);
    Msq_Register("start",REG);
/*
    Zlog_Init("Confile.txt");
    ZLOG("last",LOG_TRACE,"hope will work");
*/
    inFp  = fopen(_inFp,"r");
    snprintf(outputPath,MAX,"%s/%d",OUTPUT,getpid());
    outFp = fopen(outputPath,"w");

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
        
        if(!(read(inFp,lineCDR,MAX))) 
        { 
            break ;
        }
        handle = Parser1(lineCDR);
        Msq_Send(msg,TYPE,parsRt,sendSize*sizeof(char));
        snprintf(placeSave,MAX,"%d|%d",(int)inFp,(int)ftell(inFp));
        write(outFp, placeSave,strlen(placeSave));

    }
    /*
    Zlog_Destroy();
    dlclose(handle);
    */
    fclose(inFp);
    fclose(outFp);
    return 0;
}