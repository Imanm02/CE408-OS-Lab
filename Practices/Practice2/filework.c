#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int file = open("oslab2.txt", O_WRONLY| O_CREAT | O_TRUNC);
	if (file < 0)
		return -1;
	long success = write(file, "Negar Babashah", 14);
	close(file);
	if (success < 0)
		return -1;

}
