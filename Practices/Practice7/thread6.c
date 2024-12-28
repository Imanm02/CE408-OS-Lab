#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int global_var = 0;

void *child(void *arg) {
    int local_var;

    printf("Thread %ld, pid %d, addresses: &global: %p, &local: %p \n",
        pthread_self(), getpid(), &global_var, &local_var);

    global_var++;

    printf("Thread %ld, pid %d, incremented global var=%d\n",
        pthread_self(), getpid(), global_var);

    pthread_exit(0);
}

int main() {
    pthread_t thread1, thread2;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    global_var = 10;
    printf("Main thread before: global_var = %d\n", global_var);

    pthread_create(&thread1, &attr, child, NULL);
    pthread_create(&thread2, &attr, child, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main thread after: global_var = %d\n", global_var);

    return 0;
}

