
#include <sqlite3.h>


#define R 10
#define L 11
#define Q 12
#define H 13

#define N 64

struct msg1;
typedef struct msg1 MSG;

void do_register(int socketfd, MSG* msg);
int do_login(int socketfd, MSG * msg);
void do_query(int socketfd, MSG * msg);
void do_history(int socketfd, MSG* msg);
void Send(MSG* msg);
void Recv(MSG* msg);


