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

int minerals_in_block[1000];
int game_minerals = 0;
int soldiers = 0;
int block_count = 2;
pthread_mutex_t block_mutex[1000];
pthread_mutex_t minerals_mutex;
pthread_mutex_t block_count_mutex;

void* mine(void* person)
{
    int block_count_local;
    pthread_mutex_lock(&block_count_mutex);
    block_count_local = block_count;
    pthread_mutex_unlock(&block_count_mutex);

    bool usable_blocks[1000];
    bool flag = true;
    int i;
    int number = (int) person;

    for(i = 0; i < block_count_local; i++)
    {
        usable_blocks[i] = true;
    }
    //printf("worker %d was created\n", number);
    while(flag)
    {
        for(i = 0; i < block_count_local; i++)
        {
            flag = false;
            if(usable_blocks[i] == true)
            {
                flag = true;
                break;
            }
        }
        for(i = 0; i < block_count_local; i++)
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

int main(int argc, char* argv[])
{

    int i;
    int workers = 5;
    int block_count_local = 2;
    if(argc == 2)
    {
        pthread_mutex_lock(&block_count_mutex);
        block_count = atoi(argv[1]);
        block_count_local = block_count;
        pthread_mutex_unlock(&block_count_mutex);
    }

    pthread_t *threads = malloc(sizeof(pthread_t)*workers);

    for(i = 0; i < block_count_local; i++)
    {
        pthread_mutex_init(&block_mutex[i], NULL);
    }

    for(i = 0; i < block_count_local; i++)
    {
        minerals_in_block[i] = 500;
    }

    for(i = 0; i < workers; i++)
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

    for(i = 0; i < block_count_local; i++)
    {
        pthread_mutex_destroy(&block_mutex[i]);
    }

    printf("Map minerals 1000, player minerals %d, SCVs %d, Marines %d\n", game_minerals, workers, soldiers);

    // for(i = 0; i < 5; i++)
    // {
    //     pthread_join(*(threads+i), NULL);
    // }

    exit(0); //or exit(0);
}
