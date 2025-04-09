#include <stdio.h>

// main is the entrypoint and also the exit point of every program
//
int main() {
	printf("Hello, World!\n");

	int x = 3;
	long int y = 30000000000;
	char letter = '!';
	char null_terminator = '\0';
	float pi = 3.14;
	double big_pi = 3.1415926535;
	
	size_t size_double = sizeof(double);
	
	printf("The value of pi is: %.2f\n", pi);
	printf("The value of x is: %d\n", x);
	printf("The value of big_pi is: %lf\n", big_pi);
	printf("The value of letter is: %c\n", letter);
	printf("My first name is: %s\n", "Alex");

	// +, -, *, /, % (modulo operator)
	printf("The sum of pi and big_pi is: %lf\n", pi + big_pi);

	// For the curious reader: Google "post-increment vs pre-increment"
	x++; // Increments x to 4
	++x; // Increments x to 5
}
