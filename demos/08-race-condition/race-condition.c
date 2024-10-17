#include <stdio.h>
#include <pthread.h>

int shared_counter = 0;

void* increment(void* arg) {
    for (int i = 0; i < 100000; i++) {
        shared_counter++;  // Race condition here
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, increment, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final Counter Value: %d\n", shared_counter);
    return 0;
}
