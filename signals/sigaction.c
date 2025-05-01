#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

// open()
// close()
// read()
// write()
// lseek()

// Reentrancy: A function is reentrant if it can be "restarted" in the middle
// of execution and still behave well
void sigint_handler(int signo) {
	// In general, basically all stdio.h functions are non-reentrant
	// printf("Hello, World!\n");
	write(1, "Hello, World!\n", 14);
}

int main() {
	sigset_t my_signal_set;
	sigfillset(&my_signal_set);
	sigdelset(&my_signal_set, SIGINT);

	// Create sigaction structure whose fields are all zero initially
	struct sigaction sigint_sa = {0};

	// Populate fields that we care about.
	sigint_sa.sa_handler = sigint_handler;
	sigfillset(&(sigint_sa.sa_mask));
	sigint_sa.sa_flags = SA_RESTART;
	// DON'T DO THIS. JUST INITIALIZE THE SIGACTION STRUCTURE TO {0}, AS
	// ABOVE.
	// sigint_sa.sa_sigaction = NULL;

	sigaction(SIGINT, &sigint_sa, NULL);

	// Line a
	// line b
	// line c

	pause();
	pause();
	pause();
}
