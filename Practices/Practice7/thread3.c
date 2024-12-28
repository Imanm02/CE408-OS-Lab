#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int oslab = 0;

void *child(void *arg) {
    printf("Hello from child thread! PID: %d\n", getpid());
    oslab = 10;
    printf("Child thread: oslab = %d\n", oslab);
}

int main() {
    pthread_t thread;
    printf("Hello from main thread! PID: %d\n", getpid());
    printf("Main thread before: oslab = %d\n", oslab);
    pthread_create(&thread, NULL, child, NULL);
    pthread_join(thread, NULL);
    printf("Main thread after: oslab = %d\n", oslab);
    return 0;
}
