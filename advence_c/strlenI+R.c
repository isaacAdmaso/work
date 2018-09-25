#include <stdio.h>


int StrLenI(const char* _s)
{
    int count = 0;

    if(NULL != _s)
       for(;*(_s++);++count);
    return count;
}

int StrLenR(const char *_s)
{
    if('\0' == *_s)
        return 0;
    return 1+StrLenR(_s + 1);
}

void StrCpyI(char*_s1,const char* _s2)
{
 
    while( *(_s1++)=*(_s2++));
}
void StrCpyR(char*_s1,const char* _s2)
{
    if(!*_s2 || !*_s1)
        return;
    StrCpyR(_s1 +1,_s2);

    
}
int main()
{
    char str[16] = "abcdef";
    char str2[8] = "xyz";
    /* code */
    StrCpyI(str,str2);
    printf("StrlenI of %s: is %d\n",str,StrLenI(str));
    printf("StrlenR of %s: is %d\n",str,StrLenR(str));
    printf("%s\n",str);
    return 0;
}

