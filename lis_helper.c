/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:19:06 by houkaamo          #+#    #+#             */
/*   Updated: 2026/01/27 16:24:01 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_malloc_array(int size)
{
	int	*arr;

	arr = malloc(size * sizeof(int));
	return (arr);
}

void	free_arrays(t_lis *data)
{
	free(data->tails);
	free(data->tails_indx);
	free(data->parent);
}

void	reverse_lis(int *lis, int len)
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
