#include <stdio.h>
#include <fcntl.h>              
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int pipefd[2];
	pipe(pipefd);

	pid_t pid = fork();

	if(pid == 0)
	{
		close(pipefd[0]);
		write(pipefd[1], "b", 1);
		printf("write\n");	
	}
	else
	{
		char ch;
		close(pipefd[1]);
		read(pipefd[0], &ch, 1);
		printf("read\n");	
	}
}
