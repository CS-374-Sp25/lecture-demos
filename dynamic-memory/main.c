#include <stdio.h>
#include <stdlib.h>

void foo() {
	static int y = 1;
	printf("%d\n", y);
	y++;
}

int main() {
	/*
	foo(); // Prints 1
	foo(); // Prints 2
	*/

	// Compile-time constant: has to be known at compile time
	int n;
	scanf("%d", &n);
	char* my_string = (char*) calloc(n, sizeof(char));
	/*
	int i;
	for (i = 0; i < n; i++) {
		my_string[i] = '\0';
	}
	*/
	my_string[0] = 'H';
	my_string[1] = 'i';
	printf("%s\n", my_string);

	// Create a new array that's bigger than the old one
	// Copy the elements from the old array to the new array
	// Add a new element to the end
	// Increment the size
	// Delete the old array
	
	my_string = realloc(my_string, sizeof(char) * n * 2);

	free(my_string);

	// valgrind
}
