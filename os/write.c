#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/syscall.h>

int main()
{
	const char *s = "Hi\n";
	size_t len = strlen (s);
	size_t written = 0;
	ssize_t wresult = 0;

	while(wresult != len)
	{		
		wresult = syscall( SYS_write, STDOUT_FILENO, s + written, len - written);
		if(wresult < 0)
		{
			perror ("write");
			return 1;		
		}
		written += wresult;
	}	
	return 0;
}
