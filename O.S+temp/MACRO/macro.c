#include <stdio.h>
#include "list.h"
#include 


int  main (void)
{
    List* l ;

    printf("before func: %s, in file: %s, in line: %d\non the: %s, in: %s \n ",__func__,__FILE__,__LINE__,__DATE__,__TIME__);
    l = List_Create();
    List_Destroy(&l,NULL);
    printf("after func: %s, in file: %s, in line: %d\non the: %s, in: %s \n ",__func__,__FILE__,__LINE__,__DATE__,__TIME__);
    return 0;
}