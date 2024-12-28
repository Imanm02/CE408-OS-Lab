#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *versionFile = fopen("/proc/version", "r");
    FILE *outputFile = fopen("Linux Version.txt", "w");

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), versionFile) != NULL) {
        fputs(buffer, outputFile);
    }

    fclose(versionFile);
    fclose(outputFile);
    printf("Successfully copied version into `Linux Version.txt`\n");
    return 0;
}
