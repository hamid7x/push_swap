/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:22:11 by houkaamo          #+#    #+#             */
/*   Updated: 2026/01/22 15:16:39 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;

	if (a > b && a > c && b > c)
	{
		sa(*stack_a);
		rra(stack_a);
	}
	else if (a < b && a < c)
	{
		sa(*stack_a);
		ra(stack_a);
	}
	else if (a > b && a > c && b < c)
		ra(stack_a);
	else if (a < b && a > c)
		rra(stack_a);
	else
		sa(*stack_a);
}

void	sort_4_or_5(t_node **stack_a, t_node **stack_b)
{
	t_node	*curr;
	int	target;
	int	i;
	
	target = 0;
	while(stack_size(*stack_a) != 3)
	{
		curr = *stack_a;
		i = 0;
		while (curr->index != target)
		{
			i++;
			curr = curr->next;
		}
		while((*stack_a)->index != target)
		{
			if (i <= (stack_size(*stack_a) / 2))
					ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		target++;
	}
	sort_3(stack_a);
	while (stack_size(*stack_b))
		pa(stack_a, stack_b);
	
}

void	sort_small_numbers(t_node **stack_a, t_node **stack_b, int size)
{
	if (size == 3)
		sort_3(stack_a);
	else
		sort_4_or_5(stack_a, stack_b);
}
