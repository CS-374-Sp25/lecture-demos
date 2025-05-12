#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int pipe_fds[2];
	pipe(pipe_fds);

	// At this point, pipe_fds[0] is a reading file descriptor,
	// pipe_fds[1] is a writing file descriptor.
	
	pid_t fork_result = fork();

	if (fork_result == 0) {
		// I'm the child!
		close(pipe_fds[1]);

		char* message = NULL;
		size_t total_bytes_read = 0;
		
		char buffer[10];
		do {
			size_t bytes_read = read(pipe_fds[0], buffer, 10);
			total_bytes_read += bytes_read;

			message = realloc(message, total_bytes_read);
			memcpy(message + (total_bytes_read - bytes_read), buffer, bytes_read);
		} while (message[total_bytes_read - 1] != '\0');

		printf("%s\n", message);
	} else {
		// I'm the parent!

		// Option 1: Before sending the message, send the size of the
		// message.

		// Option 2: Send the message, and suffix it with a
		// terminating sequence.
		close(pipe_fds[0]);
		char buffer[] = "Hi there! Have a good day at school!";
		size_t total_bytes_to_write = strlen(buffer) + 1;
		size_t total_bytes_written = 0;
		while (total_bytes_written < total_bytes_to_write){
			size_t bytes_written = write(pipe_fds[1], buffer + total_bytes_written, total_bytes_to_write - total_bytes_written);
			total_bytes_written += bytes_written;
		}
	}
}
