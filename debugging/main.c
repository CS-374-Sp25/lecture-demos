#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* create_int() {
	int x = 10; // x has automatic storage duration
	return &x;
}

int main() {
	int x = 0; // Uninitialized. "Garbage"
	printf("%d\n", x); // Print a garbage value

	x = x + 1;
	x++;

	printf("%d\n", x);

	
	// char c[256];
	char* c = (char*) malloc(sizeof(char) * 256);
	strcpy(c, "Hello");
	free(c);

	// c[256] = 'A';
	
	int* x_pointer = create_int(); // dangling pointer
	*x_pointer++; // Use-after-free
	
}
