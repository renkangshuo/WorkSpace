#include "need.h"

int main() 
{
	open("myfile", O_CREAT, S_IRUSR|S_IXOTH);
	return 0;
}
