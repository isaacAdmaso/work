/**
 
 solution -simple "print what i want" 
 
 my_size spin on  sizeof() operator
 
 and how to change CONST int 
 
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define NUM 30
#define my_size(type) ((char*)(&(type) + 1) -(char*)(&(type)))

/** tandem first q */
void solution(int N) 
{
    for(int i = 1; i <= N; ++i)
    {
        if(!(i%2) || !(i%3) || !(i%5))
        {
            if(!(i%2))
                printf("%s","a");
            
            if(!(i%3))
                printf("%s","b");
            
            if(!(i%5))
                printf("%s","c");
        }
        else
        {
            printf("%d",i);
        }
        printf("%c",'\n');
    }
}

int main(int argc,char* argv[])
{
    if(argc > 2)
        solution(atoi(argv[1]));
    else
        solution(NUM);
    const int i = 7;
    typedef struct P
    {
        int m_first;
        int m_second;
    }P;
    P k = {3,4};
    printf("const int size:%ld\n",my_size(i));
    printf("struct size:%ld\n",my_size(k));

    int *ptr = (int*)&i;
    *ptr = 1;
    printf("const:%d\n",i);
    printf("ptr:%d\n",*ptr);

    printf("const:%p\n",&i);
    printf("ptr:%p\n",ptr);

    return 0;
}