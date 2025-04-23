#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
	// struct stat file_info;
	// stat("a.txt", &file_info);

	// printf("UID: %d\nSize: %d\n", file_info.st_uid, file_info.st_size);

	DIR* handle = opendir("./");
	struct dirent* entry;
	while ((entry = readdir(handle)) != NULL) {
		printf("%s\n", entry->d_name);
	}

	closedir(handle);
}
