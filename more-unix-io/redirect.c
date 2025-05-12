#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int the_file = open("output.txt", O_WRONLY | O_CREAT, 0777);
	dup2(the_file, 1);
	printf("Hello, World!\n");
}
