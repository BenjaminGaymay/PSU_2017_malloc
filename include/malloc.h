/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** malloc
*/

#ifndef _MALLOC_
# define _MALLOC_

# include <unistd.h>
# include <pthread.h>

# define ERROR 84
# define SUCCESS 0
# define HEXA "0123456789ABCDEF"
# define DECI "0123456789"
# define NOTFREE 0
# define FREE 1
# define SBRK_FAIL (void *) - 1

typedef struct s_malloc {
	struct s_malloc *next;
	struct s_malloc *prev;
	size_t size;
	int free;
	int uggly;
} t_malloc;

void dump_list(t_malloc *);
void *malloc(size_t);
void *calloc(size_t, size_t);
void *realloc(void *, size_t);
void free(void *);
void merge_free(t_malloc *);
void show_alloc_mem(void);
t_malloc *find_block(size_t);
t_malloc *create_block(t_malloc *, size_t);
t_malloc *find_free(void *);

void my_putchar(char);
void my_putstr(char *);
void my_putnbr(size_t size);
void my_putbase(unsigned long, char *);

extern t_malloc *g_list;
extern pthread_mutex_t g_thread;

#endif /* _MALLOC_ */
