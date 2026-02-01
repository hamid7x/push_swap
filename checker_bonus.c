/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:47:10 by houkaamo          #+#    #+#             */
/*   Updated: 2026/02/01 10:47:14 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

static void	call_operation(char *line, t_node **a, t_node **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(*a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(*b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(*a, *b);
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
		error_exit(*a, NULL);
}

static void	read_instructions(t_node **a, t_node **b)
{
	char	*buffer;
	char	*line;
	int		size;

	line = NULL;
	buffer = malloc(sizeof(char) * 2);
	if (!buffer)
		error_exit(*a, NULL);
	size = read(0, buffer, 1);
	while (size > 0)
	{
		buffer[size] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
		{
			call_operation(line, a, b);
			line = NULL;
		}
		size = read(0, buffer, 1);
	}
	if (line)
		error_exit(*a, NULL);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	if (ac == 1)
		return (1);
	a = parse_args(ac, av);
	b = NULL;
	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	read_instructions(&a, &b);
	if (is_sorted(a) && !b)
		printf("OK\n");
	else
		printf("KO\n");
}
