#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#include "SystemMsgQueue.h"

static int getsystemMsgQueueID(int keyroot_int)
{
	int qid_int;
	key_t key ;
	key = keyroot_int;
	qid_int = msgget(key,0);

	if(  qid_int  < 0 )
	{
		qid_int  = msgget(key,IPC_CREAT|0666);
	}
	return qid_int;
}


int sendMsgToQueue
	(int queudid_int,tSystemBuffer *data_pstruct)
{

	int ret_int;
	ret_int = msgsnd(getsystemMsgQueueID(queudid_int),
		data_pstruct,
		sizeof(tSystemBuffer)-sizeof(long), 0);
	return ret_int;
}



int recvMsgFromQueue
	(int queudid_int,tSystemBuffer *data_pstruct)
{

	int ret_int;
	ret_int = msgrcv( getsystemMsgQueueID(queudid_int),
		data_pstruct,
		sizeof(tSystemBuffer) - sizeof(long),
		data_pstruct->msgcmd_int, 0);
	return ret_int;
}






