/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:22:11 by houkaamo          #+#    #+#             */
/*   Updated: 2026/01/21 13:57:59 by houkaamo         ###   ########.fr       */
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

	curr = *stack_a;
	while(curr)
	{
		//printf("index: %d\n", curr->index);
		if (!(curr->index == 0 || curr->index == 1 || curr->index == 2))
			pb(stack_a, stack_b);
		//curr = curr->next;
		printf("%d\n",curr->value);
		curr = curr->next;
	}
	print_stack(*stack_a);
}

void	sort_small_numbers(t_node **stack_a, t_node **stack_b, int size)
{
	if (size == 3)
		sort_3(stack_a);
	else
		sort_4_or_5(stack_a, stack_b);
}
