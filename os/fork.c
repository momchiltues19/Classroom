#include <unistd.h>
#include <stdio.h>

int main()
{
	//fork() - creates new process, which is a exact copy of the parent one
	//printf("1\n");
	pid_t pid = fork();
	if (pid < 0)
	{
		perror("fork");
	}	
	else if (pid == 0)
	{
		//sleep(10);
		printf("sos child %d\n", pid);
		sleep(1);
		execlp("ls","ls",NULL);
	}	
	else 
	{	
		printf("sos parent %d\n", pid); //making it sleep makes it a zombie (process)
		wait(NULL);
	}
	return 0;
}
