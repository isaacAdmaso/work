/**
 * @file Trigger.h
 * @brief ?
 * @version 0.1
 * @date 2018-11-21
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __TRIGGER_H__
#define __TRIGGER_H__

#include "CDR.h"/**for printing and debug*/

#define MSGQUE_NAME_DEFAULT       "../../"
#define MSGQUE_REGISTRAR	      "REGISTRAR"
#define MSG_TYPE_READ		      5
#define MSG_TYPE_REGISTRAR	      7
#define MSG_TYPE_DISPATCH  	      9
#define MAX                       1024
#define OUTPUT                    "./log.txt"
#define INFILE                    "./file.txt"
#define DIRPATH                   "./"
#define EXECUTABLE                "./Reader.out"
#define BUFF                      16
#define MFNSIZE                   256



typedef struct Trigger_t Trigger_t;



/**
 * @brief create Trigger
 * 
 */
Trigger_t* Trigger_Create(char* _executabe, char* _inFile, char* _outFile,char* _msqName,char* _nEnviron);

/**
 * @brief free _trigger  
 * 
 */
void  Trigger_Destory(Trigger_t* _trigger);


/**
 * @brief 
 * argv[0]  executabe
 * argv[1]  message queue id
 * argv[1]  input file path,
 * argv[2]  output path Dir,
 * argv[3]  size of struct after parse
 * argv[4]  parser dynemic lib,
 * argv[5]  parser function name
 * 
 */
void* Triger_Run(void* _trigger);


#endif /*__TRIGGER_H__*/