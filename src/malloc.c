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

        if (size <= 0)
                return (NULL);
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
	return (new + 1);
}

void *realloc(void *ptr, size_t size)
{
        void *new;
        char *tmp;
        char *cpy;
        t_malloc *meta_data;

        if (! ptr) {
                ptr = malloc(size);
                return (ptr);
        }
        if (size == 0) {
                free(ptr);
                return (NULL);
        }
        cpy = (char *)ptr;
        meta_data = (t_malloc *)ptr - 1;
        new = malloc(meta_data->size + size);
        tmp = (char *)new;
        if (! new)
                return (ptr);
        for (int i = meta_data->size ; i * sizeof(char) > 0 ; i--) {
                *tmp = *cpy;
                tmp++;
                cpy++;
        }
        // new = memcpy(new, ptr, meta_data->size);
        free(ptr);
        return (new);
}

void free(void *ptr)
{
        t_malloc *tmp;

        if (ptr) {
                tmp = find_free(ptr);
                tmp->free = FREE;
        }
}
