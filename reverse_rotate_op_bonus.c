/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:38:49 by houkaamo          #+#    #+#             */
/*   Updated: 2026/02/02 18:50:04 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	r_rotate(t_node **stack)
{
	t_node	*curr;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	curr = *stack;
	while (curr->next->next)
		curr = curr->next;
	last = curr->next;
	curr->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rra(t_node **a)
{
	if (!r_rotate(a))
		return ;
}

void	rrb(t_node **b)
{
	if (!r_rotate(b))
		return ;
}

void	rrr(t_node **a, t_node **b)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = r_rotate(a);
	rotated_b = r_rotate(b);
	if (!rotated_a || !rotated_b)
		return ;
}
