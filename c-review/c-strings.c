#include <stdio.h>

int main(int argc, char** argv) {
	printf("%d\n", argc);
	printf("%s\n", argv[0]);
	printf("%s\n", argv[1]);


	// char my_string[7] = {'H', 'e', 'l', 'l', 'o', '\0', 'Z'};
	// printf("%s\n", my_string + 1);
	// printf("%c\n", my_string[6]);

	// Automatic storage duration
	// char my_string[7] = "Hello";
	char my_string1[] = "Hello";
	char my_string2[] = "Hello";
	char my_string3[] = "Hello";

	my_string1[0] = 'J';

	// This is not on the stack
	// This is not on the heap
	// It's in the read-only section of the "data segment" of memory
	const char* my_string4 = "Hello";
	char* my_string5;
	my_string5 = "Hello";
	// my_string4[0] = 'J'; // This is NOT allowed!!!

	// printf("%p %d\n", my_string4, 3);
	// printf("%p\n", my_string5);

	int input1;
	float input2;
	printf("Enter an integer, followed by a floating point number: ");
	// scanf("%d %f", &input1, &input2);
	// printf("%d\n", input1);
	// printf("%f\n", input2);

	char* my_c_string = "Hello";
	size_t buffer_size = 0;
	printf("Enter a sentence: ");
	ssize_t string_length = getline(&my_c_string, &buffer_size, stdin);
	my_c_string[string_length - 1] = '\0'; // Remove \n from the end
	printf("%s\n", my_c_string);
}
