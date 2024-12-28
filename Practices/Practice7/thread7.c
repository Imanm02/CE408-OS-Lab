#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
    int local_main = 20;

    printf("Main thread before: global_var = %d, local_main = %d\n", global_var, local_main);

    pthread_create(&thread1, &attr, child, NULL);
    pthread_create(&thread2, &attr, child, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main thread after threads: global_var = %d, local_main = %d\n", global_var, local_main);

    pid_t pid = fork();

    if (pid == 0) {
        global_var = 30;
        local_main = 40;
        printf("Child process: global_var = %d, local_main = %d\n", global_var, local_main);
    } else {
        wait(NULL);
        printf("Parent process: global_var = %d, local_main = %d\n", global_var, local_main);
    }

    return 0;
}
