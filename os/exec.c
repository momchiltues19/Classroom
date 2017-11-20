#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid = fork();
	if(pid == 0)
	{
		execlp("ls", "ls", NULL);
	    printf("hi"); //<- this will not be printed without forking
	}
	else 
	{
		//printf("doki"); 		
		//wait(NULL);
	}
}
