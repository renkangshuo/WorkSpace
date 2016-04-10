#include "server.h"
#include "csapp.h"

MSG message, message1;
char usrname[20];
char passwd[20];
int connfd;
sqlite3 *fdb;
char *serror = 0;

int history_found = 0; // Used in do_history
int login_found = 0; // Used in do_login
int query_found = 0; // Used in do_query
int register_found = 0; // Used in do_register
int passwd_found = 0;

struct msg1 {
	int type;
	char name[N];
	char data[256];
};

void dosomething1(int);
int login_passwd_callback(void* notused, int num, char** s1, char** scol)
{
	printf("In login_passwd_callback\n");
	printf("Usrpasswd is %s\n", passwd);
	
	if (strcmp(s1[2], passwd) == 0)
	{
		passwd_found = 1;	// The passwd is verified, passwd_found is set to 1

	}

	printf("After strcmp\n");
	// If not ,the passwd_found is still remain zero
	//
	return 0;
}
int query_callback(void* notused, int num, char** s1, char** scol)
{
	printf("In query_callback\n");
	query_found = 1;
	static int num1 = 0;

	/* time */
	time_t time1;
//	time1 =	time();
	time(&time1);

	char st[40];
	char* stp;
	stp = ctime(&time1);
	strcpy(st, stp);
	st[strlen(st)-1] = '\0';


	int i;
	int ret;
	char sc[1024];// Important
	bzero(sc, 1024);

	bzero(message1.data, sizeof(message1.data));

	// Send the meaning of the word to the clientlen
	printf("%s :::::::::: %s\n", s1[1], s1[2]);
	printf("Usrname is %s\n", usrname);
//	printf("%s : %s\n", scol[1], scol[2]);
	message1.type = 1;
	sprintf(message1.data, "%s:  %s", s1[1], s1[2]); 
	send(connfd, &message1, sizeof(MSG), 0);
	// Add the word to the record ,the usrname and the time to the record table
	
	sprintf(sc, "insert into record values(%d, '%s', '%s', '%s', '%s')", num1, st, s1[1], s1[2], usrname);
	ret = sqlite3_exec(fdb, sc, NULL, NULL, &serror);
	if (ret != SQLITE_OK) 
	{
		printf("error: fail to %s\n", serror);
		serror = NULL;
		return -1;
	}

	num1++;

	return 0;
}
int register_callback(void* notused, int num, char** s1, char** scol)
{
	register_found = 1;

	return 0;
}
int login_callback(void *notused, int num, char** s1, char** scol)
{
	login_found = 1;

	return 0;
}
/* send the meaning of the word once */
int history_callback(void *notused, int num, char** s1, char** scol)
{
	printf("In history_callback\n");
	history_found = 1;	
	bzero(message1.data, sizeof(message1.data));

	message1.type = 0;
	// Send word meaning and time to the usr
	sprintf(message1.data, "%s:  %s added on %s", s1[2], s1[3], s1[1]);
	send(connfd, &message1, sizeof(MSG), 0);

	return 0;
}

void sigchld_handler(int sig)
{
	while (waitpid(-1, 0, WNOHANG) > 0)
		;
	return;
}




int main(int argc, const char *argv[])
{
	if (argc < 2) {
		printf("Usage: <port>\n");
		exit(-1);
	}

	sqlite3_open("./data.db", &fdb);
	int listenfd;
	int port;
	socklen_t clientlen = sizeof(struct sockaddr_in);
	struct sockaddr_in clientaddr;

	Signal(SIGCHLD, sigchld_handler);
	port = atoi(argv[1]);

	listenfd = Open_listenfd(port);
	bzero(message.name, sizeof(message.name));
	bzero(message.data, sizeof(message.data));
#if 1
	bzero(message1.name, sizeof(message1.name));
	bzero(message1.data, sizeof(message1.data));
#endif

	
	while (1) {
		connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
		if (Fork() == 0) {
			Close(listenfd);
		//	dosomething1(connfd);
			do_client(connfd);
			Close(connfd);
			exit(0);
		}
		Close(connfd);
	}
	return 0;
}

void do_query(int connfd , MSG* msg, sqlite3* fdb)
{
	printf("In do_query\n");
	int ret;
	char s[256];
	bzero(s, 256);
	sprintf(s, "select * from word where literal='%s'", msg->data);

	ret = sqlite3_exec(fdb, s, query_callback, NULL, &serror);

	if (ret != SQLITE_OK)
	{
		printf("error: fail to %s\n", serror);
		serror = NULL;
		return;
	}

	if (query_found == 0) // Word not found
	{
		msg->type = -1; // Indicates that the word not found
		send(connfd, msg, sizeof(MSG), 0);
		return;
	}

	query_found = 0; // For the next do_query

	return;
}

