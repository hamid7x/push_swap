/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 09:23:59 by houkaamo          #+#    #+#             */
/*   Updated: 2026/01/18 09:24:03 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_invalid_number(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (!(s[i + 1] >= '0' && s[i + 1] <= '9'))
			return (1);
		i++;
	}
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

static int	has_duplicate(t_node *a, int n)
{
	t_node	*ptr;

	ptr = a;
	while (ptr)
	{
		if (ptr->value == n)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

static void	proccess_numbers(char **numbers, t_node **a)
{
	int			i;
	long long	n;

	i = 0;
	while (numbers[i])
	{
		if (is_invalid_number(numbers[i]))
			error_exit(*a, numbers);
		n = ft_atoi(numbers[i]);
		if (n < INT_MIN || n > INT_MAX)
			error_exit(*a, numbers);
		if (has_duplicate(*a, n))
			error_exit(*a, numbers);
		if (!add_stack_front(a, n))
			error_exit(*a, numbers);
		i++;
	}
}

t_node	*parse_args(int ac, char **av)
{
	t_node	*a;
	int		i;
	char	**numbers;

	a = NULL;
	i = 1;
	if (ac == 1)
		return (NULL);
	while (i < ac)
	{
		numbers = ft_split(av[i], ' ');
		if (!numbers || !numbers[0])
			error_exit(a, numbers);
		proccess_numbers(numbers, &a);
		free_split(numbers);
		i++;
	}
	return (a);
}
