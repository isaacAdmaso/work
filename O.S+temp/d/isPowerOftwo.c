#include <stdio.h>
#include <string.h>

int Is_Pwr_of_Two(int num)
{
    int i,j,size = sizeof(int)*8;

    for(i = 0;i < size ;++i)
    {
        if(num & 1<<i)
        {
            for(j = i + 1;j < size;j++)
            {
                if(num & 1<<j)
                    return 0;
            }
            return 1;
        }
    }
    return 0 ;
}

int main(int argc, char const *argv[])
{
    int num =   atoi(argv[1]);
    printf("\n%d\n",Is_Pwr_of_Two(num));  
    return 0;
}
