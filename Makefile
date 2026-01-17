CC = gcc
CFLAGS = -Werror -Wextra -Wall
NAME = push_swap
SRCS = push_swap.c push_swap_helper.c parse_args.c parse_utils.c \
      parse_helpers.c swap_op.c push_op.c retate_op.c retate_reverse_op.c
OBJS = $(SRCS: .O=.C)

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

