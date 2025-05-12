#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main() {
	FILE* the_file = fopen("data.txt", "w");
	pid_t fork_result = fork();
	if (fork_result == 0) {
		// I'm the child!
		fprintf(the_file, "Hello, ");
	} else {
		// I'm the parent!
		fprintf(the_file, "World!");
	}

}
