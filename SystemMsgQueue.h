#ifndef __SystemMsgQueue_H__
#define __SystemMsgQueue_H__
#include "queueIdTable.h"

//#define SYSMSGQ	0x9000
//#define INTERFACE_REQ	0x0001 

typedef enum _eInterface{
	INTERFACE_REQ = 1,
	INTERFACE_RSP_TUNNEL,
	INTERFACE_RSP_ETH,
}eInterface;






//========== new queue ===============

typedef struct _tSystemBuffer
{
	long	msgcmd_int;
	eInterface msgfrom_int;
	int len_int;
	char	data_achar[1024];
}tSystemBuffer;

int sendMsgToQueue
	(int queudid,tSystemBuffer *data_pstruct);


int recvMsgFromQueue
	(int queudid,tSystemBuffer *data_pstruct);


#endif


