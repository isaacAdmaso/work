#ifndef __PINGPONG_H__
#define __PINGPONG_H__


#include "CDR.h"/**for printing and debug*/

#define MSGQUE_NAME_DEFAULT "../"
#define MSGQUE_REGISTRAR	"REGISTRAR"

/* The values of message types are imporant - the registrar MUST be between other two */
#define MSG_TYPE_READ		  5
#define MSG_TYPE_REGISTRAR	  7
#define MSG_TYPE_DISPATCH  	  9



#endif /* __PINGPONG_H__ */
