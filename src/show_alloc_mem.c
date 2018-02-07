/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc
*/

#include "malloc.h"

void show_alloc_mem(void)
{
	t_malloc *tmp;

	my_putstr("break : 0x");
	my_putbase((unsigned long)sbrk(0), HEXA);
	my_putchar('\n');

	tmp = g_list;
	while (tmp) {
		my_putstr("0x");
		my_putbase((unsigned long)(tmp + 1), HEXA);
		my_putstr(" - ");
		my_putstr("0x");
		my_putbase((unsigned long)((size_t)(tmp + 1) + tmp->size), HEXA);
		my_putstr(" : ");
		my_putbase(tmp->size, DECI);
		my_putstr(" bytes\n");
		tmp = tmp->next;
	}
}
