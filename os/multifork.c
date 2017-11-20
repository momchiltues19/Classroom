#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	pid_t pid = fork();
	if(pid == 0)
	{
		execlp(argv[2], argv[2], NULL);
	}
	else 
	{
		execlp(argv[2], argv[2], NULL);
	}
} 
