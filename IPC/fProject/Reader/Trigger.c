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



#define OUTPUT      "/./log.txt"
#define INFILE      "/./file.txt"
#define DIRPATH     "/./"
#define EXECUTABLE  "/./Reader.out"
#define BUFF        16
#define SIZE        4




/**
static void TriggerRun(char readerInput[SIZE][MAX],char *executable, char newenviron[][1]);
 * argv[0]  message queue id
 * argv[1]  input file path,
 * argv[2]  output path Dir,
 * argv[3]  size of struct after parse
 * argv[4]  parser dynemic lib,
 * argv[5]  parser function name
 * symbol-file file
 * 
 */

int main()
{
    char *newargv[] = { MSGQUE_NAME_DEFAULT, INFILE, DIRPATH, NULL };
    char *newenviron[] = { NULL };
    msq_t msq;

    msq = Msq_CrInit(MSGQUE_NAME_DEFAULT,1);
    if(msq == -1)
    {
        perror("\nMSQ INIT\n");
        return -1;
    }
    printf("\nin trigget\n");
    fflush(stdout);

    execve(EXECUTABLE, newargv, newenviron);
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