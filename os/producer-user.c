#include <stdio.h>
#include <fcntl.h>              
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{	
	int pipefd[2];
	pipe(pipefd);
	char ch;
	char msg[10];
	pid_t pid = fork();

	if (pid == 0)
	{
		close(pipefd[1]);
		while(1)
		{
			while(read(pipefd[0], &ch, 1) > 0)
			{
				write(STDOUT_FILENO, &ch, 1);
			}
			sleep(200);	
		}
		close(pipefd[0]);	
	}
	else
	{
		while(atoi(msg) != EOF)
		{	
			close(pipefd[0]);
			fgets(msg, 5, stdin);
			if(strcmp(msg, "quit") == 0) break;
			write(pipefd[1], msg, strlen(msg));
		}	
		close(pipefd[1]);
	}
}