void do_history(int connfd, MSG* msg, sqlite3* fdb)
{
	//printf("In do_history\n");
	int ret;
	//char *s1 = "select * from record";
	char s1[256];
	bzero(s1, 256);
	sprintf(s1, "select * from record where usrname='%s'", msg->name);
	ret = sqlite3_exec(fdb, s1, history_callback, NULL, &serror);
	
	if (ret != SQLITE_OK)
	{
		printf("error: fail to %s\n", serror);
		serror = NULL;
		return;
	}

	if (history_found == 0) {// This usr has no history on the server
		msg->type = -1; // indicates that there is no history in the server
		send(connfd, msg, sizeof(MSG), 0);
		return;
	}

	if (history_found == 1) // Historycall has send the information to the usr
	{
		msg->type = 201; // Indicates that there is no history to send , usr can quit
		send(connfd, msg, sizeof(MSG), 0);
	}

	history_found = 0; // For the next do_history
	
	return;
}

void do_login(int connfd, MSG* msg, sqlite3* fdb)
{
	printf("In do_login\n");
	printf("The passwd of this usr is %s\n", msg->data);
	printf("The usrname of this usr is %s\n", msg->name);
	strcpy(passwd, msg->data);
	int ret;
	char s[256];
	bzero(s, 256);
	sprintf(s, "select * from usr where usrname='%s'", msg->name);

	ret = sqlite3_exec(fdb, s, login_callback, NULL, &serror);
	/* The usrname does not exist in the database */
	if (ret != SQLITE_OK) {
		printf("error: fail to %s\n", serror);
		serror = NULL;
		return;
	}

	if (login_found == 0) { // The usrname is not in the database
		msg->type = -1;
		send(connfd, msg, sizeof(MSG), 0);
		return;
	}

	/* The usrname does exist in the database */
	/* Server need to verify the passwd of the usr */
	bzero(s, 256);
	sprintf(s, "select * from usr where usrname='%s'", msg->name);
	printf("After passwd sqlite3_exec\n");
	ret = sqlite3_exec(fdb, s, login_passwd_callback, NULL, &serror);
	if (ret != SQLITE_OK) {
		printf("error: fail to %s\n", serror);
		serror = NULL;
		return;
	}
	// If passwd is not verified 
	if (passwd_found == 0) {
		msg->type = -2;
		send(connfd, msg, sizeof(MSG), 0);
		return;
	}

	if (passwd_found == 1) {	// Now the passwd is verified
		msg->type = 1; //Indicates that server has the usrname
		send(connfd, msg, sizeof(MSG), 0); //Inform the client , so it can do something
		login_found = 0; // For next login
		passwd_found = 0;
	}

	return;
}

void do_register(int connfd, MSG* msg, sqlite3* fdb)
{
	printf("In do_register\n");
	static num = 0; // counter for the number of usr names in the database */
	
	int ret;
	char s[256]; // Command line for the sqlite3_exec
	char s1[256]; // Command line for the sqlite3_exec
	bzero(s, 256);
	bzero(s1, 256);

	sprintf(s1, "select * from usr where usrname='%s';", msg->name);

	ret = sqlite3_exec(fdb, s1, register_callback, NULL, &serror);
	printf("After sqlite3_exec register\n");

	if (ret != SQLITE_OK) {
		printf("error: fail to %s\n", serror);
		serror = NULL;
		return;
	}
	/* The usrname has already been added into the database */
	if (register_found == 1) {
		msg->type = -1; // Indicates that usrname is in the database, you can log in use this usrname
		send(connfd, msg, sizeof(MSG), 0);
		return;
	}

	sprintf(s, "insert into usr values(%d, '%s', '%s');", num, msg->name, msg->data); // Add usrname and their passwd into this database

	ret = sqlite3_exec(fdb, s, NULL, NULL, &serror);
	if (ret != SQLITE_OK) {
		printf("error: fail to %s\n", serror);
		serror = NULL;
		return;
	}
	/* The usrname was not in the database. now it has been added into the
	 * database */
	msg->type = 1;
	send(connfd, msg, sizeof(MSG), 0);
	num++; // number for the next register operation
	register_found = 0; // For the next register operation
	return;
	
}

void do_client(int connfd)
{
	while (recv(connfd, &message, sizeof(message), 0))
	{
		strcpy(usrname, message.name);
		printf("While: usrnameis%s\n", usrname);
		switch(message.type) {
		case R:
			printf("In do_register\n");
			do_register(connfd, &message, fdb); break;
		case L:
			printf("In do_login\n");
			do_login(connfd, &message, fdb); break;
		case Q:
			printf("In do_query\n");
			do_query(connfd, &message, fdb); break;
		case H:
			printf("In do_history\n");
			do_history(connfd, &message, fdb); break;
		default:
			break;
		}
	}

	return;
}

void dosomething1(int connfd)
{
	while (recv(connfd, &message, sizeof(MSG), 0))
	{
		printf("name=%s data=%s\n", message.name, message.data);

		sprintf(message1.name, "we get %s", message.name);
		sprintf(message1.data, "we also get %s", message.data);

		bzero(message.name, sizeof(message.name));
		bzero(message.data, sizeof(message.data));

		send(connfd, &message1, sizeof(MSG), 0);

		bzero(message.name, sizeof(message1.name));
		bzero(message.data, sizeof(message1.data));

	}
}
