/**
 * @file Reader.h
 * @brief read from file and send struct trow msq 
 * @version 0.1
 * @date 2018-11-20
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __READER_H__
#define __READER_H__
#include "CDR.h"/**for size of CDR object*/


#define MAX_LINE        1024
#define MAX_FNAME       256
#define MSG_TYPE_READ		      5




typedef void* (*PtrFunc)(char* _lineCDR);

#endif /*__READER_H__*/