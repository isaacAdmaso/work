#include "config.h"
#include <stdio.h>
#include "assert.h"

static configData OpenConfig(char*_configFileN)
{
    File* conFp = NULL;
    configData c_Data;
    
    conFp = fopen(_configFileN,"r");
    assert(conFp != NULL);
    fscanf(conFp,"%s",c_Data.m_level);
    fscanf(conFp,"%s",c_Data.m_fileTo);
    return c_Data;
}
