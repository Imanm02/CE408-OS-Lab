#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


extern char etext, edad, end;

int main(int argc, char *argv[]){

	printf("First address past:\n");
	printf("	program text (etext)		%10p\n", &etext);
	printf("	initialized data(edata)		%10p\n", &etext);
	printf("	uninitialized data (end)	%10p\n", &end);

	exit(EXIT_SUCCESS);

}
