#include <stdlib.h> /* required for rand() */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
#include "buffer.h"

void *producer (void *param);
void *consumer (void *param);
void *print_params(int sleep_time, int producers, int consumers);

buffer_item buffer[BUFFER_SIZE];
int head;
int tail;

// declare mutex lock and semaphores
pthread_mutex_t mutex;

sem_t full;
sem_t empty;


int main(int argc, char *argv[]) {
    
    /* get command line arguements */
    // make sure the user put in the correct amount of arguments
    if (argc != 4) {
        puts("You need to have three arguments. Run the command like this");
        puts("./<name> <sleep time> <# producer threads> <#consumer threads>");
        return(1);
    }

    
    int sleep_time =  atoi(argv[1]);
    int producer_threads = atoi(argv[2]);
    int consumer_threads = atoi(argv[3]);

    // start threads

    pthread_t consumer_t;
    pthread_t producer_t;

    // initialize buffer
    head = 0;
    tail = 0;
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BUFFER_SIZE);   // init to BUFFER_SIZE because there by default all slots are available (empty)
    sem_init(&full, 0, 0);   // init to 0 because none of the slots are available (all of them are empty)

    print_params(sleep_time, producer_threads, consumer_threads);


    for (int i = 0; i < producer_threads; i++) {
        pthread_create(&producer_t, NULL, producer, NULL);
    }

    for (int i = 0; i < consumer_threads; i++) {
        pthread_create(&consumer_t, NULL, consumer, NULL);
    }
    sleep(sleep_time);
    puts("========================================");
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return(0);
}
void *print_params(int sleep_time, int producers, int consumers) {

    puts("========================================");
    printf("Run main for %d seconds\n", sleep_time);
    printf("producer threads: %d\n", producers);
    printf("consumer threads: %d\n", consumers);
    puts("========================================\n");

}