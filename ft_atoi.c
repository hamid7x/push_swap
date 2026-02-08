/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:24:43 by houkaamo          #+#    #+#             */
/*   Updated: 2026/02/08 11:34:41 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (sign == 1 && result > (INT_MAX - (str[i] - '0' )) / 10)
			return ((long)INT_MAX + 1);
		if (sign == -1
			&& result > (-(long)INT_MIN - (str[i] - '0' )) / 10)
			return ((long)INT_MIN - 1);
		result = result * 10 + (str[i++] - '0');
	}
	return (result * sign);
}
