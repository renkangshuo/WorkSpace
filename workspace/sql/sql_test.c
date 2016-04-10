#include <stdio.h>
#include <sqlite3.h>

int callback(void *notused, int num, char** s1, char** scol)
{
	static int k = 0;
	int i;
	for (i = 0; i < num; i++)
	{
		printf("%s = %s\n", scol[i], s1[i]);
	}
	k++;
	printf("%d j\n", k);

	

	return 0;
}

int main(int argc, const char *argv[])
{
	sqlite3 *fd;
	sqlite3_open("./1.db", &fd);
	printf("Hello World\n");
	char sc[128];

	int ret;
	char *serror = 0;
	char *s = "create table stu(id int , name char[20], Chinese int, English int, math int)";

	ret = sqlite3_exec(fd, s, NULL, NULL, &serror);
	if (ret != SQLITE_OK){
		printf("error: fail to %s\n", serror);
		serror = NULL;
	}
	for (int i = 0; i < 10; i++) {
		sprintf(sc, "insert into stu values(%d, 'somebody%d', %d, %d, %d)", i, i,  60+i, 70+i, 80+i);

		//s = "insert into stu values(1, 'somebody', 60, 70, 80)";

		ret = sqlite3_exec(fd, sc, NULL, NULL, &serror);
		if (ret != SQLITE_OK) {
			printf("error: fail to %s\n", serror);
			serror = NULL;
		}
	}
	/*s = "insert into stu values(2, 'somebody2', 60, 70, 80)";

	ret = sqlite3_exec(fd, s, NULL, NULL, &serror);
	if (ret != SQLITE_OK) {
		printf("error: fail to %s\n", serror);
		serror = NULL;
	} */

	s = "select * from stu";

	ret = sqlite3_exec(fd, s, callback, NULL, &serror);

	if (ret != SQLITE_OK) 
	{
		printf("error: fail to %s\n", serror);
		serror = NULL;
	}

	sqlite3_close(fd);
	return 0;
}