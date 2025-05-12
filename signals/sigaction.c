#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

// open()
// close()
// read()
// write()
// lseek()

volatile sig_atomic_t foreground_only_mode = 0;

// Reentrancy: A function is reentrant if it can be "restarted" in the middle
// of execution and still behave well
void sigint_handler(int signo) {
	// In general, basically all stdio.h functions are non-reentrant
	// printf("Hello, World!\n");
	write(1, "Hello, World!\n", 14);

	if (foreground_only_mode) {
		foreground_only_mode = 0;
	} else {
		foreground_only_mode = 1;
	}
}

int main() {
	sigset_t my_signal_set;
	sigfillset(&my_signal_set);
	sigdelset(&my_signal_set, SIGINT);

	// Create sigaction structure whose fields are all zero initially
	struct sigaction sigint_sa = {0};
	// Populate fields that we care about.
	sigint_sa.sa_handler = sigint_handler;
	// sigint_sa.sa_handler = SIG_IGN;
	// sigint_sa.sa_handler = SIG_DFL;
	sigfillset(&(sigint_sa.sa_mask));
	sigint_sa.sa_flags = SA_RESTART;

	// DON'T UNCOMMENT THE BELOW LINE. JUST INITIALIZE THE SIGACTION
	// STRUCTURE TO {0}, AS ABOVE.
	// sigint_sa.sa_sigaction = NULL;

	sigaction(SIGINT, &sigint_sa, NULL);

	// Line a
	// line b
	// line c

	pid_t fork_result = fork();

	if (fork_result == 0) {
		// I am the child process
		struct sigaction child_sigint_sa = {0};
		child_sigint_sa.sa_handler = SIG_IGN;
		sigaction(SIGINT, &child_sigint_sa, NULL);
		char* command = "sleep";
		char* args[] = {"sleep", "10", NULL};
		execvp(command, args); // SIG_IGN is preserved!
	} else {
		// I am the parent process
	}

	pause();
	pause();
	pause();
}
