#include <semaphore.h>
#include <pthread.h>

// declare mutex lock and semaphores
extern pthread_mutex_t mutex;

extern sem_t full;
extern sem_t empty;

int insert_item (int item);
int remove_item (int *item);