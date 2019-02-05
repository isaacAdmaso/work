#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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
        //int temp = i % 30;
        //switch (temp)
        //{
        //    case 1:
        //    case 7:
        //    case 11:
        //    case 13:
        //    case 17:
        //    case 19:
        //    case 23:
        //    case 29:
        //        printf("%d",temp);
        //        break;
        //    case 2:
        //    case 4:
        //    case 8:
        //    case 14:
        //    case 16:
        //    case 22:
        //    case 26:
        //    case 28:
        //        printf("%s","a");
        //        break;
        //    case 3:
        //    case 9:
        //    case 21:
        //    case 27:
        //        printf("%s","b");
        //        break;
        //    case 5:
        //    case 25:
        //        printf("%s","c");
        //        break;
//
        //    case 6:
        //    case 12:
        //    case 18:
        //    case 24:
        //        printf("%s","ab");
        //        break;
//
        //    case 10:
        //    case 20:
        //        printf("%s","ac");
        //        break;
//
        //    case 15:
        //        printf("%s","bc");
        //        break;
//
        //    case 30:
        //        printf("%s","abc");
        //        break;
        //}
        //printf("%s","\n");
    
    }
}

int main(int argc,char* argv[])
{
    solution(atoi(argv[1]));
    return 0;
}