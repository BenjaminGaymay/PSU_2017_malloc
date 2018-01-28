##
## EPITECH PROJECT, 2017
## malloc
## File description:
## malloc
##

NAME	=	libmy_malloc.so

CC	=	gcc

RM	=	rm -f

SRCS	=	./src/malloc.c		\
		./src/list.c		\
		./src/useful.c		\
		./src/show_alloc_mem.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-I ./include/
CFLAGS +=	-Wall -Wextra -fPIC

$(NAME)	:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -shared -o $(NAME)

all	:	$(NAME)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY: all clean fclean re