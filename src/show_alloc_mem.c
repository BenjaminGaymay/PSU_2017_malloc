//
// EPITECH PROJECT, 2018
// malloc
// File description:
// malloc
//

#include "malloc.h"

void show_alloc_mem()
{
	my_putstr("break : 0x");
	my_putbase((unsigned long)sbrk(0), HEXA);
	my_putchar('\n');
	
}