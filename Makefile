SRCS  = srcs/do_ops.c srcs/files_handling.c srcs/inits_and_free.c \
			srcs/pipes.c srcs/pipex.c srcs/processes.c \
			srcs/get_next_line.c
SRCS_DIR = ./srcs/
HEAD	= includes/pipex.h
OBJS	= ${SRCS:.c=.o}
NAME	= pipex
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -f
LIBFT 	= libft/libft.a
LIBFTDIR = ./libft/

all: $(NAME) $(LIBFT)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@

$(LIBFT):
	make -C $(LIBFTDIR)

clean:
		$(RM) $(OBJS)
		make -C $(LIBFTDIR) clean

fclean: clean
		make -C $(LIBFTDIR) fclean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re