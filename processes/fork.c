#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	printf("I am the parent process\n");
	
	pid_t fork_result = fork();

	if (fork_result == 0) {
		printf("I am the child process\n");

		char* program_args[] = {"ls", "my_directoryfdsajfdsajfds/", (char*) NULL};
		execvp("ls", program_args);
	} else {
		int exit_status;
		waitpid(fork_result, &exit_status, 0);
		if (WIFEXITED(exit_status)) {
			// The child process exited "normally"
			// Extract the actual exit code from it
			int actual_exit_code = WEXITSTATUS(exit_status);
			printf("The child process exited normally with "
				"status %d\n", actual_exit_code);
		} else if (WIFSIGNALED(exit_status)) {
			// The child process was killed by a signal.
			// Extract the signal number
			int actual_signal_number = WTERMSIG(exit_status);
			printf("The child process was killed by "
				"signal %d\n", actual_signal_number);
		}
		printf("I am still the parent process\n");
	}
}
