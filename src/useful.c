//
// EPITECH PROJECT, 2018
// malloc
// File description:
// malloc
//

#include <unistd.h>

int my_strlen(char *s)
{
	int i = 0;

	while (s[i])
		++i;
	return i;
}

void my_putchar(char a)
{
	write(1, &a, 1);
}

void my_putstr(char *s)
{
	write(1, s, my_strlen(s));
}

void	my_putbase(unsigned long nb, char *base)
{
	unsigned long base_len;
	unsigned long i;
	unsigned long c;

	base_len = my_strlen(base);
	i = nb % base_len;
	c = (nb - i) / base_len;
	if (nb >= base_len - 1 && c != 0)
		my_putbase(c, base);
	write(1, &base[i], 1);
}