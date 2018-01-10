//Name: Momchil Todorov
//Class: 11a
//Number: 19 
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#define FIRST_OPEN -1

int count_lines(char *argv, int lines);
void standart_input();

int main(int argc, char *argv[])
{
	int lines = 0;
	int ten_lines = 0;
	int count_files = 1;
	char name_output[100] = {'=','=','>',' ','\0'};
	if (argc == 1) standart_input();	
	else 
	{
		while(argc - count_files > 0)	
		{		
			if(argv[count_files] == "-")
			{
				write(STDOUT_FILENO, "==> standard input <==\n", 22);
				standart_input();
			}			
			else if(argc != 2)
			{
				strcat(strcat(name_output,argv[count_files]), " <==\n");
				write(STDOUT_FILENO, name_output, strlen(name_output));
				strcpy(name_output, "\n==> \0");
			}			
			lines = count_lines(argv[count_files], FIRST_OPEN);
			ten_lines = count_lines(argv[count_files], lines);
			count_files++;	
		}	
	}	make
	return 0;
}

//used to open the file twice, once to count the lines and a second time to output the last 10 lines
int count_lines(char *argv, int lines)
{
	char buff[1];	
	int fd = open(argv, O_RDONLY);
	int count = 0;
	while(read(fd, buff, 1))
	{
		if(lines != FIRST_OPEN && count >= lines-10)write(STDOUT_FILENO, buff, 1);
		if(*buff == '\n') count++;	
	}
	close(fd);
	return count;
}

void standart_input()
{
	char *buff, help[1000];
	int line_count = 0, symbol_count = 0, capacity = 10, i = 0, lines = 0, j = 0;
	buff = malloc(sizeof(char)*capacity);
	while(read(STDIN_FILENO, buff + symbol_count, 1))
	{
		if(symbol_count == capacity)
		{
			capacity *= 2;
			buff = realloc(buff, sizeof(char)*capacity);
		}
		if(*buff == '\n')line_count++;	
		symbol_count++;
	}
	for(i=symbol_count, j=0; i>0; i--, j++)
	{
		help[j] = buff[i];	
		if(buff[i] == '\n') lines++;
		if(lines == 10) break;
	}
	write(STDOUT_FILENO, help, j);
	free(buff);
}
