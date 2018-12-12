/**
 * @file virIO.cpp
 * @brief 
 * @version 0.1
 * @date 2018-12-11
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <stdio.h>
#include "virIO.h"

virIO_t::~virIO_t(){fclose(pFile);}
