/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:38:49 by houkaamo          #+#    #+#             */
/*   Updated: 2026/01/31 14:50:17 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap_bonus.h"

void	r_rotate(t_node **stack)
{
	t_node	*curr;
	t_node	*last;

	curr = *stack;
	while (curr->next->next)
		curr = curr->next;
	last = curr->next;
	curr->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_node **a)
{
	r_rotate(a);
}

void	rrb(t_node **b)
{
	r_rotate(b);
}

void	rrr(t_node **a, t_node **b)
{
	r_rotate(a);
	r_rotate(b);
}
