#include <stdio.h>
#include <stddef.h>



void PrintHi()
{
    printf("\nHi\n");
}
void PrintStack(size_t _a1,size_t _a2,size_t _a3,size_t _a4,size_t _a5,size_t _a6,size_t _a7);

int main(void)
{
    PrintStack(1,2,3,4,5,6,7);

    return 0;
}
void PrintStack(size_t _a1,size_t _a2,size_t _a3,size_t _a4,size_t _a5,size_t _a6,size_t _a7)
{
    size_t* ptr;
    int i;

    ptr = &_a1;
    for(i = 0 ;i < 20; ++i)
    {
        printf("\n%d  \t\t\t  %p\n",*ptr,ptr);
        --ptr;
    }
    printf ("\nmain\t\t\t %p\n",main);
}

