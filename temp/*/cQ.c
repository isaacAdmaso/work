#include <stdio.h>


/*

int fn(int x3, unsigned int factor){
    return x3 / factor;
}
int main(void)
{
    int f1=0x2; // 0010
    int x1=0x8; // 1000
    int r1,r2;
    if(x1 | f1 != 10)// != is before |
	    printf("yes\n");
    else
	    printf("no\n");
 
    r1 = x1 * 8 + 1;
    r2 = x1<< 3 + 1;//+ is before <<
 
    if(r1==r2)
	    printf("yes\n");
    else
	    printf("no\n");
	
    printf("\n\n");
 
    int x2=10,y2=20,res2;
 
    switch(x2)
    {
 	    case 2:
            y2=10;  
            break;    
	    case 4:
            y2=33;
            break;
	    case 6:
            y2=44;
            break;
	    case 8:
            y2=55;
            break;
	    defualt:
            y2=100;	
            break;
    }  
    printf("y=%d\n",y2);
 
    printf("\n\n");
    
 
 
    int x3=-20,y3=10,res3;
 
    res3 = fn(x3,y3);
    printf("y=%d\n",res3);
 
    typedef struct {
	    int a;
	    int b;
    }T1;
 
    int a=90,res4;
    T1 m = {10,20};
    T1 *p = &m;
    res4 = p-->a;
    
    printf("res=%d\n",res4);
    return 0;
}
*/
void PrintM(int(*arr)[2])
{
    for(int i = 0 ,j = 0;i<2;++i)
    {
        for(;j<2;++j)
            printf("%d\n",*(*(arr+i)+j));
        j = 0;
    }
}
int main(int argc, char const *argv[])
{
    int arr[2][2] = {1,2,3,4};
    PrintM(arr);
    return 0;
}
