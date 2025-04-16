#include <stdio.h>
#include <string.h>

int main() {
	char* sentence = "The epic highs and lows of high school football";
	size_t sizeof_sentence = strlen(sentence);
	printf("%d\n", sizeof_sentence);

	char substring[5] = {'\0'};
	strncpy(substring, sentence + 4, 4);
	printf("%s\n", substring);
	
	printf("%d\n", sizeof(sentence));

	char sentence_copy[strlen(sentence) + 1];
	strcpy(sentence_copy, sentence);
	printf("%s\n", sentence_copy);

	if (strcmp(sentence, sentence_copy) == 0) {
		printf("They're the same!\n");
	}

	char string[] = "The Incredible Hulk,2004";
	char* title = strtok(string, ",");
	char* year_string = strtok(NULL, ",");
	printf("%s\n", title);
	printf("%s\n", year_string);
	printf("%s\n", string);

	int* my_array = (int*) malloc(sizeof(int) * 100);

	free(my_array);
}
