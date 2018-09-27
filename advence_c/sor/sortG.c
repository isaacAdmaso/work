#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

/*
int cmp( int* _a, int* _b)
{
    return *_a > *_b;
}
*/
int Sort(void*  const _elements, size_t _n, size_t _elemSize, int(*_less)(const void*, const void*))
{
    int i,j;
    char* const arr = _elements;
    void *val = malloc(_elemSize);

	for(i=1;i<_n;++i)
	{
		memcpy(val,arr+(i*_elemSize),_elemSize);
		j = i-1;
	/*Move elements bigger than val  */
		while (j >= 0 && _less(arr+(j*_elemSize),val))
		{
			memcpy(arr+((j+1)*_elemSize),arr+(j*_elemSize),_elemSize);
			--j;
		}
		memcpy(arr+((j+1)*_elemSize),val,_elemSize);
	}
	return 1;
}


int main()
{
    int i,a[] ={1,2,3,4,5,4,3,2,1,1,2,3,4,5,5};
    Sort(people,sizeof(people)/sizeof(people[0]),sizeof(people[0]),cmp);
    for( i = 0;i < sizeof(people)/sizeof(people[0]);++i)
        printf("%d,",people[i].id);
    return 0;
}



