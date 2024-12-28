#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    pid_t pid = atoi(argv[1]);
    char path[40];
    
    snprintf(path, 40, "/proc/%d/status", pid);
    FILE * file = fopen(path, "r");
    if (!file) {
	return -1;
    }

    char line[100];

    while (fgets(line, 100, file)) {
        if (strncmp(line, "Name:", 5) == 0) {
            printf("Name: %s", line + 6);
        }
        if (strncmp(line, "VmSize:", 7) == 0) {
            printf("Memory: %s", line + 8);
        }
    }
    fclose(file);

    snprintf(path, 40, "/proc/%d/cmdline", pid);
    file = fopen(path, "r");
    if (!file) {
        return 1;
    }

    if (fgets(line, 100, file)) {
        printf("Cmd Parameters: %s\n", line);
    }
    fclose(file);

  

    snprintf(path, 40, "/proc/%d/environ", pid);
    file = fopen(path, "r");
    if (!file) {
        return 1;
    }

    printf("Environment Variables:\n");
    while (fgets(line, 100, file)) {
       char *p; 
       for (p = line; *p; p++) {
            if (*p == '\0') {
                *p = '\n';
            }
        }
        printf("%s", line);
    }
    fclose(file);

    return 0;
}

