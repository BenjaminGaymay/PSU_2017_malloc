//
// EPITECH PROJECT, 2018
// malloc
// File description:
// malloc
//

#pragma once

#include <unistd.h> 

#define ERROR 84
#define SUCCESS 0
#define HEXA "0123456789ABCDEF"

typedef struct s_malloc {
	size_t size;
	void *addr;
	int free;
	struct s_malloc *next;
} t_malloc;

int add_in_list(t_malloc **, size_t, void *);
void dump_list(t_malloc *);
void *malloc(size_t);
void free(void *);

void my_putchar(char);
void my_putstr(char *);
void my_putnbr(size_t size);
void my_putbase(unsigned long, char *);
void show_alloc_mem();