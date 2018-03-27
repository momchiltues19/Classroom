//Name: Momchil Todorov
//Class: XIA
//Number: 19
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex[5];

void* buyer(void* person)
{
	int i;
	for(i = 0; i < 5; i++)
	{
		if(!pthread_mutex_trylock(&mutex[i]))
		{
			printf("Buyer %d takes car %d.\n", person, i);
			sleep(5);
			printf("Buyer %d returns car %d.\n", person, i);
			pthread_mutex_unlock(&mutex[i]);	
			break;
		}
	}
	pthread_exit(0);
}

int main()
{
	int i;
	for(i = 0; i < 5; i++)
	{
		pthread_mutex_init(&mutex[i], NULL);
	}

	pthread_t threads[20];
	for(i = 0; i < 20; i++)
	{
		pthread_create(&threads[i], NULL, buyer, (void *)(i+1));
		sleep(1);	
	}	

	for(i = 0; i < 20; i++)
	{
		pthread_join(&threads[i], NULL);
	}

	for(i = 0; i < 5; i++)
	{
		pthread_mutex_destroy(&mutex[i]);
	}
	pthread_exit(0);
}
