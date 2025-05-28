#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>

int main() {
	
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in address_info = {0};
	address_info.sin_family = AF_INET;

	// Domain name: google.com
	// Hostname: The name of a host
	// Host: A computer on a network
	
	int connect_result = -1;

	/*
	address_info.sin_addr.s_addr = inet_addr("192.168.0.5");
	address_info.sin_port = htons(80);
	
	connect_result = connect(socket_fd,
		(const struct sockaddr*) &address_info,
		sizeof(address_info));
	*/

	struct addrinfo hints = {0};
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = 0;

	struct addrinfo* addrinfo_list = NULL;
	int getaddrinfo_result = getaddrinfo(
		"localhost",
		"54721",
		&hints,
		&addrinfo_list
	);

	if (getaddrinfo_result != 0) {
		printf("getaddrinfo() failed!\n");
	}

	struct addrinfo* itr = addrinfo_list;
	while (itr != NULL) {
		// Try to connect, breaking loop if successful
		connect_result = connect(socket_fd, itr->ai_addr, itr->ai_addrlen);
		if (connect_result == 0) {
			break;
		}

		// Step iterator
		itr = itr->ai_next;
	}
	
	if (connect_result != 0) {
		// Some error occurred. Deal with it here
		printf("Failed to connect!\n");
	}

	
	char* message = "Yo server! I heard you like clients!";
	int n_bytes_sent = send(socket_fd, message, strlen(message), 0);
}
