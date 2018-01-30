// #include <stdio.h>
#include "malloc.h"
void show_alloc_mem();
int main()
{
	char *mdr = malloc(120);
	mdr[0] = 'a';
	mdr[1] = 'b';
	mdr[2] = '\0';
	// my_putstr(mdr);
	// printf("\n%s\n", mdr);
	free(mdr);
	show_alloc_mem();
	return (0);
}