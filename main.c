#include <stdlib.h>
#include "./include/malloc.h"

int main()
{
		char *mdr = malloc(2);
	mdr[0] = 'a';
	mdr[1] = '\0';
	my_putstr(mdr);
	mdr = realloc(mdr, 3);
	mdr[1] = 'b';
	mdr[2] = '\0';
	my_putstr(mdr);
	my_putchar('\n');
	// printf("\n%s\n", mdr);
	free(mdr);
	show_alloc_mem();
	return (0);
}
