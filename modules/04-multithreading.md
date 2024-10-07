---
lab:
    title: 'Multithreading - Mutex, Semaphores, and Condition Variables'
---
# Module 04: Multithreading and Synchronization

## Overview

In this module, you will explore multithreading concepts, focusing on race conditions and synchronization mechanisms like mutexes and semaphores. The exercises will help you understand the problems caused by unsynchronized threads and provide techniques to solve these issues using various thread synchronization primitives.

### Exercise Instructions
1. Observe race condition and implement mutex to solve it.
2. Use semaphores to control access.

### Race Conditions and Mutexes
In this exercise, you will observe a race condition in a sample code and then solve the issue by implementing a mutex.

**Step 1: Observe Race Conditions**

When two or more threads access shared data simultaneously without proper synchronization, a race condition can occur. Run the following code and observe inconsistent results due to the race condition.

**Sample Code:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_ITERATIONS 1000000

int counter = 0; // Shared resource (global variable)

void* incrementCounter(void* arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        counter++; // Race condition occurs here
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, incrementCounter, NULL);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final Counter Value: %d\n", counter); // The result will be inconsistent

    return 0;
}
```

**Step 2: Implement Mutex to Solve the Race Condition**
Now, implement a mutex to ensure that the increment operation on the shared resource (counter) is protected and executed atomically by only one thread at a time.
Observe how the race condition is resolved, and the final value of the counter remains consistent.

**Example Code (Race Condition Fixed with Mutex)**
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_ITERATIONS 1000000

int counter = 0; // Shared resource (global variable)
pthread_mutex_t mutex; // Mutex declaration

void* incrementCounter(void* arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        // Lock the mutex before modifying the counter
        counter++;
        // Unlock the mutex after modification
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Initialize the mutex

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
    }

    printf("Final Counter Value: %d\n", counter); // The result will now be consistent

    // Destroy the mutex

    return 0;
}
```

### Semaphores in Action
In this exercise, you will use semaphores to control access to a shared resource among multiple threads.
A semaphore is a signaling mechanism that limits the number of threads that can access a shared resource at any time. In this case, learners will observe a fixed number of threads allowed to access a resource simultaneously.
Run the example code below and observe how only 3 threads are allowed to access the shared resource at any given time.
Modify the semaphore's initial value and observe how it changes the number of threads accessing the resource simultaneously.

**Example code:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 10

sem_t semaphore; // Semaphore declaration

void* accessSharedResource(void* arg) {
    int thread_id = *((int*)arg);

    printf("Thread %d is waiting to access the shared resource...\n", thread_id);

    // Wait on the semaphore (decrements the semaphore value)
    sem_wait(&semaphore);

    // Critical section (accessing the shared resource)
    printf("Thread %d is accessing the shared resource.\n", thread_id);
    sleep(1); // Simulate work being done on the shared resource

    // Signal on the semaphore (increments the semaphore value)
    sem_post(&semaphore);

    printf("Thread %d is done accessing the shared resource.\n", thread_id);
    
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize the semaphore with an initial value of 3 (allowing 3 threads to access the resource at a time)
    sem_init(&semaphore, 0, 3);

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, accessSharedResource, &thread_ids[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}
```

**Next Steps:**
1. Experiment with different thread counts and semaphore values to observe the impact on thread synchronization.
2. Explore condition variables and more complex synchronization scenarios.

Stay curious and keep experimenting!
