#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX 1024
#define DEFAULT 7 
#define LETTER "y"
#define STR_OPT "n:wi:"
const char USAGE[]	="\nUsage: %s [-w] [-n] [-i number of iteration] \n";


typedef struct Msg
{
    pthread_mutex_t m_myMutex;
    pthread_cond_t m_W_cond;
    pthread_cond_t m_R_cond;
    int m_W_predicate;
    int m_R_predicate;
    int m_whileF;
    char m_msg[1];
}Msg_t;


void *WriteMsg(void* _msg)
{
    Msg_t *msg = _msg;
    
    pthread_mutex_lock(&(msg->m_myMutex));
    if(msg->m_whileF)
    {
        while (!msg->m_W_predicate)
        {
            pthread_cond_wait(&(msg->m_W_cond), &(msg->m_myMutex));
        }
        msg->m_R_predicate = 1;
    }
    else
    {
        pthread_cond_wait(&(msg->m_W_cond), &(msg->m_myMutex));
    }
    strcpy(msg->m_msg,LETTER);
    pthread_cond_broadcast(&(msg->m_R_cond));
    pthread_mutex_unlock(&(msg->m_myMutex)); 
    return NULL;
}

void* ReadMsg(void* _msg)
{
    Msg_t *msg = _msg;
    pthread_t id;

    pthread_mutex_lock(&(msg->m_myMutex));

    id = pthread_self();
    msg->m_W_predicate = 1;
    pthread_cond_signal(&(msg->m_W_cond));
    if(msg->m_whileF)
    {
        while (!msg->m_R_predicate)
        {
            pthread_cond_wait(&(msg->m_R_cond), &(msg->m_myMutex));
        }
    }
    else
    {
        pthread_cond_wait(&(msg->m_R_cond), &(msg->m_myMutex));
    }
    fprintf(stdout,"%ld -> %s ,",id,msg->m_msg);

    pthread_mutex_unlock(&(msg->m_myMutex));
    return NULL;
}

int main(int argc, char *argv[])
{
    int opt = -1,nReaders = DEFAULT,i,j,nIter = DEFAULT;
    extern char *optarg;
	extern int optind;
    Msg_t send = {0};
    pthread_t writer,*readers;
    


    while (-1 != (opt = getopt(argc, argv,STR_OPT)))
    {
		switch (opt)
        {
		case 'w':	
			send.m_whileF = 1;
			break;
		case 'n':	
			nReaders = atoi(optarg);
			break;
		case 'i':	
			nIter = atoi(optarg);
			break;
		default: /* '?' */
			fprintf(stderr, USAGE, argv[0]);
			return 1;
		}
	}

    readers = calloc(nReaders,sizeof(pthread_t));

    for(j = 0;j < nIter;++j)
    {

        if(pthread_cond_init(&(send.m_W_cond),NULL))
        {
            fprintf(stderr, "\nError init of cond\n");
            return 1;
        }
        if(pthread_cond_init(&(send.m_R_cond),NULL))
        {
            fprintf(stderr, "\nError init of cond\n");
            return 1;
        }
        if(pthread_mutex_init(&(send.m_myMutex),NULL))
        {
            fprintf(stderr, "\nError init of mutex\n");
            return 1;
        }
        
        if(pthread_create(&writer,NULL,WriteMsg,(void*)&send))
        {
            fprintf(stderr, "\nError creating W thread\n");
            return 1;
        }
    
        for(i = 0;i < nReaders;++i)
        {
            if(pthread_create(&readers[i], NULL,ReadMsg,(void*)&send))
            {
                fprintf(stderr, "\nError creating thread\n");
                if(i > 0)
                {
                    nReaders = i;
                    break;
                }
                else
                {
                    return 1;
                }
            }
        }
        if(pthread_join(writer, NULL))
        {
            fprintf(stderr, "Error joining writer thread\n");
            return 1;
        }
        for(i = 0;i < nReaders;++i)
        {
            if(pthread_join(readers[i], NULL))
            {
                fprintf(stderr, "Error joining writer thread\n");
                return 1;
            }
        }
        pthread_mutex_destroy(&(send.m_myMutex));
        pthread_cond_destroy(&(send.m_W_cond));
        pthread_cond_destroy(&(send.m_R_cond));

        printf("\nend of %d iteration\n",j+1);  
    } 
    free(readers); 

    return 0;
}

