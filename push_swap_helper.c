/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:06:59 by houkaamo          #+#    #+#             */
/*   Updated: 2026/02/02 19:09:14 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack_element(t_node *stack)
{
	int		count;
	t_node	*curr;
	t_node	*tmp;

	curr = stack;
	while (curr)
	{
		tmp = stack;
		count = 0;
		while (tmp)
		{
			if (curr->value > tmp->value)
				count++;
			tmp = tmp->next;
		}
		curr->index = count;
		curr = curr->next;
	}
}

int	stack_size(t_node *stack)
{
	t_node	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	is_sorted(t_node *stack)
{
	t_node	*curr;
	t_node	*next;

	curr = stack;
	while (curr->next)
	{
		next = curr->next;
		if (curr->value > next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}
