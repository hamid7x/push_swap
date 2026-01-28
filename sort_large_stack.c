/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 12:12:50 by houkaamo          #+#    #+#             */
/*   Updated: 2026/01/28 12:12:54 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_stack_to_array(t_node *stack, int arr[])
{
	t_node	*curr;
	int		i;

	curr = stack;
	i = 0;
	while (curr)
	{
		arr[i] = curr->value;
		curr = curr->next;
		i++;
	}
}

void	rotate_min_to_top(t_node **a, int size)
{
	int		min;

	min = get_min_nb_a(*a);
	while ((*a)->value != min)
	{
		if (get_pos_of_target(*a, min) <= (size / 2))
			ra(a);
		else
			rra(a);
	}
}

void	push_non_lis_to_b(t_node **a, t_node **b, int *lis, int lis_len)
{
	int		size;
	int		i;

	size = stack_size(*a);
	i = 0;
	while (i < size)
	{
		if (is_found(lis, lis_len, (*a)->value))
			ra(a);
		else
			pb(a, b);
		i++;
	}
}

void	push_all_b_to_a(t_node **a, t_node **b)
{
	while (*b)
	{
		calc_cost_set_rotate_dir(a, b);
		push_cheapest_to_a(a, b);
	}
}

void	sort_large_stack(t_node **a, t_node **b, int size)
{
	int	*arr;
	int	*lis;
	int	lis_len;

	arr = malloc(size * sizeof(int));
	if (!arr)
		error_exit(*a, NULL);
	lis = malloc(size * sizeof(int));
	if (!lis)
	{
		free(arr);
		error_exit(*a, NULL);
	}
	copy_stack_to_array(*a, arr);
	if (!long_inc_sub(arr, size, lis, &lis_len))
	{
		free(arr);
		free(lis);
		error_exit(*a, NULL);
	}
	push_non_lis_to_b(a, b, lis, lis_len);
	push_all_b_to_a(a, b);
	rotate_min_to_top(a, size);
	free(arr);
	free(lis);
}
