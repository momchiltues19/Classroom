#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
	ssize_t wresult = 0;
	ssize_t rresult = 0;	
	char buff[100];

	int fd = open(argv[1], O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}
	
	while((rresult = read(fd, buff, 100)) != 0)
	{
		wresult = 0;
		while(wresult != rresult)
		{	
			ssize_t res;		
			res = write(STDOUT_FILENO, buff + wresult, rresult - wresult);
			if (res < 0)
			{
				return -1;
			}
			wresult += res;		
		}	
	}	
	
	if (close(fd) < 0)
	{
		perror("close");
		return -1;
	}
	return 0;
}
