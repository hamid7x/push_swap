# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/31 14:02:58 by houkaamo          #+#    #+#              #
#    Updated: 2026/02/05 04:30:59 by houkaamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wextra -Wall

NAME = push_swap
BONUS_NAME = checker

HEADER = push_swap.h
BONUS_HEADER = push_swap_bonus.h

SRCS = push_swap.c push_swap_helper.c parse_args.c parse_utils.c ft_split.c\
      parse_helpers.c swap_op.c push_op.c rotate_op.c reverse_rotate_op.c\
      sort_small_stack.c sort_large_stack.c long_inc_sub.c cost_helper.c\
      search_helper.c move_helper.c

BONUS = checker_bonus.c parse_args_bonus.c parse_utils_bonus.c parse_helpers_bonus.c\
	ft_split_bonus.c ft_strjoin_bonus.c checker_helper_bonus.c push_op_bonus.c swap_op_bonus.c rotate_op_bonus.c\
	reverse_rotate_op_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

$(OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJS): %.o: %.c $(BONUS_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
re: fclean all

