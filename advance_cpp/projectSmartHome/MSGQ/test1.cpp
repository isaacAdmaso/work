#include "Msgq.h"
#include <unistd.h>
#include <iostream> 







int main()
{
    Msgq mq("/MSGQ",10,512);
    char msg[] = "hello #2!!!";
    char buf[512];

    mq.Msq_Send(msg,sizeof(msg)+1);
    sleep(3);
    mq.Msq_Receive(buf,512);
    std::cout<<buf<<std::endl;

    return 0;
}
