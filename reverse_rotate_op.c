/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:24:34 by houkaamo          #+#    #+#             */
/*   Updated: 2026/01/25 15:32:25 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_rotate(t_node **stack)
{
	t_node	*curr;
	t_node	*last;

	if (!*stack || !(*stack)->next)
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
	if (r_rotate(a))
		write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	if (r_rotate(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	int	a_rotated;
	int	b_rotated;

	a_rotated = r_rotate(a);
	b_rotated = r_rotate(b);
	if (a_rotated || b_rotated)
		write(1, "rrr\n", 4);
}
