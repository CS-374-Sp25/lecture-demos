#include <stdio.h>
#include <stdlib.h>

/*
char* create_char() {
	// my_character has automatic storage duration
	char my_character = 'C';
	return &my_character;
}
*/

void change_me(int x[]) {
	x[0] = 10;
}

void func(int* p) {
	*p = 100;
}

int main() {
	int x;
	func(&x);
	int y;
	int* p = &x;
	*p = 10;

	*(p + 1) = 100;
	*(p - 1) = 200;

	printf("%d\n", y);

	// Dangling pointer
	/*
	char* p2 = create_char();
	printf("%c\n", *p2); // Undefined behavior. Use-after-free error
	*/

	// NULL is simply 0
	p = NULL;

	int numbers[10] = {1, 2, 3};
	
	printf("%p\n", numbers);
	printf("%p\n", &(numbers[0]));

	change_me(numbers);

	char my_string[6] = {'H', 'e', 'l', 'l', 'o'};
	printf("%s\n", my_string);
}
