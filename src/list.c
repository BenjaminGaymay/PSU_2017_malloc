/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc
*/

#include "malloc.h"

void dump_list(t_malloc *list)
{
	t_malloc *tmp;

	tmp = list;
	my_putstr("START\n\n");
	while (tmp) {
		my_putstr("Size of the block : ");
		my_putbase(tmp->size, DECI);
		my_putstr("\nAddr of the block : 0x");
		my_putbase((unsigned long)tmp, HEXA);
		my_putstr("\n\n");
		tmp = tmp->next;
	}
}

t_malloc *find_block(t_malloc **list, size_t size)
{
	t_malloc *cur = g_list;

	while (cur && !(cur->free == FREE && size <= cur->size)) {
		*list = cur;
		cur = cur->next;
	}
	return (cur);
}

t_malloc *create_block(t_malloc *list, size_t size)
{
	t_malloc *new;

	new = sbrk(size + sizeof(t_malloc));
	if (new == SBRK_FAIL)
		return (NULL);
	if (list)
		list->next = new;
	new->size = size;
	new->next = NULL;
	new->free = UNFREE;
	return (new);
}
