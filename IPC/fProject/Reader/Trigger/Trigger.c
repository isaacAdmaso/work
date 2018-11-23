/**
 * @file Trigger.c
 * @brief 
 * @version 0.1
 * @date 2018-11-22
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include "MyMsq.h"
#include "Trigger.h"


#define MAGIC           80746224908
#define IS_INVALID(T)   ((NULL == (T)) || (T)->m_magic != MAGIC)



struct Trigger_t
{
    char    m_Executabe[MFNSIZE];
    char    m_InFile[MFNSIZE];
    char    m_OutFile[MFNSIZE];
    char    m_MsqName[MFNSIZE];
    char    m_Nenviron[MFNSIZE]; 
    size_t  m_magic;  
};


/**
 * @brief create Trigger
 * 
 */
Trigger_t* Trigger_Create(char* _executabe, char* _inFile, char* _outFile, char* _msqName, char* _nEnviron)
{
    Trigger_t* trigger = NULL;
    msq_t msq;

    msq = Msq_CrInit(_msqName,0);
    if(msq == -1)
    {
        perror("\nMSQ INIT\n");
        return NULL;
    }
    if(!(trigger = calloc(1,sizeof(Trigger_t))))
    {
        return NULL;
    }
    
    strcpy(trigger->m_Executabe,_executabe);
    strcpy(trigger->m_InFile,   _inFile);
    strcpy(trigger->m_OutFile,  _outFile);
    strcpy(trigger->m_MsqName,  _msqName);
    strcpy(trigger->m_Nenviron, _nEnviron);
    
    trigger->m_magic = MAGIC;
    return trigger;
}

/**
 * @brief free _trigger  
 * 
 */
void  Trigger_Destory(Trigger_t* _trigger)
{
    if(IS_INVALID(_trigger))
    {
        return;
    }
    _trigger->m_magic = 0;
    free(_trigger);
}

/**set process's arguments */
static int TriggerToExSTR(Trigger_t* _trigger, char** newargv, char** newenviron)
{

    if(IS_INVALID(_trigger))
    {
        return 0;
    }
    
    newenviron[0] = _trigger->m_Nenviron;
    newargv[0]    = _trigger->m_Executabe;
    newargv[1]    = _trigger->m_InFile;
    newargv[2]    = _trigger->m_OutFile;
    newargv[3]    = _trigger->m_MsqName;
    return 1;
}
/**
 * argv[0]  executabe
 * argv[1]  message queue id
 * argv[1]  input file path,
 * argv[2]  output path Dir,
 * argv[3]  size of struct after parse
 * argv[4]  parser dynemic lib,
 * argv[5]  parser function name
 * symbol-file file
 * 
 */

void* Trigger_Run(void* _trigger)
{
    char *newargv[] = { NULL, NULL, NULL, NULL, NULL };
    char *newenviron[] = { NULL };
    int n;
    Trigger_t* trigger = (Trigger_t*)_trigger;

    if(IS_INVALID(trigger))
    {
        return NULL;
    }
    TriggerToExSTR(trigger,newargv,newenviron);
    printf("\nin trigget\n");
    fflush(stdout);

    n = fork();
    if(n < 0)
    {
        perror("\nERROR fork()\n");
    }
    if (n == 0)
    {
        execve(newargv[0], newargv, newenviron);
        perror("execve"); /* execve() only returns on error */
        exit(EXIT_FAILURE);
    }
    return 0;

}
/*
    DIR* dirPtr*;
    struct dirent* in_file;
    FILE    *common_file;
    FILE    *entry_file;
    char    buffer[BUFSIZ];

    
    // Openiing common file for writing 
    common_file = fopen(INFILE, "w");
    if (common_file == NULL)
    {
        fprintf(stderr, "Error : Failed to open common_file - %s\n", strerror(errno));

        return 1;
    }

    // Scanning the in directory 
    if (NULL == (FD = opendir (DITPATH))) 
    {
        fprintf(stderr, "Error : Failed to open input directory - %s\n", strerror(errno));
        fclose(common_file);

        return 1;
    }
    while ((in_file = readdir(FD))) 
    {
        // On linux/Unix we don't want current and parent directories
         / On windows machine too, thanks Greg Hewgill
         //
        if (!strcmp (in_file->d_name, "."))
            continue;
        if (!strcmp (in_file->d_name, ".."))    
            continue;
         Open directory entry file for common operation 
         TODO : change permissions to meet your need! 
        entry_file = fopen(in_file->d_name, "rw");
        if (entry_file == NULL)
        {
            fprintf(stderr, "Error : Failed to open entry file - %s\n", strerror(errno));
            fclose(common_file);

            return 1;
        }

         Doing some struf with entry_file : 
         For example use fgets 
        while (fgets(buffer, BUFSIZ, entry_file) != NULL)
        {
             Use fprintf or fwrite to write some stuff into common_file
        }

        // When you finish with the file, close it 
        fclose(entry_file);
static void TriggerRun(char readerInput[SIZE][MAX],char *executable, char newenviron[][1])  
    }

     Don't forget to close common file before leaving 
    fclose(common_file);
    return 0;
}
static void TriggerRun(char readerInput[SIZE][MAX],char *executable, char newenviron[][1])  
}
*/