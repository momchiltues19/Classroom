#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd;
	fd = open("output.txt", O_WRONLY);

	dup2(fd, STDOUT_FILENO);
	
	
	if(fd < 0)
	{
		perror("open");
	}
	printf("Hi from output.txt\n");
	close(fd);
}
