#include "client.h"
#include "csapp.h"

struct msg1 {
	int type;
	char name[N];
	char data[256];
};

MSG message;
int found = 0;
char usrname[20];

int main(int argc, const char *argv[])
{
#if 1
	int clientfd;
	int port;
	char *host;

	if (argc != 3) {
		fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
		exit(0);
	}
	host = argv[1];
	port = atoi(argv[2]);

	clientfd = Open_clientfd(host, port);
#endif

	int command; // Command the usr is about to input 

	while (1) {
		printf("********************************\n");
		printf("1:register 2:login 3:quit\n");
		printf("********************************\n");
		printf("Please choose : \n");
		scanf("%d", &command);

		switch(command)
		{
		case 1: printf("\n");
				printf("do_register\n");
				do_register(clientfd, &message);
				printf("\n");
				break;
		case 2: 
				printf("\n");
				printf("do_login\n");
				if (do_login(clientfd, &message) == 1) {
					printf("\n");
					goto next;
				}

				printf("\n");
				break;
		case 3:
				printf("\n");
				printf("exit\n");
				Close(clientfd);
				exit(0);
				printf("\n");
				break;

		default:
				break;
		}
		continue;
next:
		while (1) {
			printf("****************************************\n");
			printf("1: query_word 2: history_record 3: quit \n");
			printf("\n");
			printf("Please choose one of the options from above\n");
			scanf("%d", &command);

			switch (command) {
			case 1:
				printf("\n");
				do_query(clientfd, &message);
				printf("\n");
				break;
			case 2:
				printf("\n");
				do_history(clientfd, &message);
				printf("\n");
				break;
			case 3:
				printf("\n");
				Close(clientfd);
				exit(0);
				break;
			}
		}
	}
}

void do_register(int clientfd, MSG* msg)
{
	msg->type = R;
	printf("name:");
	scanf("%s", msg->name); //name
	printf("\n");
	printf("passwd:");
	scanf("%s", msg->data); // passwd
	printf("\n");
	send(clientfd, msg, sizeof(MSG), 0);
//	bzero(msg->data, sizeof(msg->data));
	bzero(msg, sizeof(MSG));

	recv(clientfd, msg, sizeof(MSG), 0);
	if (msg->type == -1) {
		printf("The usrname has been registered\n");
		printf("Please login\n");
		return;
	}

	if (msg->type == 1) {
		printf("You has registered successfully\n");
		printf("Now you can login\n");
		return;
	}
//	printf("%s\n", msg->name);
//	printf("%s\n", msg->data);

	return;
	
}

int do_login(int clientfd, MSG* msg)
{
	msg->type = L;
	printf("name:");

	scanf("%s", msg->name); //name
	printf("\n");
	strcpy(usrname, msg->name);
	printf("Usrname is %s\n", usrname);

	printf("passwd:");
	scanf("%s", msg->data); // passwd
	printf("\n");
	send(clientfd, msg, sizeof(MSG), 0);
//	bzero(msg->data, sizeof(msg->data));
	bzero(msg, sizeof(MSG));


	recv(clientfd, msg, sizeof(MSG), 0);
	if (msg->type == -1) {
		printf("The usrname is not registered\n");
		printf("Please register and login\n");
		return 0;
	}
	if (msg->type == -2) {
		printf("Wrong passwd\n");
		printf("\n");
		printf("Please try again\n");
		return 0;
	}

	if (msg->type == 1) {
		printf("You have logged in successfully\n");
		printf("Enjoy the dict\n");
		return 1;
	}
	//printf("%s\n", msg->name);
	//printf("%s\n", msg->data);
}

void do_query(int connfd, MSG* msg)
{
	while (1) {
		bzero(msg, sizeof(MSG));
		msg->type = Q;
		strcpy(msg->name, usrname);
		printf("Usrname is %s\n", usrname);
		printf("Input word:");
		printf("\n");

		scanf("%s", msg->data);
		if (strncmp(msg->data, "#", 2) == 0)
			return;

		
		send(connfd, msg, sizeof(MSG), 0);
//		bzero(msg->data, sizeof(msg->data));

		recv(connfd, msg, sizeof(MSG), 0);
		if (msg->type == -1) {
			printf("The word not found\n");
			continue;
		}

		if (msg->type == 1) {
			printf("The result is %s\n", msg->data);
			continue;
		}

	}
}

void do_history(int clientfd, MSG*msg)
{
	msg->type = H;
	send(clientfd, msg, sizeof(MSG), 0);
	//bzero(msg->data, sizeof(msg->data));
	bzero(msg, sizeof(MSG));


	while (recv(clientfd, msg, sizeof(MSG), 0)) { //There maybe multiple results of history
		if (msg->type == -1) {
			printf("No history\n");
			return;
		}

		if (msg->type == 0) {
			printf("Have history\n");
			printf("%s\n", msg->data);
			continue;
		}

		if (msg->type == 201) { // The end of the history
			printf("The end of the history_query\n");
			return;
		}
	}

	return;
}
