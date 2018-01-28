#include <unistd.h>
#include "malloc.h"

t_malloc *g_list;

void *malloc(size_t size)
{
	void *ptr;

	if (size == 0)
		return (NULL);
	ptr = sbrk(size);
	if (add_in_list(&g_list, size, ptr) == ERROR)
		return (NULL);
	// dump_list(g_list);
	return (ptr);
}

void free(void *ptr)
{
	ptr = sbrk(-120);
}