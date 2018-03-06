//Name: Momchil Todorov
//Class: XIA
//Number: 19
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int gold = 0;

void* mine(void* person)
{

}

void* trade(void* person)
{

}

int main(int argc, char* argv[])
{
	//pthread_mutex_init(&mutex, NULL); 	
	pthread_t threads[100];
	int i = 0;
	int miners = atoi(argv[1]);
	int traders = atoi(argv[2]);
	do
	{	
		if(command[0] == 'p')
		{
			pthread_create(&threads[i], NULL, , (void *)N);
			i++;
		}			
	}while(1);
	//pthread_mutex_destroy();
	pthread_exit(NULL);
	
}
