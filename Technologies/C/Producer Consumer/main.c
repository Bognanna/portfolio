/*  Bogna Kilanowska 148252
    Group SI1
    The producer-consumer problem revisited*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define SHARED 0
#define N 10 // size of the buffer
#define PRO 3 //number of producers
#define CON 2 //number of consumers

#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void* producer();
void* consumer();
sem_t sm_free, sm_taken, full, empty;

int free_id[N]; //list of indices of free positions
int buffer[N]; //buffer with N slots
int taken_id[N]; //list of indices of taken positions

int add_free = 0; //addition index
int rem_free = 0; //remove index
int add_taken = 0; //addition index
int rem_taken = 0; //remove index

int licz = 1; //number of produced products

int times_p[PRO] = { 2, 3, 15}; //speeds of praticular producers
int times_c[CON] = { 3, 5}; //speeds of particular consumers

int taken_slots = 0;

void* producer(void* id_p){
    int id;
    int* id_pro = id_p;

    while(1){ 
        
        sem_wait(&empty);

            sem_wait(&sm_free);
                id = free_id[rem_free%N];
                rem_free += 1;
            sem_post(&sm_free);

            sleep(times_p[*id_pro - 1]);
            buffer[id] = licz;
            taken_slots += 1;

            sem_wait(&sm_taken);
                taken_id[add_taken%N] = id;
                add_taken += 1;
            sem_post(&sm_taken);

            printf(ANSI_COLOR_MAGENTA "Producer: %d\tItem: %d\tTaken slots: %d\n" ANSI_COLOR_MAGENTA, *id_pro, licz, taken_slots);
            licz += 1;

        sem_post(&full);
    }
}

void* consumer(void* id_c){
    int id;
    int product;
    int* id_con = id_c;

    while(1){ 
        
        sem_wait(&full);

            sem_wait(&sm_taken);
                id = taken_id[rem_taken%N];
                rem_taken += 1;
            sem_post(&sm_taken);

            sleep(times_c[*id_con - 1]);
            product = buffer[id];
            buffer[id] = 0;
            taken_slots -= 1;

            sem_wait(&sm_free);
                free_id[add_free%N] = id;
                add_free += 1;
            sem_post(&sm_free);

            printf(ANSI_COLOR_CYAN "Consumer: %d\tItem: %d\tTaken slots: %d\n" ANSI_COLOR_CYAN, *id_con, product, taken_slots);

        sem_post(&empty);
    }
}

int main() {
    pthread_t p[PRO];
    pthread_t c[CON];

    for(int i = 0; i < N; ++i){
        free_id[i] = i;
        taken_id[i] = -1;
    }

    //producers and consumers indices
    int tab_p[PRO], tab_c[CON];
    int* arg_p[PRO];
    int* arg_c[CON];
    for(int i = 0; i < PRO; ++i){
        tab_p[i] = i+1;
        arg_p[i] = &tab_p[i];
    }
    for(int i = 0; i < CON; ++i){
        tab_c[i] = i+1;
        arg_c[i] = &tab_c[i];
    }

    //semaphores initialization
    sem_init(&empty, SHARED, N);
    sem_init(&full, SHARED, 0);
    sem_init(&sm_free, SHARED, 1);
    sem_init(&sm_taken, SHARED, 1);

    //creating producers and consumers threads
    for(int i = 0; i < PRO; ++i)
        pthread_create(&p[i], NULL, &producer, arg_p[i]);

    for(int i = 0; i < CON; ++i)
        pthread_create(&c[i], NULL, &consumer, arg_c[i]);


    //joining producers and consumers threads
    for (int i = 0; i < PRO + CON; ++i){
        if(i < PRO)
            pthread_join(p[i], NULL);
        else
            pthread_join(c[i - PRO], NULL);
    }

    return 0;
}
