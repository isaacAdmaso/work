#include "Pool.h"
#include <string.h>
#include <stdio.h>

int main()
{
    Pool* p = NULL;
    int* intPtr; 

    p = Pool_Create(4*sizeof(int),1);
    intPtr = MyMalloc(p);
    *intPtr = 1;
    *(++intPtr) = 2;
    *(++intPtr) = 3;
    printf("%d\n",*intPtr);
    printf("%d\n",*--intPtr);
    printf("%d\n",*--intPtr);
    MyFree(p,(void*)intPtr);
    Pool_Destroy(p);
    return 0;
}