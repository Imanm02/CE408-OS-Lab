#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t ret = fork();

    if (ret == 0) {
        char *args[] = {"ls", "-g", "-h", NULL};
        execvp("ls", args);
    } else {
        wait(NULL);
    }
    return 0;
}
