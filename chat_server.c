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

