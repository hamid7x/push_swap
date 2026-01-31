/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:22:56 by houkaamo          #+#    #+#             */
/*   Updated: 2026/01/31 14:49:42 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_stack_back(t_node *stack, t_node *tmp)
{
	t_node	*curr;

	tmp->next = NULL;
	curr = stack;
	while (curr->next)
		curr = curr->next;
	curr->next = tmp;
}

static void	rotate(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	push_stack_back(*stack, tmp);
}

void	ra(t_node **a)
{
	rotate(a);
}

void	rb(t_node **b)
{
	rotate(b);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
}
