/* Explores simple control flow ambiguity that happens with function pointers
 */

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
