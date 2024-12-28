#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("/proc/meminfo", "r");
    if (!file) {
        return 1;
    }

    char line[256];
    unsigned long mem_total = 0, mem_free = 0, buffers = 0, cached = 0;

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "MemTotal: %lu kB", &mem_total);
        sscanf(line, "MemFree: %lu kB", &mem_free);
        sscanf(line, "Buffers: %lu kB", &buffers);
        sscanf(line, "Cached: %lu kB", &cached);
    }
    fclose(file);

    unsigned long mem_used = mem_total - mem_free - buffers - cached;

    printf("Total Memory: %lu kB\n", mem_total);
    printf("Used Memory: %lu kB\n", mem_used);
    printf("Free Memory: %lu kB\n", mem_free);

    return 0;
}
