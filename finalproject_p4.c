#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
int count = 1;

void* threadA(void* arg) {
    while (count <= 7) {
        pthread_mutex_lock(&mutex);
        if (count % 2 != 0) {
            printf("Thread A: %d\n", count);
            count++;
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void* threadB(void* arg) {
    while (count <= 14) {
        pthread_mutex_lock(&mutex);
        if (count % 2 == 0) {
            printf("Thread B: %d\n", count);
            count++;
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t tidA, tidB;
    pthread_mutex_init(&mutex, NULL);
    
    pthread_create(&tidA, NULL, threadA, NULL);
    pthread_create(&tidB, NULL, threadB, NULL);
    
    pthread_join(tidA, NULL);
    pthread_join(tidB, NULL);
    
    pthread_mutex_destroy(&mutex);
    
    return 0;
}