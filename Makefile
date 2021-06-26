SRCS  = srcs/do_ops.c srcs/files_handling.c srcs/inits_and_free.c \
			srcs/pipes.c srcs/pipex.c srcs/processes.c \
			srcs/get_next_line.c
HEAD	= includes/pipex.h
OBJS	= ${SRCS:.c=.o}
NAME	= pipex
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -f
LIB 	= libft/libft.a

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(LIB) $^ -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re