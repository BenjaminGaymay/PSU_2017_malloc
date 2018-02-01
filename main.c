#include "./include/malloc.h"

int main()
{
	char *a = malloc(10);
	char *b = malloc(20);
	char *c = malloc(20);
	char *d = malloc(20);
	char *e = malloc(200);
	dump_list(g_list);
	show_alloc_mem();
	return 0;
}