#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *child(void *arg) {
    long long int n = *(long long int *)arg;
    long long int sum = 0;
    for (long long int i = 2; i <= n; i++) {
        sum += i;
    }
    printf("the sum is: %lld\n", sum);
}

int main() {
    pthread_t thread;
    pthread_attr_t attr;
    long long int n;

    printf("Enter n: ");
    scanf("%lld", &n);

    pthread_attr_init(&attr);
    pthread_create(&thread, &attr, child, &n);
    pthread_join(thread, NULL);

    return 0;
}
