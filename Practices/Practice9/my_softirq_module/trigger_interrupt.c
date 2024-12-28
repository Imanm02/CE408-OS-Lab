#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define PROC_PATH "/proc/my_softirq"

int main() {
    int fd;
    const char *message = "Trigger Interrupt";

    fd = open(PROC_PATH, O_WRONLY);
    if (fd == -1) {
        perror("Failed to open /proc/my_softirq");
        return EXIT_FAILURE;
    }

    if (write(fd, message, sizeof("Trigger Interrupt")) == -1) {
        perror("Failed to write to /proc/my_softirq");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Interrupt triggered successfully.\n");

    close(fd);
    return EXIT_SUCCESS;
}