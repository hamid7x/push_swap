/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:23:13 by houkaamo          #+#    #+#             */
/*   Updated: 2026/01/28 12:15:35 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_cost_b(t_node *curr, int pos, int size)
{
	int	cost_up;
	int	cost_down;

	cost_up = pos;
	cost_down = size - pos;
	if (cost_up <= cost_down)
	{
		curr->dir_b = 'U';
		curr->cost_b = cost_up;
	}
	else
	{
		curr->dir_b = 'D';
		curr->cost_b = cost_down;
	}
}

void	calc_cost_a(t_node *a, int value, int size, t_node *curr_b)
{
	int		target;
	int		pos;
	int		cost_up;
	int		cost_down;

	target = find_target(a, value);
	pos = get_pos_of_target(a, target);
	cost_up = pos;
	cost_down = size - pos;
	if (cost_up <= cost_down)
	{
		curr_b->dir_a = 'U';
		curr_b->cost_a = cost_up;
	}
	else
	{
		curr_b->dir_a = 'D';
		curr_b->cost_a = cost_down;
	}
}

int	max_cost(int cost_a, int cost_b)
{
	if (cost_a <= cost_b)
		return (cost_b);
	else
		return (cost_a);
}

void	calc_cost_set_rotate_dir(t_node **a, t_node **b)
{
	t_node	*tmp_b;
	int		pos;
	int		b_size;
	int		a_size;

	b_size = stack_size(*b);
	a_size = stack_size(*a);
	tmp_b = *b;
	pos = 0;
	while (tmp_b)
	{
		calc_cost_b(tmp_b, pos, b_size);
		calc_cost_a(*a, tmp_b->value, a_size, tmp_b);
		if (tmp_b->dir_a == tmp_b->dir_b)
			tmp_b->total_cost = max_cost(tmp_b->cost_a, tmp_b->cost_b);
		else
			tmp_b->total_cost = tmp_b->cost_a + tmp_b->cost_b;
		pos++;
		tmp_b = tmp_b->next;
	}
}
