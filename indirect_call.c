/* This code explores indirect call ambiguity in function pointers */
/* Also shows ambuigity for dynamic dispatch at runtime */

#include <stdio.h>

void authenticate();
void process_packet();
void (*handler)();

void dispatch(int code)
{
	if (code == 1)
	{
		handler = authenticate;
	else
		handler = process_packet;
	}

	handler();
}
