#ifndef __PINGPONG_H__
#define __PINGPONG_H__
#include <unistd.h>
#include <fcntl.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define KEY_PATE "./ping2.c" 
#define DEF "MyFifo"
#define KEY_ID 'A'
#define MAX_RETRIES 10
#define MAX 1024
#define MODE 0644
#define PRINT_V(S,STR) do{ if((S)) printf("\n%s\n",(STR));}while(0)


typedef int MSQID; 
typedef struct MsG
{
    pid_t m_pid;
    char m_msg[MAX];
}Msg;
typedef struct MymsgBuf
{
    long m_type;
    Msg  m_mBufId;
}MymsgBuf;

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
    int m_eof;
}Input_Op;

void Get_Op_Prm(Input_Op* _input,int _argc, char *_argv[],char* _str);
void PrintPid();
void Key_Init(Input_Op* _op,key_t* key );
int Str_Msg_Send(MymsgBuf* _msgBuf,MSQID _msqid,int _vFlag);
int Str_Msg_Res(MSQID _msqid,MymsgBuf* _msgBuf);
int InitSem(key_t key, int nsems);
int Msq_Init(MSQID *_msqid ,key_t _key);




#endif/**__PINGPONG_H__ */