#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int pipefd[2]; //0 - read, 1 - write
	pipe(pipefd);
	char ch;
	pid_t pid = fork();

	if (pid == 0)
	{
		close(pipefd[1]);
		while(read(pipefd[0], &ch, 1) > 0)
			write(STDOUT_FILENO, &ch, 1);
		wait(NULL);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		execlp("ls", "ls", NULL);
	}
}
