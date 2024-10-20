SRCS = \
ft_printf.c ft_print_format.c ft_print_ptr.c

NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)

LIBC = ar rcs
FLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME)	: $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY : all clean fclean re