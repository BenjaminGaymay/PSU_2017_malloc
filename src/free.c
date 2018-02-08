/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc
*/

#include "malloc.h"

void merge_free(t_malloc *current)
{
	size_t s = current->size;

	if (current->next && current->next->free == FREE) {
		s += current->next->size + sizeof(t_malloc);
		current->next = current->next->next;
		if (current->next)
			current->next->prev = current;
	}
	if (current->prev && current->prev->free == FREE) {
		s += current->prev->size + sizeof(t_malloc);
		current->prev->next = current->next;
		if (current->next)
			current->next->prev = current->prev;
	}
	current->size = s;
}

void free(void *ptr)
{
	t_malloc *tmp;

	if (ptr) {
                pthread_mutex_lock(&g_thread);
		tmp = (t_malloc *)ptr - 1;
		tmp->free = FREE;
		merge_free(tmp);
                pthread_mutex_unlock(&g_thread);
	}
}
