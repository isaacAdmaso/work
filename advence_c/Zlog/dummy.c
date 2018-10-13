#include <stdio.h>
#include <unistd.h>
#include "logger.h"
#define MODULE "MODULE"
void foo()
{
    ZLOG(MODULE,LOG_TRACE,"try");
}
void foo1()
{
    ZLOG(MODULE,LOG_TRACE,"try");
}
void foo2()
{
    ZLOG(MODULE,LOG_TRACE,"try");
}
int main()
{
    int n;
    Zlog_Init("Confile.txt");
    n = fork();
    foo();
    if(n > 0)
    {
        foo1();
    }
    else
    {
        foo2();
    }
    foo();
    ZLOG(MODULE,LOG_TRACE,"try");
    Zlog_Destroy();
    foo();
    return 0;
}