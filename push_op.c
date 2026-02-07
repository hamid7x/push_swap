/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:21:49 by houkaamo          #+#    #+#             */
/*   Updated: 2026/02/07 16:26:45 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_stack(t_node **stack, t_node **dest)
{
	t_node	*first;

	if (!stack || !*stack || !dest)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = *dest;
	*dest = first;
}

void	pa(t_node **a, t_node **b)
{
	push_to_stack(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push_to_stack(a, b);
	write(1, "pb\n", 3);
}
