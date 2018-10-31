#include <sys/msg.h>
#define KEY_PATE "./ping.c" 
#define KEY_ID 'A'

int main(int argc, char const *argv[])
{
    key_t key;
    int msqid;
    
    key = ftok(KEY_PATE, KEY_ID);
    msqid = msgget(key,IPC_CREAT);
    return 0;
}
