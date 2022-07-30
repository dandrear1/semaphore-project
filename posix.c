#include <stdlib.h> /* required for rand() */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "buffer.h"
#include "semutils.h"

void *producer(void *param) {
    buffer_item item;

    while (1) {
        // sleep for a random period of time
        sleep(1);
        
        // generate a random number
        item = rand();
        sem_wait(&empty);    // wait for there to be an opening to but in items
        pthread_mutex_lock(&mutex); // aquire a lock

        // put in the item
        if (insert_item(item))
            printf("Error state producer\n");
        else
            printf("producer produced %d\n", item);
        

        pthread_mutex_unlock(&mutex);
        sem_post(&full);    // signal that that there is an item added to the buffer
    }
}

void *consumer(void *param) {
    buffer_item item;

    while (1) {
        // sleep for a random period of time
        sleep(1);
        sem_wait(&full);    // wait for there to be enough items to be taked
        pthread_mutex_lock(&mutex); // aquire a lock

        if (remove_item(&item))
            printf("Error State consumer\n");
        else
            printf("consumer consumed %d\n", item);

        
        pthread_mutex_unlock(&mutex);   // release lock
        sem_post(&empty);   // signal that there an opening to put in items
    }
}