#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *child(void *arg) {
    puts("Hello from child thread!");
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, child, NULL);
    sleep(1);
    return 0;
}
