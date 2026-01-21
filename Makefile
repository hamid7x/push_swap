CC = gcc
CFLAGS = -Werror -Wextra -Wall
NAME = push_swap
SRCS = push_swap.c push_swap_helper.c parse_args.c parse_utils.c ft_split.c\
      parse_helpers.c swap_op.c push_op.c rotate_op.c reverse_rotate_op.c\
      sort_helpers.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

