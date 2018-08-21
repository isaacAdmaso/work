#include<stdio.h>

void MulTblLine(int num1, int num2)
{
   if ( num2 > 1 )
   {
      MulTblLine(num1, num2-1);
   }
   printf("%2d ", num1*num2);
}

void MulTbl(int num1, int num2)
{
   if ( num1 > 1 )
   {
      MulTbl(num1-1, num2);
   }
   MulTblLine(num1, num2);
   printf("\n");
}

int main()
{
   MulTbl(5, 3);
}
	
