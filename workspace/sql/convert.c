#include <stdio.h>
#include <sqlite3.h>

#define ONE 1
#define TWO 2

int main(int argc, const char *argv[])
{
	FILE* fp;
	fp = fopen("./dict.txt", "r");




	sqlite3 *fd;
	sqlite3_open("./data.db", &fd);
	printf("Hello World\n");
	char sl[512];
	char *p;
	char s1[24];
	char s2[256];
	char insert[256];
	int i = 0;
	int j = 0;
	int num = 0;

	int ret;
	int state = ONE;
	char *serror = 0;

	while (fgets(sl, 512, fp) != NULL) {
		//if (num > 10)
		//	break;
		p = sl;
		i = 0;
		j = 0;
		while (*p != ' ') {
			s1[i] = *p;
			i++;
			p++;
		}
		s1[i] = '\0';
		while (*p == ' ') {
			p++;
		}
		p--;

		while (*p != '\n') {
			s2[j] = *p;
			j++;
			p++;
		}
		s2[j] = '\0';

		//printf("s1 %s s2 %s\n", s1, s2);
		//printf("sl %s\n", sl);
#if 1
		sprintf(insert, "insert into word values(%d, '%s', '%s');", num, s1, s2);
		ret = sqlite3_exec(fd, insert, NULL, NULL, &serror);
		if (ret != SQLITE_OK) {
			printf("error: fail to %s\n", serror);
			serror = NULL;
		}
#endif
		num++;
		

	}



	fclose(fp);
	sqlite3_close(fd);
	return 0;
}
