#include <stdio.h>

double sum(double a, double b) {
	return a + b;
}

// void return type for functions that don't return anything

struct person {
	int age;
	char first_initial;
};

// main is the entrypoint and also the exit point of every program
//
int main() {
	printf("Hello, World!\n");

	int x = 3;
	long int y = 30000000000;
	char letter = ' ';
	int letter_ascii_number = letter;
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

	x--; // Decrements x to 4
	--x; // Decrements x to 3

	/*
	x+1; // Legal C statement
	4; // Legal C statement
	*/
	
	x += 5; // This increases x by 5
	// -=
	// *=
	// /=
	// %=
	
	// This is "type coercion", which is also called "implicit type casting"
	// Type casting means to convert data of one type to another
	x = 3.99; // This is legal
	double double_x = x;

	// You can implicitly type cast basically any primitive type to any other
	// primitive type
	
	// Explicit type casting:
	printf("%lf\n", (double) x);

	// Relational operators:
	// >=
	// >
	// <=
	// <
	// !=
	// ==, NOT the same thing as =
	//
	// Logical operators:
	// || (logical OR operator)
	// && (logical AND operator)
	// ! (logical NOT operator)
	if (x == 3 || x > 5) {
		// If statement body
		printf("Hello, World!\n");
	} else if (x == 4) {
		printf("X is 4!\n");
	} else {
		printf("X is less than 3\n");
	}

	int i = 0;
	while (i < 10) {
		i++;
		printf("%d\n", i);
	}

	/*
	do {
		// Body of code
	} while(condition);
	*/

	// gcc main.c
	int j; // j is currently "garbage"
	printf("%d\n", j); // Undefined behavior
	for (j = 0; j < 10; ++j) {
		// The loop body
	}

	// Automatic arrays
	//
	// All data has a storage duration.
	// Automatic storage duration
	// Dynamic storage duration
	// Static storage duration
	// Thread-local storage duration
	
	char my_string[256] = {'H', 'e', 'l', 'l', 'o'};
	my_string[0] = 'H';
	printf("%c\n", my_string[0]);
	printf("%c\n", my_string[1]);
	printf("%s\n", my_string);

	/*
	// Buffer overflow. Stack smashing
	my_string[256] = 'C'; // Arbitrary code execution (ACE) exploit
	// Buffer overread
	printf("%c\n", my_string[256]);
	*/
	
	struct person p;
	p.age = 25;
	p.first_initial = 'L';

	struct person* person_pointer = &p;
	(*person_pointer).age = 26;
	person_pointer->age = 27;

	
}
