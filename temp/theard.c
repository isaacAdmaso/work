#include <pthread.h>
#include <stdio.h>

#define TEN 10


void* PrintFnc(void* tid)
{
    int num = 3,*iPtr = &num;
    iPtr = (int*)tid;
    printf("\n%d\n",*iPtr);
    pthread_exit(NULL);
}

int main(void)
{
    int i,status,arr[] = {1,2,3,4,5,6,7,8,9,10};
    pthread_t threads[TEN];

    for(i = 0;i < TEN;++i)
    {

        status = pthread_create(&(threads[i]), NULL, PrintFnc, (void*)(arr+i));
    }
    for(i = 0;i < TEN;++i)
    {
        pthread_join(threads[i],NULL); 
    }
    return 0;
}
