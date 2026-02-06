/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:20:27 by houkaamo          #+#    #+#             */
/*   Updated: 2026/02/06 15:30:56 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	if (ac == 1)
		return (0);
	a = parse_args(ac, av);
	b = NULL;
	if (stack_size(a) == 1)
		return (0);
	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	if (stack_size(a) == 2)
		sa(&a);
	else if (stack_size(a) > 2 && stack_size(a) <= 5)
	{
		index_stack_element(a);
		sort_small_stack(&a, &b, stack_size(a));
	}
	else
		sort_large_stack(&a, &b, stack_size(a));
	free_stack(a);
	return (0);
}
