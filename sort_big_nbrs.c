/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_nbrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:22:34 by houkaamo          #+#    #+#             */
/*   Updated: 2026/01/25 13:00:10 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	convert_to_arr(t_node *stack, int arr[])
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

int	is_found(int arr[], int size, int value)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return 1;
		i++;
	}
	return 0;
}

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

int	min_element(int list[], int len)
{
	int	i;
	int	min;

	min = list[0];
	i = 1;
	while(i < len)
	{
		if (list[i] < min)
			min = list[i];
		i++;
	}
	return (min);
}

int get_min_nb_a(t_node *a)
{
	t_node	*tmp;
	int	min;

	min = a->value;
	tmp = a->next;
	while(tmp)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	find_target(t_node *a, int value, int size)
{
	int	flag;
	t_node	*tmp;
	int	list[size];
	int	list_len;

	tmp = a;
	flag = 0;
	list_len = 0;
	while(tmp)
	{
		if (tmp->value > value)
		{
			list[list_len] = tmp->value;
			list_len++;
			flag = 1;
		}
		tmp = tmp->next;
	}
	if (!flag)
		return (get_min_nb_a(a));
	else
		return (min_element(list, list_len));

}

void	calc_cost_a(t_node *a, int value, int size, t_node *curr_b)
{
	int	target;
	int	pos;
	int	cost_up;
	int	cost_down;
	t_node	*tmp;

	target = find_target(a, value, size);
	tmp = a;
	pos = 0;
	while (tmp)
	{
		if (tmp->value == target)
			break ;
		pos++;
		tmp = tmp->next;
	}
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
void	calc_cost_set_R_dir(t_node **a, t_node **b)
{
	t_node	*tmp_b;
	int	i;
	int 	pos;
	int	b_size;
	int	a_size;

	b_size = stack_size(*b);
	a_size = stack_size(*a);
	i = 0;
	tmp_b = *b;
	pos = 0;
	while(i < b_size)
	{
		calc_cost_b(tmp_b, pos, b_size);
		calc_cost_a(*a, tmp_b->value, a_size, tmp_b);
		if (tmp_b->dir_a == tmp_b->dir_b)
			tmp_b->total_cost = max_cost(tmp_b->cost_a, tmp_b->cost_b);
		else
			tmp_b->total_cost = tmp_b->cost_a + tmp_b->cost_b;
		//printf("%d->%d\n",tmp_b->value,tmp_b->total_cost);
		i++;
		pos++;
		tmp_b = tmp_b->next;
	}
}

t_node	*get_cheap_element(t_node *b)
{
	t_node	*cheap;
	t_node	*tmp;

	cheap = b;
	tmp = b->next;
	while (tmp)
	{
		if (cheap->total_cost > tmp->total_cost)
			cheap = tmp;
		tmp = tmp->next;
	}
	return (cheap);
}

void	take_to_top(t_node **stack, char dir, int cost)
{
	while (cost)
	{
		if (dir == 'U')
			rb(stack);
		else
			rrb(stack);
		cost--;
	}
}

void	push_back_to_a(t_node **a, t_node **b)
{
	t_node	*element;

	element = get_cheap_element(*b);
	//printf("el->%d\n",element->value);
	take_to_top(b, element->dir_b, element->cost_b);
	//target = find_target(*a, element->value, size);
	take_to_top(a, element->dir_a, element->cost_a);
	pa(a, b);
}

void	rotate_untill_sorted(t_node **a, int size)
{
	int	min;
	int	i;
	t_node	*tmp;

	min = get_min_nb_a(*a);
	tmp = *a;
	i = 0;
	while (tmp)
	{
		if (tmp->value ==  min)
			break ;
		tmp = tmp->next;
		i++;
	}
	tmp = *a;
	while (tmp->value != min)
	{
		if (i <= (size / 2))
			ra(a);
		else
			rra(a);
		tmp = *a;
	}

}

void	sort_big_numbers(t_node **a, t_node **b, int size)
{
	t_node	*curr;
	int	arr[size];
	int	lis[size];
	int	lis_len;
	int	i;

	convert_to_arr(*a, arr);
	long_inc_subs(arr,size, lis, &lis_len);
	printf("lis list:\n");
	for(int i = 0; i < lis_len; i++)
		printf("%d ",lis[i]);
	printf("\n");
	curr = *a;
	i = 0;
	while(i < size)
	{
		if (is_found(lis, lis_len, curr->value))
			ra(a);
		else
			pb(a,b);
		curr =*a;
		i++;
	}
	printf("stack A: after lis\n");
	print_stack(*a);
	printf("stack B: after lis\n");
	print_stack(*b);
	while (stack_size(*b) != 0)
	{
		calc_cost_set_R_dir(a,b);
		push_back_to_a(a, b);
	}
	rotate_untill_sorted(a, size);
	printf("stack A: after sort\n");
	print_stack(*a);
	printf("Stack B: after\n");
	print_stack(*b);
}
