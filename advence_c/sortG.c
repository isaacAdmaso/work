#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.c"


int cmp(const Person* _a,const Person* _b)
{
    return _a->random > _b->random;
}
int Sort(void* _elements, size_t _n, size_t _elemSize, int(*_less)(const void*, const void*))
{
    int i,j;
    void *val = malloc(_elemSize);

	for(i=1;i<_n;++i)
	{
		memcpy(val,_elements+(i*_elemSize),_elemSize);
		j = i-1;
	/*Move elements bigger than val  */
		while (j >= 0 && _less(_elements+(j*_elemSize),val))
		{
			memcpy(_elements+((j+1)*_elemSize),_elements+(j*_elemSize),_elemSize);
			--j;
		}
		memcpy(_elements+((j+1)*_elemSize),val,_elemSize);
	}
	return 1;
}

int main()
{
    int i,a[] ={1,2,3,4,5,4,3,2,1,1,2,3,4,5,5};
    Sort(a,100*sizeof(Person),sizeof(Person),cmp);
    for( i = 0;i < 100;++i)
        printf("%d,",people[i].random);
    return 0;
}



