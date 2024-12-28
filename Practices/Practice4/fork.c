#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
	int ret1 = fork();
	if (ret1 == 0) {
		return 23;
	} else {
		int rc = 0;
		wait(&rc);
		printf("return code is %d\n", WEXITSTATUS(rc));
	}
	printf("After first fork, ret1 = %d\n", ret1);
	int ret2 = fork();
	printf("After second fork, ret1 = %d, ret2 = %d\n", ret1, ret2);
	int ret3 = fork();
	printf("After third fork, ret1 = %d, ret2 = %d, ret3 = %d\n", ret1, ret2, ret3);
	return 0;
}
