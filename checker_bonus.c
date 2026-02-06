/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:47:10 by houkaamo          #+#    #+#             */
/*   Updated: 2026/02/06 15:19:17 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	free_and_exit(t_node *a, t_node *b, char *buffer, char *line)
{
	free(buffer);
	free(line);
	free_stack(b);
	error_exit(a, NULL);
}

static int	call_operation(char *line, t_node **a, t_node **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b);
	else
		return (0);
	return (1);
}

static int	get_next_line(t_node **a, t_node **b, char *buffer, char **line)
{
	int		size;
	char	*tmp;

	size = read(0, buffer, 1);
	while (size > 0)
	{
		buffer[size] = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, buffer);
		free(tmp);
		if (ft_strchr(*line, '\n'))
		{
			if (!call_operation(*line, a, b))
				return (-1);
			free(*line);
			*line = NULL;
		}
		size = read(0, buffer, 1);
	}
	return (1);
}

static void	read_instructions(t_node **a, t_node **b)
{
	char	*buffer;
	char	*line;

	line = NULL;
	buffer = malloc(sizeof(char) * 2);
	if (!buffer)
		free_and_exit(*a, *b, buffer, line);
	if (get_next_line(a, b, buffer, &line) == -1)
		free_and_exit(*a, *b, buffer, line);
	if (line)
		free_and_exit(*a, *b, buffer, line);
	free(buffer);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	if (ac == 1)
		return (1);
	a = parse_args(ac, av);
	b = NULL;
	read_instructions(&a, &b);
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(a);
	free_stack(b);
	return (0);
}
