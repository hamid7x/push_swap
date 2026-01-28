/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:57:04 by houkaamo          #+#    #+#             */
/*   Updated: 2026/01/28 12:16:08 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_found(int arr[], int len, int value)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	get_min_nb_a(t_node *a)
{
	int	min;

	min = a->value;
	a = a->next;
	while (a)
	{
		if (min > a->value)
			min = a->value;
		a = a->next;
	}
	return (min);
}

int	get_pos_of_target(t_node *a, int target)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->value == target)
			break ;
		pos++;
		a = a->next;
	}
	return (pos);
}

int	find_target(t_node *a, int value)
{
	t_node	*tmp;
	int		target;

	target = INT_MAX;
	tmp = a;
	while (tmp)
	{
		if (tmp->value > value && tmp->value < target)
			target = tmp->value;
		tmp = tmp->next;
	}
	if (target == INT_MAX)
		return (get_min_nb_a(a));
	else
		return (target);
}

t_node	*get_cheap_element(t_node *b)
{
	t_node	*cheap;

	cheap = b;
	b = b->next;
	while (b)
	{
		if (cheap->total_cost > b->total_cost)
			cheap = b;
		b = b->next;
	}
	return (cheap);
}
