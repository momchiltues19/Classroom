//Name: Momchil Todorov
//Class: XIA
//Number: 19
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <ncurses.h>
#include <stdbool.h>

int minerals_in_block[2] = {500, 500};
int game_minerals = 0;
int soldiers = 0;
pthread_mutex_t block_mutex[2];
pthread_mutex_t minerals_mutex;

void* mine(void* person)
{
    bool usable_blocks[2] = {true, true};
    int i;
    int number = (int) person;
    //printf("worker %d was created\n", number);
    while(usable_blocks[0] || usable_blocks[1])
    {
        for(i = 0; i < 2; i++)
        {
            sleep(3);
            if(minerals_in_block[i] == 0 && usable_blocks[i]) usable_blocks[i] = false;
            if(!pthread_mutex_trylock(&block_mutex[i]) && usable_blocks[i])
            {
                printf("SCV %d is mining from mineral block %d\n", number, i+1, minerals_in_block[i]);
                pthread_mutex_lock(&minerals_mutex);
                if(minerals_in_block[i] <= 8)
                {
                    game_minerals += minerals_in_block[i];
                    minerals_in_block[i] = 0;
                    usable_blocks[i] = false;
                }
                else
                {
                    minerals_in_block[i] -= 8;
                    game_minerals += 8;
                }
                pthread_mutex_unlock(&minerals_mutex);
                printf("SCV %d is transporting minerals\n", number);
                sleep(2); //might need something more to be added
                printf("SCV %d delivered minerals to the Command center\n", number);
                pthread_mutex_unlock(&block_mutex[i]);    
                //break;
            }
        }
    }
}

int main()
{

    int i;
    int workers = 5;
    for(i = 0; i < 2; i++)
    {
        pthread_mutex_init(&block_mutex[i], NULL);
    }

    pthread_t *threads = malloc(sizeof(pthread_t)*workers);

    for(i = 0; i < 5; i++)
    {
        pthread_create(threads + i, NULL, mine, (void*) i);
        //sleep(1);   
    }   

    char command;
    while(1)
    {
        command = getchar();
        switch(command)
        {
        	case 'm':
        		pthread_mutex_lock(&minerals_mutex);
                if(game_minerals >= 50)
                {
                    printf("You wanna piece of me, boy?\n");
                    sleep(1);
                    game_minerals -= 50;
                    soldiers ++;
                }
                else
                {
                    printf("Not enough minerals.\n");
                }
                pthread_mutex_unlock(&minerals_mutex);
                break;
            case 's':
                break;

        }
        if(soldiers == 20) break;
    }

    for(i = 0; i < 2; i++)
    {
        pthread_mutex_destroy(&block_mutex[i]);
    }

    printf("Map minerals 1000, player minerals %d, SCVs %d, Marines %d\n", game_minerals, workers, soldiers);

    // for(i = 0; i < 5; i++)
    // {
    //     pthread_join(*(threads+i), NULL);
    // }

    pthread_exit(0);
}
