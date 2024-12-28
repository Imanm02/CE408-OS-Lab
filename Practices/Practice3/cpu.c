#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("/proc/cpuinfo", "r");
    if (!file) {
        return 1;
    }

    char line[256];
    char model[256] = "";
    char mhz[256] = "";
    char cache_size[256] = "";

    while (fgets(line, sizeof(line), file)) {

        if (strncmp(line, "model name", 10) == 0) {
            strcpy(model, strchr(line, ':') + 2);
        }
        else if (strncmp(line, "cpu MHz", 7) == 0) {
            strcpy(mhz, strchr(line, ':') + 2);
        }
        else if (strncmp(line, "cache size", 10) == 0) {
            strcpy(cache_size, strchr(line, ':') + 2);
        }
    }

    printf("model: %s", model);
    printf("frequency: %s MHz", mhz);
    printf("cache size: %s", cache_size);

    fclose(file);
    return 0;
}
