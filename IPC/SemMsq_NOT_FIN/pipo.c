#include "PingPong.h"
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
#include <sys/sem.h>
#include <time.h>



static void Init(Input_Op* _inStc,int _argc, char *_argv[])
{
    _inStc->m_argv = _argv;
    _inStc->m_fileN = DEF;
    _inStc->m_argc = _argc;
    _inStc->m_delete = 0;
    _inStc->m_numToRead = 0;
    _inStc->m_create = 0;
    _inStc->m_vFlag = 0;
    _inStc->m_sWorkSim = 0;
    _inStc->m_eof = 0;
}
void Get_Op_Prm(Input_Op* _input,char* _str,int _argc, char *_argv[])
{
    int op = -1;
    extern char *optarg;
	extern int optind;

    Init(_input,_argc,_argv);

    while ((op = getopt(_input->m_argc, _input->m_argv, _str)) != -1)
    {
		switch (op) 
        {
		case 'd':
            _input->m_delete = 1;
			break;
		case 'r':
        case 'n':
            _input->m_numToRead = atoi(optarg);
			break;
        case 'c':
            _input->m_create = 1;
			break;
        case 'v':
            _input->m_vFlag = 1;
			break;
        case 'f':
            _input->m_fileN = optarg;
			break;
        case 's':
            _input->m_sWorkSim = atoi(optarg);
			break;
        case 'e':
            _input->m_eof = 1;
            break;
        case '?':
			break;
		}
    }
}

void PrintPid()
{
    pid_t pid = getpid();
    printf("\nfrom ps %d\n",pid);
}

void Key_Init(Input_Op* _op,key_t* _key )
{

    if(strcmp(_op->m_fileN,DEF))
    {
        if((*_key = ftok(_op->m_fileN, KEY_ID)) == -1)
        {
            perror("\nftok\n");
            exit(1);
        }
    }
    else
    {
        if((*_key = ftok(KEY_PATE, KEY_ID)) == -1)
        {
            perror("ftok");
            exit(1);
        }
    }
}

int Str_Msg_Send(MymsgBuf* _msgBuf,int _msqid,int _vFlag)
{
    int numOfBytes;

    if(fgets(_msgBuf->m_mBufId.m_msg, MAX, stdin) == NULL)
    {
        return 0;
    }
    numOfBytes = strlen(_msgBuf->m_mBufId.m_msg);
    if(_msgBuf->m_mBufId.m_msg[numOfBytes - 1] == '\n')
    {
        _msgBuf->m_mBufId.m_msg[numOfBytes - 1] = '\0';
    }
    PRINT_V((_vFlag),"msgsnd");
    if(msgsnd(_msqid, _msgBuf, numOfBytes + 1, IPC_NOWAIT) == -1)
    {
        return 0; 
    }

    return 1;
}
int Str_Msg_Res(MSQID _msqid,MymsgBuf* _msgBuf)
{
    if(msgrcv(_msqid, _msgBuf, sizeof (_msgBuf->m_mBufId), 0, 0) == -1)
    {
        perror("msgrcv");
        return 0;
    }
    PrintPid();
    printf("\nRec srt: %s from PID: %d\n",_msgBuf->m_mBufId.m_msg,_msgBuf->m_mBufId.m_pid);
    fflush(0);
    return 1;
}
int  Msq_Init(int *_msqid ,key_t _key)
{
    if ((*_msqid = msgget(_key,MODE | IPC_CREAT)) == -1)
    {
        return 0;
    }
    return 1;
}
/**semaphore */

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int InitSem(key_t key, int nsems)  /* key from ftok() */
{
    int i;
    union semun arg;
    struct semid_ds buf;
    struct sembuf sb;
    int semid,e,ready;

    semid = semget(key, nsems, IPC_CREAT | IPC_EXCL | 0666);

    if (semid >= 0) { /* we got it first */
        sb.sem_op = 1; sb.sem_flg = 0;
        arg.val = 1;

        printf("press return\n"); getchar();

        for(sb.sem_num = 0; sb.sem_num < nsems; sb.sem_num++) { 
            /* do a semop() to "free" the semaphores. */
            /* this sets the sem_otime field, as needed below. */
            if (semop(semid, &sb, 1) == -1) {
                e = errno;
                semctl(semid, 0, IPC_RMID); /* clean up */
                errno = e;
                return -1; /* error, check errno */
            }
        }

    } else if (errno == EEXIST) { /* someone else got it first */
        ready = 0;

        semid = semget(key, nsems, 0); /* get the id */
        if (semid < 0) return semid; /* error, check errno */

        /* wait for other process to initialize the semaphore: */
        arg.buf = &buf;
        for(i = 0; (i < MAX_RETRIES) && !ready; i++) {
            semctl(semid, nsems-1, IPC_STAT, arg);
            if (arg.buf->sem_otime != 0) {
                ready = 1;
            } else {
                sleep(1);
            }
        }
        if (!ready) {
            errno = ETIME;
            return -1;
        }
    } else {
        return semid; /* error, check errno */
    }

    return semid;
}    
