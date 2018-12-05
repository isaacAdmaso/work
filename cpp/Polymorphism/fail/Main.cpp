/**
 * @file Main.cpp
 * @author your name (you@domain.com)
 * @brief test
 * @version 0.1
 * @date 2018-12-05
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "memPool.h"
#include "memPage.h"
#include "memManager.h"


void testW(memManager_t* _poly,void* _buf)
{
    (*_poly).write(_buf,sizeof (int));
}

void testR(memManager_t* _poly,void* _buf) 
{
    (*_poly).read(0,_buf,sizeof (int));
}


int main(int argc, char const *argv[])
{
    int num = 333;
    int rt;
    memPage_t page(1);
    testW(&page,&num);
    testR(&page,&rt);
    cout << rt<<endl;
    /*
    memPool_t pool(11);

    testW(&pool,&num);
    testR(&pool,&rt);
    cout << rt<<endl;
*/
    return 0;
}
