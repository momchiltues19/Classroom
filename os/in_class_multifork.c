#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char * argv[])
{
	int i = 0;
	pid_t pid;

	for (i=0; i<atoi(argv[1]); i++)
		pid = fork();
		if ( pid == 0 )
		{
			execvp(argv[2], argv+2);
			return -1;
		}
	
	for (i=0; i<atoi(argv[1]); i++)
	{
		wait(NULL);	
	}
}
