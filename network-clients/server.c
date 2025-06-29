#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>

int main() {
	int listening_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in address_info = {0};
	address_info.sin_family = AF_INET;
	address_info.sin_addr.s_addr = INADDR_ANY;
	// Port numbers can be between 0 and 65535
	address_info.sin_port = htons(54721);
	
	int bind_result = bind(listening_socket_fd,
		(const struct sockaddr*) &address_info,
		sizeof(address_info));

	if (bind_result != 0) {
		printf("Failed to bind!\n");
	}

	int listen_result = listen(listening_socket_fd, 10);
	if (listen_result != 0) {
		printf("Failed to listen!\n");
	}

	while (1) {
		struct sockaddr client_addr;
		socklen_t client_addr_len;
		int communication_socket_fd = accept(listening_socket_fd, &client_addr, &client_addr_len);
		if (communication_socket_fd < 0) {
			printf("Failed to accept!\n");
		}

		pid_t fork_result = fork();
		if (fork_result == 0) {
			// I am the child process!
			char buffer[256] = {'\0'};
			int total_bytes_received = 0;
			while (strstr(buffer, "@@") == NULL) {
				int n_bytes_received = recv(
					communication_socket_fd,
					buffer + total_bytes_received,
					255 - total_bytes_received,
					0
				);
				total_bytes_received += n_bytes_received;
			}
			buffer[total_bytes_received - 1] = '\0';
			buffer[total_bytes_received - 2] = '\0';

			char* first_message = strtok(buffer, "$");
			char* second_message = strtok(NULL, "$");
			printf("The client's first message: %s\n", first_message);
			printf("The client's second message: %s\n", second_message);

			exit(0);
		} else {
			// I am the parent process!
			close(communication_socket_fd);
		}
	}

	// read, write
	// recv(), send()
}
