#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
 void hanoi(int _n,char _from,char _to, char _via)
 {
 	if(_n == 0)
 	{
 		return;
 	}
 	hanoi(_n-1, _from, _via, _to);
 	printf("Move disc %d from %c to %c via %c\n",_n,_from,_to,_via);
	hanoi(_n-1, _via, _to, _from);
 }
 
 
int main()
{
	hanoi(5,'a','c','b');
	return 0;
	
}
