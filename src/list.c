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
	my_putstr("START\n\n");
	while (tmp) {
		my_putstr("Size of the block : ");
		my_putbase(tmp->size, DECI);
		my_putstr("\nAddr of the block : 0x");
		my_putbase((unsigned long)tmp->addr, HEXA);
		my_putchar('\n');
		my_putchar('\n');
		tmp = tmp->next;
	}
}
