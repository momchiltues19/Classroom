#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int pipefd[2];
	pid_t cpid;
	char buff;
	
	if(pipe(pipefd) == -1)
	{
		perror("pipe");
		return -1;		
	}
	
	cpid = fork();
	if(cpid == -1)
	{
		perror("fork");
		return -1;
	}

	if(cpid == 0)
	{
		close(pipefd[1]);

		while(read(pipefd[0], &buff, 1) > 0)
			write(STDOUT_FILENO, &buff, 1);
		write(STDOUT_FILENO, "\n", 1);
		printf("%d, %d\n", pipefd[0], pipefd[1]);
		close(pipefd[0]);
		return 0;
	}
	else
	{
		close(pipefd[0]);
		char* str = "hyperspace";
		write(pipefd[1], str, strlen(str)); //WRITES IN PIPEFD[1], not in terminal
		close(pipefd[1]);		
		wait(NULL);
		return 0;
	}
}
