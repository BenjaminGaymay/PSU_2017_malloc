//
// EPITECH PROJECT, 2018
// malloc
// File description:
// malloc
//

#include "malloc.h"

int add_in_list(t_malloc **list, size_t size, void *addr)
{
	t_malloc *new;

	new = sbrk(sizeof(*new));
	if (new == (void*)-1) {
		return (ERROR);
	}
	new->size = size;
	new->addr = addr;
	new->next = *list;
	*list = new;
	return (SUCCESS);
}

void dump_list(t_malloc *list)
{
	t_malloc *tmp;

	tmp = list;
	while (tmp) {
		// my_putnbr(tmp->size);
		my_putchar('\n');
		tmp = tmp->next;
	}
}