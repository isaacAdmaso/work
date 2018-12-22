/**
 * @file errorHandle.h
 * @brief from gadi dbg experis
 * @version 0.1
 * @date 2018-12-22
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __ERRHANDLE_H__
#define __ERRHANDLE_H__
#include <stdio.h> /**printf */
#include <string.h>/**strerror -return string describing error */


#define HANDLE_ERR_EXIT(COND, RTVAL, MSG) do {\
            if(HandleError(COND, RTVAL, MSG,__FILE__,__LINE__,errno)) return EXIT_FAILURE;}while(0)

#define HANDLE_ERR_NO_EXIT(COND, RTVAL, MSG) HandleError(COND, RTVAL, MSG,__FILE__,__LINE__,errno)



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



#endif /*__ERRHANDLE_H__*/