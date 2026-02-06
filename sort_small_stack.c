/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:29:42 by houkaamo          #+#    #+#             */
/*   Updated: 2026/02/06 12:10:59 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (is_sorted(*stack_a))
		return ;
	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && a > c && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a < b && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a > b && a > c && b < c)
		ra(stack_a);
	else if (a < b && a > c)
		rra(stack_a);
	else
		sa(stack_a);
}

static int	get_index_position(t_node *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			break ;
		pos++;
		stack = stack->next;
	}
	return (pos);
}

static void	move_index_to_top(t_node **stack, int index)
{
	int	pos;

	pos = get_index_position(*stack, index);
	while ((*stack)->index != index)
	{
		if (pos <= (stack_size(*stack) / 2))
			ra(stack);
		else
			rra(stack);
	}
}

static void	sort_4_or_5(t_node **stack_a, t_node **stack_b)
{
	int		target;

	target = 0;
	while (stack_size(*stack_a) != 3)
	{
		move_index_to_top(stack_a, target);
		pb(stack_a, stack_b);
		target++;
	}
	sort_3(stack_a);
	while (stack_size(*stack_b))
		pa(stack_a, stack_b);
}

void	sort_small_stack(t_node **stack_a, t_node **stack_b, int size)
{
	if (size == 3)
		sort_3(stack_a);
	else
		sort_4_or_5(stack_a, stack_b);
}
