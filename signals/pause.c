#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
	alarm(5);
	pause();
	printf("Hello, world!\n");
}
