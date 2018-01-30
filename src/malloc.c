/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc
*/

#include <unistd.h>
#include "malloc.h"

t_malloc *g_list = NULL;

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
	return (new + 1);
}

void free(void *ptr)
{
        if (! ptr)
                return ;
        t_malloc *tmp = find_free(ptr);

        tmp->free = FREE;
        // my_putstr("\nSize :\n");
        // my_putbase(tmp->size, DECI);
        // my_putstr("\nADDR :\n0x");
        // my_putbase((unsigned long)tmp, HEXA);
	return;
}
