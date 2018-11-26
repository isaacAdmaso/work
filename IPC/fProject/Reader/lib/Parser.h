/**
 * @file Parser.h
 * @brief  parsing line to struct cdr
 * @version 0.1
 * @date 2018-11-19
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __PARSER_H__
#define __PARSER_H__
#include <string.h>


#define STR_CDR_ORDER    "ScMCITDtdplmi"/**order of fields in cdr line */



void* Parser1(char* _lineCDR);



#endif /*__PARSER_H__*/


