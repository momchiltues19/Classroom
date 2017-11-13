#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	int fd = open("", O_WRONLY);
	char* s = "sth";
	write(fd, s, strlen(s));
	return 0;
}//it works with 2 files in 2 terminals   

/*  int main(
	{
		int fd = open("",O_REONLY);
		char* c = ;

???? */
