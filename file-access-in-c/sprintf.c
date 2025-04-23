#include <stdio.h>

int main() {
	char my_string[256];
	sprintf(my_string, "Hello, World! The value of pi is: %f", 3.14);

	printf("%s\n", my_string);
}
