#include <stdio.h>
#include <signal.h>

int main() {
	raise(SIGCHLD);
	printf("Hello, world!\n");
}
