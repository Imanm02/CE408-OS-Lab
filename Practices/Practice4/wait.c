#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

	int ret = fork();
	if (ret == 0) {
		// chlid
		for (int i = 1; i <= 100; i++) {
			printf("%d, ", i);
		} 
		printf("\n");
		return 0;
	} else {
		// parent
		wait(NULL);
		printf("Child process has finished counting!\n");
		return 0;
	}
}
