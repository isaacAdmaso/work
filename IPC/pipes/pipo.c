#include "pipo.h"
#define FIFO_DEF "MyFifo"


void Init(Input_Op* _inStc,int _argc, char *_argv[])
{
    _inStc->m_argv = _argv;
    _inStc->m_fileN = FIFO_DEF;
    _inStc->m_argc = _argc;
    _inStc->m_delete = 0;
    _inStc->m_numToRead = 0;
    _inStc->m_create = 0;
    _inStc->m_vFlag = 0;
    _inStc->m_sWorkSim = 0;
}
void Get_Op_Prm(Input_Op* _input,char* _str)
{
    int op = -1;
    extern char *optarg;
	extern int optind;

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
    