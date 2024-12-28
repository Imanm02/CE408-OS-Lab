#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[1024];

    fp = fopen("/proc/interrupts", "r");
    if (fp == NULL) {
        perror("Error in opening /proc/interrupts");
        return EXIT_FAILURE;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}