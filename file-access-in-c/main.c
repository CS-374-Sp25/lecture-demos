#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	FILE* data_file = fopen(argv[1], "r");

	if (data_file == NULL) {
		printf("Failed to open the file!\n");
		return 1;
	}

	while (!feof(data_file)) {
		char* line = NULL;
		size_t n = 0;
		// The invisible cursor that traverse the file as you read from /
		// write to it is called the "file offset"
		ssize_t length_of_line = getline(&line, &n, data_file);
		if (length_of_line > 0) {
			line[length_of_line - 1] = '\0';
			length_of_line--;
			printf("%s\n", line);
		}
		free(line);
	}

	fprintf(data_file, "%f\n", 3.14);

	fclose(data_file);
}
