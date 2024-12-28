#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int ret = fork();
    if (ret == 0) {
        printf("child's parent PID:%d\n", getppid());
        sleep(5);
        printf("child's parent PID:%d\n", getppid());
        return 0;
    } else {
        sleep(1);
        printf("Parent is returning.\n");
	return 0;
    }
}
