#include <unistd.h>
#include <string.h>

int main()
{
	int pipefd[2]; //0 - read, 1 - write
	pipe(pipefd);
	char ch;
	char *msg = "HII?!\n";
	pid_t pid = fork();

	if (pid == 0)
	{
		close(pipefd[1]);
		while(read(pipefd[0], &ch, 1) > 0)
			write(STDOUT_FILENO, &ch, 1);
	}
	else
	{
		close(pipefd[0]);
		write(pipefd[1], msg, strlen(msg));
	}
}
