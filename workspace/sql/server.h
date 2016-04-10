
#include <sqlite3.h>

#define N 64
#define R 10
#define L 11
#define Q 12
#define H 13
struct msg1;
typedef struct msg1 MSG;

void do_register(int connfd, MSG* msg, sqlite3* usrdb);
void do_login(int connfd, MSG* msg, sqlite3* usrdb);
void do_history(int connfd, MSG* msg, sqlite3* recorddb);
void do_query(int connfd, MSG* msg, sqlite3* worddb);
void Send(MSG* msg);
void Recv(MSG* msg);
void do_client(int connfd);

