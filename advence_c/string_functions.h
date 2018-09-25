#ifndef __STR_LIB_H__
#define __STR_LIB_H__
#include <stdlib.h>



/**
 * Compute string length
 */
size_t StrLen(const char* _str);

/**
 * Compute string length with recursion
 */
size_t StrLenRec(const char* _str);

/**
 *  Compare two strings, return negative s1 < s2, zero if s1==s2, positive otherwise
 */
int StrCompare(const char* _s1, const char* _s2);
int StrComapreRec(const char* _s1, const char* _s2);


char* StrCopy(char* _destination, const char* _source);
char* StrCopyRec(char* _destination, const char* _source);

/**
 * copies at most N (including null) characters from source to destination
 */
char* StrNCopy(char* _destination, const char* _source, size_t _num);
char* StrNCopyRec(char* _destination, const char* _source, size_t _num);

/**
 * Concatenate strings
 */
char* StrConcat(char* _destination, const char* _source);


/**
 * search for substring in a string (strstr)
 */
char* StrSubString(const char* _str, const char* _search);

#endif /*__STR_LIB_H__*/
