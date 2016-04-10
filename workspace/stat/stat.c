#include <grp.h>
#include <time.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printinfo(const char*);
void printdir(const char *);

int main(int argc, const char *argv[])
{

	if (argc < 2) {
		printf("Usage: %s <filename> \n", argv[0]);
		return -1;
	}

	printdir(argv[1]);

	return 0;
}

void printdir(const char *dir)
{
	DIR* dp;
	struct dirent* entry;

	if ((dp = opendir(dir)) == NULL) {
		fprintf(stderr, "cannot open directory: %s\n", dir);
		return;
	}
	chdir(dir);
	while((entry = readdir(dp)) != NULL) {
		printinfo(entry->d_name);		
	}
	chdir("..");
	closedir(dp);
}

void printinfo(const char* filename) 
{
	struct stat statbuf;
	char time[100];
	char *ptime;
	struct passwd* up;
	struct group* gp;


	lstat(filename, &statbuf);
	
	up = getpwuid( statbuf.st_uid);
	gp = getgrgid( statbuf.st_gid);

	ptime = ctime(&statbuf.st_mtime);	
	strcpy(time, ptime);
	time[strlen(time)-1] = '\0';


	switch (statbuf.st_mode & S_IFMT) {
	case S_IFDIR: printf("d"); 			break;
	case S_IFREG: printf("-"); 			break;
	default: printf("unknown?\n"); return;
	}

	switch (statbuf.st_mode & S_IRWXU) {
	case S_IRUSR | S_IWUSR: printf("rw-"); break;
	case S_IRUSR | S_IWUSR | S_IXUSR: printf("rwx");break;
	default: return;// printf("error:\n"); return;
	}

	switch (statbuf.st_mode & S_IRWXG) {
	case S_IRGRP | S_IWGRP: printf("rw-"); break;
	case S_IRGRP | S_IWGRP | S_IXGRP: printf("rwx");break;
	default: return; //rintf("error:\n"); return;
	}

	switch (statbuf.st_mode & S_IRWXO) {
	case S_IROTH | S_IWOTH: printf("rw-"); break;
	case S_IROTH | S_IWOTH | S_IXOTH: printf("rwx");break;
	case S_IROTH : printf("r--"); break;
	default: return;//printf("error:\n"); return;
	}

	printf("\t%u", statbuf.st_nlink);
	printf("\t%s ", up->pw_name);
	printf("\t%s ", gp->gr_name);

	printf("\t%lu ", statbuf.st_size);

	printf("\t%s ", time);

	printf("\t%s \n", filename);


}
