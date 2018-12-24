/**
 * @file errorHandle.c
 * @brief 
 * @version 0.1
 * @date 2018-12-22
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <stdio.h> /**printf */
#include <string.h>/**strerror -return string describing error */
#include "errorHandle.h"



int HandleError(int _cond, int _rtval, char* _msg, char* fileN, int lineN, int _errnoN){
    if(_cond){
        printf("Error in: %s\nrtval is: %d\nin file: %s line %d\n",
            _msg,_rtval,fileN,lineN);
        
        printf("errno #%d, errmsg: %s\n",_errnoN,strerror(_errnoN));
    }else{
        printf("rtval from %s is %d\n",_msg,_rtval);
    }
    fflush(stdout);
    return _cond;
}
