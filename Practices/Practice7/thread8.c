#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct thdata {
    int thread_no;
    char message[100];
} stdata;

void *child(void *arg) {
    stdata *data = (stdata *)arg;
    printf("Thread number: %d, Message: %s\n", data->thread_no, data->message);
    pthread_exit(0);
}

int main() {
    pthread_t thread1, thread2;
    pthread_attr_t attr;
    stdata data1, data2;

    pthread_attr_init(&attr);

    data1.thread_no = 1;
    strcpy(data1.message, "I am thread 1");

    data2.thread_no = 2;
    strcpy(data2.message, "I am thread 2");

    pthread_create(&thread1, &attr, child, (void *)&data1);
    pthread_create(&thread2, &attr, child, (void *)&data2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
