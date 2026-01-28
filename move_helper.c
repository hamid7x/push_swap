/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:13:53 by houkaamo          #+#    #+#             */
/*   Updated: 2026/01/28 12:15:53 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both_stacks(t_node **a, t_node **b, t_node *el)
{
	while (el->cost_a && el->cost_b)
	{
		if (el->dir_a == 'U')
			rr(a, b);
		else
			rrr(a, b);
		el->cost_a--;
		el->cost_b--;
	}
}

void	move_to_top(t_node **a, t_node **b, t_node *el)
{
	if (el->dir_a == el->dir_b)
		rotate_both_stacks(a, b, el);
	while (el->cost_a)
	{
		if (el->dir_a == 'U')
			ra(a);
		else
			rra(a);
		el->cost_a--;
	}
	while (el->cost_b)
	{
		if (el->dir_b == 'U')
			rb(b);
		else
			rrb(b);
		el->cost_b--;
	}
}

void	push_cheapest_to_a(t_node **a, t_node **b)
{
	t_node	*element;

	element = get_cheap_element(*b);
	move_to_top(a, b, element);
	pa(a, b);
}
