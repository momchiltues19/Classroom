#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	const char *s = "Hi\n";
	size_t len = strlen (s);
	size_t written = 0;
	ssize_t wresult = 0;

	while(wresult != len)
	{	
		ssize_t res;		
		res = write(STDOUT_FILENO, s + wresult, len - wresult);
		if (res < 0)
		{
			return -1;
		}
		wresult = res;
	}	
	return 0;
}
