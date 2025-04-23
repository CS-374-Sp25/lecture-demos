#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main() {
	// umask(0000);
	int fd = open("data2.txt", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	// int fd = open("data.txt", O_RDONLY, 0777);

	// char my_string[256] = {'\0'};

	// This technically might not read 255 bytes, even if there are
	// 255 available in the file.
	// read(fd, my_string, 255);

	// printf("%s\n", my_string);
	
	char* cool_string = "The epic highs and lows of high school football";
	write(fd, cool_string, strlen(cool_string));

	close(fd);

	
}

// 11000000000000000000000000000000
// 10100000000000000000000000000000
// 
// 11100000000000000000000000000000
