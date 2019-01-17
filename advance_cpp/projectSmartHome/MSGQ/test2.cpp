#include "Msgq.h"
#include <unistd.h>
#include <iostream> 


int main()
{
    Msgq mq("/MSGQ",10,512);

    char msg[] = "goodbye #1!!!";
    char buf[1024];

    mq.Msq_Receive(buf,1024);
    mq.Msq_Send(msg,sizeof(msg)+1);
    std::cout<<buf<<std::endl;
        
    return 0;
}
