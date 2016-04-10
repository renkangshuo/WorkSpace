#include "csapp.h"
#include <sys/msg.h>
#include <sys/wait.h>

#define TYPEA 100
#define TYPEB 200

typedef struct {
	long type;
	char buf[64];
}MSG;

long len = sizeof(MSG) - sizeof(long);

int main(int argc, const char *argv[])
{
	key_t key;

	key = ftok(".", 'a');

	int msgid;
	pid_t pid;
	MSG mymsg;
	msgid = msgget(key, 0664 | IPC_CREAT);

	if (
	return 0;
}
