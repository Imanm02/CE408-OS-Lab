#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
	printf("Parent PID is: %d\n", getppid());
	return 0;
}
