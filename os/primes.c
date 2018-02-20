//Name: Momchil Todorov
//Class: XIA
//Number: 19
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int is_prime(int number)
{	
	int i;	
	for(i=2; i<number;i++)
	{
		if(number%i==0)return 0;
	}
	return 1;
}

void *primes(void *num)
{
	int prime_count = 0, N, i;
	N = (int)num;
	printf("Prime calculation started for N=%d\n", N);
	for(i=2; i<N; i++)
	{
		if(is_prime(i))prime_count++;
	}
	printf("Number of primes for N=%d is %d\n", N, prime_count);
}


int main()
{
	pthread_t threads[100];
	char *command;
	size_t size = 100;
	command = (char *)malloc(size * sizeof(char));
	int i = 0;
	do
	{		
		getline(&command,&size,stdin);
		int N = atoi(command+2);
		if(command[0] == 'p')
		{
			pthread_create(&threads[i], NULL, primes, (void *)N);
			i++;
		}		
		else if(command[0] == 'e')
		{
			break;
		}		
		else
		{	
			printf("Supported commands:\np N - Starts a new calculation for the number of primes from 1 to N\ne - Waits for all calculations to finish and exits\n");
		}
	}while(1);
	pthread_exit(NULL);
	
}
