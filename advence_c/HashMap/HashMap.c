#include "HashMap.h"
#include "../../include/list_itr.h"
#include <stdlib.h>


#define MAGIC 1073741824
#define MININPUT 1
#define IS_INVALID(H) ((NULL == (H)) || (H)->m_magic != MAGIC)


struct HashMap
{
	size_t m_magic; 
    List** m_items;			                /*data hoder*/
	size_t m_size;			                /*actual DS size*/
	size_t m_noItems;		                /* number of inputs*/
	size_t m_capacity;		                /*client max inputs*/
    HashFunction m_hashFunc;                /*Hash func given by client*/
    EqualityFunction m_keysEqualFunc;        /* Equality Function given by client*/
};


static int GetNumber(int _number);/*next prime number*/

/** 
 * @brief Create a new hash map with given capcity and key characteristics.
 * @param[in] _capacity - Expected max capacity 
 * 						  shall be rounded to nearest larger prime number.
 * @param[in] _hashFunc - hashing function for keys
 * @param[in] _keysEqualFunc - equality check function for keys. 
 * @return newly created map or null on failure
 */
HashMap* HashMap_Create(size_t _capacity, HashFunction _hashFunc, EqualityFunction _keysEqualFunc)
{
    HashMap *h;
	int primeN; 
	
	/*parameter check*/
	if(_capacity <= MININPUT)
	{
		return NULL;
	}
	h = (HashMap*)malloc(sizeof(HashMap));
    if(NULL == h)
	{
		return NULL;
	}
	/*real capacity*/
	primeN = GetNumber(_capacity);
    h->m_items =(List**)malloc(primeN*sizeof(List*));
    
    if(NULL == h->m_items)
	{
		free(h);
		return NULL;
	}
    h->m_size = primeN;
	h->m_noItems = 0;
	h->m_hashFunc = _hashFunc;
	h->m_capacity = _capacity;
	h->m_magic = MAGIC;
	return h;
}

static int IsPrime(int _n)
{
    int i;

    if (_n <= 1) return 0;
    if (_n <= 3) return 1;
    if (_n%2 == 0 || _n%3 == 0) return 0;
    for (i = 5; i*i <= _n; i = i+6)
        if (_n%i == 0 || _n%(i+2) == 0)
           return 0;
    return 1;
}

static int GetNumber(int _number)
{
	while (1)
    {
        if (IsPrime(_number)) break;
        ++_number;
    }
    return _number;
}
