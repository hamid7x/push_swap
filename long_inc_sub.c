/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_inc_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:41:13 by houkaamo          #+#    #+#             */
/*   Updated: 2026/02/05 05:24:25 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_arrays(int *dp, int *parent)
{
	free(dp);
	free(parent);
}

static void	lis_handler(int *dp, int *parent, int *arr, t_lis *info)
{
	int	i;
	int	j;

	i = 1;
	while (i < info->arr_len)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && (dp[j] + 1) > dp[i])
			{
				dp[i] = dp[j] + 1;
				parent[i] = j;
				if (dp[i] > info->max_len)
				{
					info->max_len = dp[i];
					info->end_index = i;
				}
			}
			j++;
		}
		i++;
	}
}

int	*build_lis(int	*arr, int *parent, t_lis info)
{
	int	i;
	int	j;
	int	*lis;

	lis = malloc(sizeof(int) * info.max_len);
	if (!lis)
		return (0);
	i = info.end_index;
	j = info.max_len;
	while (i != -1)
	{
		lis[--j] = arr[i];
		i = parent[i];
	}
	return (lis);
}

void	init_arrays(int *dp, int *parent, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dp[i] = 1;
		parent[i] = -1;
		i++;
	}
}

int	*long_inc_sub(int arr[], int len, int *lis_len)
{
	t_lis	info;
	int		*dp;
	int		*parent;
	int		*lis;

	dp = malloc(sizeof(int) * len);
	parent = malloc(sizeof(int) * len);
	if (!dp || !parent)
		return (free_arrays(dp, parent), NULL);
	init_arrays(dp, parent, len);
	info.arr_len = len;
	info.max_len = 1;
	info.end_index = 0;
	lis_handler(dp, parent, arr, &info);
	*lis_len = info.max_len;
	lis = build_lis(arr, parent, info);
	if (!lis)
		return (free_arrays(dp, parent), NULL);
	free_arrays(dp, parent);
	return (lis);
}
