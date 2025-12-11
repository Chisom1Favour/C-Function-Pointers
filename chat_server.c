#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

/*
 * REAL-WORLD SCENARIO: Chat Server
 *
 * A company builds a chat server that runs on port 9999.
 * Developers wrote this code, trusted it, deployed it to production.
 * They never noticed the vulnerability.
 *
 * The attacker NEVER modifies this code.
 * The attacker sends malicious network packets to exploit it
 */

void log_message(const char *msg)
{
	printf("[LOG] %s\n", msg);
}

void admin_shell()
{
	printf("[CRITICAL] Admin shell spawned! This should never happen\n");
	system("/bin/sh");
}

void process_message(char *message)
{
	char username[32];
	char msg_buffer[128];
	void (*logger)(const char *) = log_message; // Function pointer for logging
	printf("\n=== Processing Client Message ===\n");
	printf("Stack layout:\n");
	printf("  username at:     %p\n", username);
	printf("  msg_buffer at: %p\n", msg_buffer);
	printf("  Logger at: %p\n", &logger);
	printf("  admin_shell at: %p\n\n", admin_shell);

	// Extract username (developers thought this was safe)
	sscanf(message, "USER:%s MSG:%[^\n]", username, msg_buffer);
	printf("Received from '%s': %s\n", username, msg_buffer);
	logger(msg_buffer);
	printf("Message proceessed successfully\n");
}
void start_server()
{
	int server_fd, client_fd;
	struct sockaddr_in server_addr, client_addr;
	socklen_t client_len = sizeof(client_addr);
	char buffer[2048];
	// Create socket
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0)
	{
		perror("Socket creation failed");
		exit(1);
	}
	int opt = 1;
	setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	// Bind to port 9999
	server_addr.sin_family = AF_INET;
	server_adr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(9999);
	if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
	{
		perror("Bind failed");
		exit(1);
	}
	listen(server_fd, 5);
	printf("Chat server listening on port 9999...\n");
	printf("Waiting for clients...\n\n");
	while (1)
	{
		client_fd = accept (server_fd, (struct sockaddr *)&client_addr, &client_len);
		if (client_fd < 0)
			continue;
		printf("\n[+\ Client connected from %s\n", inet_nota(client_addr, sin_addr));
		// Receive message
		int bytes = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';

			// VULNERABILITY: No validation of input length
			process_message(buffer);
		}

		send(client_fd, "Message received\n", 17, 0);
		close(client_fd);
	}
}

// Simulate the attack for demonstration
void demonstrate_attack()
{
	printf("\n=========================================\n");

