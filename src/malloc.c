/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc
*/

#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "malloc.h"

t_malloc *g_list = NULL;
pthread_mutex_t g_thread;

void *malloc(size_t size)
{
	t_malloc *new;

	pthread_mutex_lock(&g_thread);
	if (size <= 0) {
		pthread_mutex_unlock(&g_thread);
		return (NULL);
	}
	new = find_block(&g_list, size);
	if (new)
		new->free = UNFREE;
	else {
		new = create_block(g_list, size);
		if (!new) {
			pthread_mutex_unlock(&g_thread);
			return (NULL);
		}
		g_list = (!g_list ? new : g_list);
	}
	pthread_mutex_unlock(&g_thread);
	return (new + 1);
}

void *realloc(void *ptr, size_t size)
{
	void *new;
	t_malloc *meta_data;

	if (!ptr)
		return (malloc(size));
	if (size == 0) {
		free(ptr);
		return (NULL);
	}
	meta_data = (t_malloc *)ptr - 1;
	if (size <= meta_data->size)
		return (ptr);
	new = malloc(size);
	if (!new)
		return (ptr);
	new = memcpy(new, ptr, meta_data->size);
	free(ptr);
	return (new);
}

void *calloc(size_t nmemb, size_t size)
{
	void *ptr = malloc(nmemb * size);

	return (!ptr ? NULL : memset(ptr, 0, size));
}

void free(void *ptr)
{
	t_malloc *tmp;

	if (ptr) {

		tmp = (t_malloc *)ptr - 1;
		tmp->free = FREE;
		ptr = memset(ptr, 0, tmp->size);
	}
}
