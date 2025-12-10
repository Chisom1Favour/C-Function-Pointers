/* Explore control flow ambiguity that happens with function pointers
 * Also explores how attack can be done using function pointers through
 * engineered buffer overflow.
 * function_ptr is initialized to safe, but through buffer overflow, the buffer
 * gets overwritten and function_ptr points to unsafe()
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void safe()
{
	print("safe\n");
}
void unsafe()
{
	printf("unsafe\n");
}
void run(void (*fp)())
{
	fp();
}
void vulnerable_function(char *input)
{
	char buffer[64]; // Small buffer on stack
	void (*function_ptr)() = safe; // Function pointer initialized to safe()
	printf("Buffer is at:              %p\n", buffer);
	printf("Function pointer is at %p\n", &function_ptr);
	printf("Function pointer points to: %p (should be safe at %p)\n", function_ptr, safe);
	printf("Unsafe function is at: %p\n", unsafe);

	// VULNERABILITY: No bounds checking!
	strcpy(buffer, input); // This can overflow
	printf("After strcpy, function pointer points to: %p\n", function_ptr);
	// Call whatever function_ptr points to
	run(function_ptr);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s input\n", argv[0]);
		printf("\nThis program demonstrates a buffer overflow attack\n");
		printf("Try:\n");
		printf(" Normal: %s \"Hello\"\n", argv[0]);
		printf(" Exploit: %s \"$(python -c 'print \"A\"*72 + \"\\x??\\x??\\x??\\x??\"')\"\n", argv[0]);
		return 1;
	}
	printf("===Buffer overflow demonstration ===/n/n");
	vulnerable_function(argv[1]);

	return 0;
}
