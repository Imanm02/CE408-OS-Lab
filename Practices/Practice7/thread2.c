#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void *child(void *arg) {
    printf("Hello from child thread! PID: %d\n", getpid());
 }


int main() {
    pthread_t thread;
    printf("Hello from main thread! PID: %d\n", getpid());
    pthread_create(&thread, NULL, child, NULL);
    pthread_join(thread, NULL);
    return 0;
}
