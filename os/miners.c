//Name: Momchil Todorov
//Class: XIA
//Number: 19
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int gold = 0;
pthread_mutex_t mutex; 

void* mine(void* person)
{
    for(int i = 0; i < 20; i++)
    {
        pthread_mutex_lock(&mutex);
        gold += 10;
        pthread_mutex_unlock(&mutex);
        printf("Miner %d gathered 10 gold\n", (int)person);
        sleep(2);
    }
}

void* trade(void* person)
{
    for(int i = 0; i < 20; i++)
    {
        if(gold == 0)
        {
            printf("The warehouse is empty, cannot sell!\n");
        }
        else 
        {           
            pthread_mutex_lock(&mutex);
            gold -= 10;
            pthread_mutex_unlock(&mutex);
            printf("Trader %d sold 10 gold\n", (int)person);
        }
        sleep(2);
    }
}

int main(int argc, char* argv[])
{
    pthread_mutex_init(&mutex, NULL); 	
    pthread_t threads[100];
    int i = 0;
    int miners = 1, traders = 1;
	//int max_miners = 1, max_traders = 1;
    //if(argc == 3)
    //{
    //    max_miners = atoi(argv[1]);
	//    max_traders = atoi(argv[2]);
    //}

    pthread_create(&threads[0], NULL, mine, (void *)miners);
    pthread_join(threads[0], NULL);
    pthread_create(&threads[1], NULL, trade, (void *)traders);

    pthread_mutex_destroy(&mutex);
    pthread_join(threads[1], NULL);
    printf("Gold: %d\n", gold);
    pthread_exit(NULL);
	
}
