#ifndef _XOPEN_SOURCE 
#define _XOPEN_SOURCE  500
#endif
#include <assert.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <sys/stat.h> 
#include <sys/types.h>
#include <fcntl.h>
#define ET 1000
#define MAX 128
#define MODE 0666

typedef struct Input_Op
{
    char **m_argv;
    char* m_fileN;
    int m_argc;
    int m_delete;
    int m_numToRead;
    int m_create;
    int m_vFlag;
    int m_sWorkSim;
}Input_Op;

void Init(Input_Op* _inStc,int _argc, char *_argv[]);
void Get_Op_Prm(Input_Op* _input,char* _str);
void PrintPid();
