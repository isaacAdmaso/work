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



#define HANDLE_ERR_EXIT(COND, RTVAL, MSG) do {\
            if(HandleError(COND, RTVAL, MSG,__FILE__,__LINE__,errno)) exit(EXIT_FAILURE);}while(0)

#define HANDLE_ERR_NO_EXIT(COND, RTVAL, MSG) HandleError(COND, RTVAL, MSG,__FILE__,__LINE__,errno)



int HandleError(int _cond, int _rtval, char* _msg, char* fileN, int lineN, int _errnoN);



#endif /*__ERRHANDLE_H__*/