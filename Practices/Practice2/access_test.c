#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    const char *path = argv[1];
    if (access(path, F_OK) == 0) {
        if (access(path, R_OK) == 0) {
            printf("I have read access to the path.\n");
        } else {
            printf("I don't have read access to the path.\n");
        }
    } else {
        printf("The path doesn't exist.\n");
    }
    return 0;
}
