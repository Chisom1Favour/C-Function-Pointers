/* This code explores indirect call ambiguity in function pointers */
/* Also shows ambuigity for dynamic dispatch at runtime */

#include <stdio.h>

void authenticate();
void process_packet();
/* Not type safe. Takes an unspecified no. of arguments. void (*handler)();
 * So this global variable will be rewritten to a local variable with 
 * type safety
 */

void dispatch(int code)
{
	void (*local_handler)(void) == NULL;
	if (code == 1)
	{
		local_handler = authenticate;
	}
	else if (code == 2)
	{
		local_handler = process_packet;
	}
	else
	{
		return;
	}

	if (local_handler)
	{
		local_handler(); // Safe: local variable
	}
}

