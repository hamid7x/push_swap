/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 12:22:56 by houkaamo          #+#    #+#             */
/*   Updated: 2026/02/07 16:27:37 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	push_stack_back(t_node *stack, t_node *tmp)
{
	t_node	*curr;

	tmp->next = NULL;
	curr = stack;
	while (curr->next)
		curr = curr->next;
	curr->next = tmp;
}

static int	rotate(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	push_stack_back(*stack, tmp);
	return (1);
}

void	ra(t_node **a)
{
	if (!rotate(a))
		return ;
}

void	rb(t_node **b)
{
	if (!rotate(b))
		return ;
}	

void	rr(t_node **a, t_node **b)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate(a);
	rotated_b = rotate(b);
	if (!rotated_a || !rotated_b)
		return ;
}
