#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        printf("Total RAM: %lu\n", info.totalram);
        printf("Free RAM: %lu\n", info.freeram);
    } else
        return 1;

    return 0;
}
