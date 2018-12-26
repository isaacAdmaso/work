#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t StrLen(const char* _str)
{
    size_t count = 0;

    if(NULL != _str)
       for(;*(_str++);++count);
    return count;
}

size_t StrLenRec(const char* _str)
{
    if(!*_str)
        return 0;
    return 1+StrLenRec(_str + 1);
}

char* StrCopy(char* _destination, const char* _source)
{
    char *start = _destination;
    while(( *(_destination++)=*(_source++) ));
    return start;
}


char* StrCopyRec(char* _destination, const char* _source)
{
    if(!*_source)
    {
        *_destination = '\0';
        return '\0';
    }
    *_destination = *_source;
    return StrCopyRec(_destination+1,_source +1);
}


char* StrNCopy(char* _destination, const char* _source, size_t _num)
{
    char *start = _destination;
    while(( *(_destination++)=*(_source++) ))
    {
        if(!--_num)
        {
            *_destination='\0';
            break;
        }
    }
    return start;
} 



char* StrNCopyRec(char* _destination, const char* _source, size_t _num)
{
    if(!*_source || _num == 0)
    {
        *_destination = '\0';
        return '\0';
    }
    *_destination = *_source;
    return StrNCopyRec(_destination+1,_source +1, _num - 1);
}


char* StrConcat(char* _destination, const char* _source)
{
    char* start = _destination;
    while((*(_destination++) != '\0'))
    {};
    while((*(_destination++) = *(_source++)))
    {};
    return start;
}

int StrCompare(const char* _s1, const char* _s2)
{
    while(!*_s1 || !*_s2)
    {
        if(*(_s1++) != *(_s2++))
            break;
        _s1++;
        _s2++;
    }
    return *(_s1) - *(_s2);
}

int StrComapreRec(const char* _s1, const char* _s2)
{
    if(!*_s1 ||  !*_s2)
    {
        return *_s1 - *_s2;
    }
    return  StrComapreRec(_s1+1,_s2+1);
}

void swap(void** _a,void** _b)
{
    void *temp ;
    temp = *_a;
    *_a = *_b;
    *_b = temp;
}

char* StrSubString(const char* _str, const char* _search)
{
    const char* ptrsrc ;
    while (*_str != '\0')
    {
        ptrsrc = _search;
        while (*ptrsrc == *_str && *ptrsrc != '\0') 
        {
            ptrsrc++;
            _str++;
        }
        if (*ptrsrc == '\0') 
            break;        
        _str-=(ptrsrc - _search - 1); 
    }
    return (char*)(_str - (ptrsrc - _search));
}

    
int main()
{
    
    char str[16] = "abcdxyzef";
    int i;
    char str2[8] = "xyz";
    char* p[3]={"yits","adm","hakaso"};
    
    for( i = 0;i < 3;++i)
        printf("%s, ",p[i]);
    swap((void**)p+2,(void**)p);
    printf("\n");
    for( i = 0;i < 3;++i)
        printf("%s, ",p[i]);
    
    printf("\n  %s %s %s\n",str,str2,StrSubString(str,str2));
    printf("StrlenR of %s: is %ld\n",str,StrLenRec(str));
    printf("%s\n",str);

    return 0;
}

