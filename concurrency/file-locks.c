#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	fork();
	
	// Acquire the lock
	int fd;
	while ((fd = open("file.lock", O_WRONLY | O_CREAT | O_EXCL, 0777)) == -1) {
		sleep(1);
	}
	close(fd);

	// This line of code is a critical section
	printf("Hello, World!\n");

	// Release the lock
	remove("file.lock");
}
