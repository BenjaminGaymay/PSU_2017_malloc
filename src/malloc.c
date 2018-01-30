#include <unistd.h>
#include "malloc.h"

t_malloc *g_list;

void *malloc(size_t size)
{
	t_malloc *new;
	t_malloc *mdr;

	if (!g_list) {
		new = create_block(NULL, size);
		if (!new)
			return (NULL);
		g_list = new;
	} else {
		mdr = g_list;
		new = find_block(&mdr, size);
		if (new)
			new->free = UNFREE;
		else {
			new = create_block(mdr, size);
			if (!new)
				return (NULL);
		}
	}
	// dump_list(g_list);
	// show_alloc_mem();
	return (new + 1);
}

void free(void *ptr)
{
	return;
}