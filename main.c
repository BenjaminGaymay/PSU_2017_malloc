#include <stdio.h>
#include "malloc.h"

int main()
{
	// char *mdr;

	// mdr = malloc(120);
	// mdr[0] = 'a';
	// mdr[1] = 'b';
	// mdr[2] = '\0';
	// printf("\n%s\n", mdr);
	// free(mdr);
	int lol = sbrk(0);
	printf("%p\n", &lol);
	show_alloc_mem();
	return (0);
}