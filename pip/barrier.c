#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 700
#endif

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#define NUM_OF_COUNTERS	10
#define NUM_OF_ITERS	1

#define handle_error_en(en, msg) \
        do { errno = en; perror(msg); return 1; } while (0)

#define handle_error(msg) \
        do { perror(msg); return 1; } while (0)

const char ECHO_COUNTERS[] = "goodbye counterTrd #%d\n";
const char ECHO_SUM[] = "goodbye sumTrd\nsum: %ld\n";

typedef struct s_optVar
{
	int		m_numItrs;
	int		m_numCntrs;
} s_optVar;


typedef struct CntrsData
{
	pthread_barrier_t*	m_pb;
	int*				m_countArr;
	int					m_numItrs;
	int					m_idx;
} CntrsData;	

typedef struct SumData
{
	pthread_barrier_t*	m_pb;
	int*				m_countArr;
	int					m_numCntrs;
} SumData;	


/*********************************************************
						Opt_Init
*********************************************************/

void Opt_Init(s_optVar *_opt)
{
	_opt->m_numItrs		= NUM_OF_ITERS;
	_opt->m_numCntrs	= NUM_OF_COUNTERS;
}
	
/*********************************************************
						GetOpt
*********************************************************/

int GetOpt(int _argc, char** _argv, s_optVar *_opt)
{	
	int op;
	Opt_Init(_opt);
	
	while ((op = getopt(_argc, _argv, "l:c:")) != -1)
	{
		switch (op)
		{
			case 'l':
				_opt->m_numItrs	  = atoi(optarg);
				break;
			case 'c':
				_opt->m_numCntrs  = atoi(optarg);
				break;
			default: /* '?' */
            	fprintf(stderr, "getoptErr");
            	exit(EXIT_FAILURE);
		}
	}
	return 1;
}

/*********************************************************
					CounterFunc
*********************************************************/

void* CounterFunc(void* _cntrsData)
{
	CntrsData* cntrsData = (CntrsData*)_cntrsData;	
	int j, i;
	
	for(j = 0; j < cntrsData->m_numItrs; ++j)
	{
		for(i = 0; i < cntrsData->m_idx; ++i)
		{
			++(cntrsData->m_countArr[cntrsData->m_idx]);
			sleep(1);
		}
		pthread_barrier_wait(cntrsData->m_pb);
	}	
	
    return NULL;
}

/*********************************************************
					SumFunc
*********************************************************/

void* SumFunc(void* _sumData)
{
	SumData* sumData = (SumData*)_sumData;	
	int sum = 0;
	int i;
	
	pthread_barrier_wait(sumData->m_pb);
	
	for(i = 0; i < sumData->m_numCntrs; ++i)
	{
		sum += sumData->m_countArr[i];
	}

    return (void*)((intptr_t)(sum));
}

/*********************************************************
					InitCntrData
*********************************************************/

void InitCntrData(CntrsData* _cntrsData, pthread_barrier_t *_barrier, int *_countArr, int _numItrs, int _idx)
{
	_cntrsData->m_pb = _barrier;
	_cntrsData->m_countArr = _countArr;
	_cntrsData->m_numItrs = _numItrs;
	_cntrsData->m_idx = _idx;
}

/*********************************************************
							main
*********************************************************/

int main(int argc, char** argv)
{
	int 				status,idx;
	s_optVar 			opt;
	SumData				sumData;
	CntrsData*			cntrsData;
	pthread_t*			cntrsTrd;
	pthread_t			sumTrd;
	pthread_barrier_t	barrier;
	int*				countArr;
	int					expRes;
	intptr_t 			res;	

	GetOpt(argc, argv, &opt);

	status = pthread_barrier_init(&barrier, NULL, (opt.m_numCntrs + 1));
	if (status)
	{
		handle_error_en(status, "pthread_barrier_init");
	}
		
	cntrsTrd = (pthread_t*)calloc((size_t)opt.m_numCntrs, sizeof(pthread_t));
	if (cntrsTrd == NULL)
	{
		handle_error("calloc counters threads");
	}
	
	cntrsData = (CntrsData*)calloc(opt.m_numCntrs, sizeof(CntrsData));
	if (cntrsData == NULL)
	{
		handle_error("calloc counters cntrsData");
	}
	
	countArr = (int*)calloc(opt.m_numCntrs, sizeof(int));
	if (countArr == NULL)
	{
		handle_error("calloc count arr");
	}
	
	sumData.m_pb 		= &barrier;
	sumData.m_countArr 	= countArr;
	sumData.m_numCntrs	= opt.m_numCntrs;

	/*writer_create_thread*/
	status = pthread_create(&sumTrd, NULL, SumFunc, (void*)&sumData);
	if (status)
	{
		handle_error_en(status, "pthread_create sum");
	}
			
	/*readers_create_thread*/
	for (idx = 0; idx < opt.m_numCntrs; ++idx)
	{
		InitCntrData(&cntrsData[idx], &barrier, countArr, opt.m_numItrs, idx);
		
		status = pthread_create(&cntrsTrd[idx], NULL, CounterFunc, (void*)&cntrsData[idx]);
		if (status)
		{
			handle_error_en(status, "pthread_create counters");
		}
	}
	
	/*kill threads*/  
    for (idx = 0; idx < opt.m_numCntrs; ++idx)
    {
       	pthread_join(cntrsTrd[idx], NULL);
       	fprintf(stdout, ECHO_COUNTERS, idx);
    }
    
    
    pthread_join(sumTrd, (void**)&res);
    fprintf(stdout, ECHO_SUM, res);
    
    pthread_barrier_destroy(&barrier);	
	free(cntrsTrd);
	
    expRes = (((opt.m_numCntrs-1)*opt.m_numCntrs))/2;
    
    printf("exp sum: %d\n", expRes);
    if (res != expRes)
    {
    	return 1;
    } 
	
	return 0;	
}









