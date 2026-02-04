/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_inc_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:41:13 by houkaamo          #+#    #+#             */
/*   Updated: 2026/02/04 18:13:09 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*long_inc_sub(int arr[], int len, int *lis_len)
{
	int	*dp;
	int	*parent;
	int		max_len;
	int		end_lis_index;
	int		i;
	int		j;
	int	*lis;

	dp = malloc(sizeof(int) * len);
	parent = malloc(sizeof(int) * len);
	if (!dp || !parent)
		return (0);
	i = 0;
	while (i < len)
	{
		dp[i] = 1;
		parent[i] = -1;
		i++;
	}

	i = 1;
	max_len = dp[0];
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && (dp[j] + 1) > dp[i])
			{
				dp[i] = dp[j] + 1;
				parent[i] = j;
				if (dp[i] > max_len)
				{	
					max_len = dp[i];
					end_lis_index = i;
				}
			}
			j++;
		}
		i++;
	}
	lis = malloc(sizeof(int) * max_len);

	curr = end_lis_index;
	i = max_len;
	while (curr != -1)
	{
		lis[--i] = arr[curr];
		curr = parent[curr];	
	}
	*lis_len = max_len;
	free(dp);
	free(parent);
	return lis;
}
