#include <stdio.h>



union end
{
    int num;
    char ch;
};
int main()
{
 /*   
    int num = 12345678;

    printf("\n%d\n",(char)num);
*/
    union end num;
    num.num = 0x123fffff;
    printf("\n%x\n",num.num);
    printf("\n%c\n",num.ch);
    return 0;
}
