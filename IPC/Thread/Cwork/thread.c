#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define MAX 1024


void* Print_t(void* _data)
{
    int data = (int)_data;
    pthread_t id = pthread_self();

    printf("\nthread #%d( with id #%lu)  is in Print_t\n",data,id);
    return _data;
}
/*
typedef struct p_type
{
    pthread_attr_t atr;
    size_t stksize;
}p_type;
*/
int main(int argc, char *argv[])
{

    size_t stkSize; 
    pthread_attr_t atr; 
    pthread_t* arr;
    int i,opt,n = MAX,sleepTime = 0,count = 0;
    extern char *optarg;
	extern int optind;


    while (-1 != (opt = getopt(argc, argv, "n:s:"))) {
        switch (opt) {
        case 'n':	/* MsgQue name */
            n = atoi(optarg);
            break;
		case 's':	/* millisecond to sleep between messages */
			sleepTime = atoi(optarg) * 1000;
			break;
        default: /* '?' */
            return 1;
        }
    }

    pthread_attr_getstacksize(&atr, &stkSize);
    printf("\nthread stack size is %ld\n",stkSize);
    pthread_attr_setstacksize(&atr, 320000034); 
    pthread_attr_getstacksize(&atr, &stkSize);
    printf("\nNEW thread stack size is %ld\n",stkSize);

    arr = malloc( n*sizeof(pthread_t));
    for(i = 0; i < n; ++i)
    {
        if(pthread_create(&arr[i], NULL, Print_t,(void*)i))
        {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }
    if(sleepTime)
    {
        usleep(sleepTime);
    }
    for(i = 0; i < n;++i)
    {
        if(pthread_join(arr[i], NULL))
        {
            fprintf(stderr, "Error joining thread\n");
            return 1;
        }
        printf("\ngoodbye from thread #%d \n",i);
        ++count;
    }
    free(arr);
    printf("\n# of threads %d\n",count);
    return 0;
}
