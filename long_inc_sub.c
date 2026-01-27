/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_inc_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:39:08 by houkaamo          #+#    #+#             */
/*   Updated: 2026/01/27 14:20:19 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	binary_search(int tails[], int value, int size)
{
	int	start;
	int	end;
	int	mid;

	start = 0;
	end = size;
	while (start < end)
	{
		mid = (start + end) / 2;
		if (tails[mid] > value)
			end = mid;
		else
			start = mid + 1;
	}
	return (start);
}

void	reverse_lis(int lis[], int len)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < len / 2)
	{
		tmp = lis[i];
		lis[i] = lis[len - i - 1];
		lis[len - i - 1] = tmp;
		i++;
	}
}

void	build_lis(int arr[], int lis[], int parent[], int last_index)
{
	int	i;

	i = 0;
	while (last_index != -1)
	{
		lis[i] = arr[last_index];
		last_index = parent[last_index];
		i++;
	}
	reverse_lis(lis, i);
}

void free_arrays(int *tails, int *tails_indx, int *parent)
{
	free(tails);
	free(tails_indx);
	free(parent);
}

int	*ft_malloc_array(int size)
{
	int	*arr;

	arr = malloc(size * sizeof(int));
	return (arr);
}

int	*allocate_arrays(int size, int **tails_indx, int **parent)
{
	int	*tails;

	tails = ft_malloc_array(size);
	*tails_indx = ft_malloc_array(size);
	*parent = ft_malloc_array(size);
	if (!tails || !*tails_indx || !*parent)
	{	
		free_arrays(tails, *tails_indx, *parent);
		return (0);
	}
	return (tails);
}
void	init_arrays(t_lis *data)
{
	data->tails[0] = data->arr[0];
	data->tails_indx[0] = 0;
	data->parent[0] = -1;
	*data->lis_len = 1;
}

static void	lis_handler(t_lis *data)
{
	int	pos;
	int	i;

	i = 1;
	while(i < data->size)
	{
		pos = binary_search(data->tails, data->arr[i], *data->lis_len);
		data->tails[pos] = data->arr[i];
		data->tails_indx[pos] = i;
		if (pos > 0)
			data->parent[i] = data->tails_indx[pos - 1];
		else
			data->parent[i] = -1;
		if (pos == *data->lis_len)
			(*data->lis_len)++;
		i++;
	}
}

void	long_inc_sub(int arr[], int size, int lis[], int *lis_len)
{
	t_lis	data;
	int	last_index;

	data.arr = arr;
	data.size = size;
	data.lis_len = lis_len;
	data.tails = allocate_arrays(data.size, &data.tails_indx, &data.parent);
	if (!data.tails)
		return ;
	init_arrays(&data);
	//data.tails[0] = data.arr[0];
	lis_handler(&data);
	last_index = data.tails_indx[*lis_len - 1];
	build_lis(data.arr, lis, data.parent, last_index);
	free_arrays(data.tails, data.tails_indx, data.parent);
}
