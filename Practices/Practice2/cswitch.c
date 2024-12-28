#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == 0) {
        printf("Voluntary context switches %ld\n", usage.ru_nvcsw);
        printf("Involuntary context switches %ld\n", usage.ru_nivcsw);
    } else
        return 1;
    return 0;
}

