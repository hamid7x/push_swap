/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:34:26 by houkaamo          #+#    #+#             */
/*   Updated: 2026/02/06 11:53:39 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}

void	pb(t_node **a, t_node **b)
{
	push_to_stack(a, b);
}
