//Name: Momchil
//Class: 11a
//Number: 19
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

char **parse_cmdline(const char*);

int main()
{
	char buff[1024];
	while(1)
	{
		printf("$ ");
		if(fgets(buff, 1024, stdin) == 0)
		{
			break;
		}
		char **argv = parse_cmdline(buff);
		pid_t pid = fork();
		if(pid == 0)
		{
			execv(argv[0], argv);
		}
		else
		{
			wait(NULL);
			free(argv);
		}
	}
	return 0;
}

char **parse_cmdline(const char *cmdline)
{
	int i, row=0, col=0;
	char **parser = (char **) malloc(sizeof(char *) * 20);
	*(parser + row) = (char *) malloc(sizeof(char) * 1024);
	for(i=0; i<strlen(cmdline); i++)
	{
		if(cmdline[i] != ' ')
		{
			if (cmdline[i] == '\n') i++;
			parser[row][col] = cmdline[i];
			col++;
		}
		else
		{
			row++;
			*(parser + row) = (char *) malloc(sizeof(char) * 1024);
			col = 0;
		}
	}
	return parser;
}
