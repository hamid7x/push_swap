/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:25:06 by houkaamo          #+#    #+#             */
/*   Updated: 2026/02/05 17:25:17 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long long	ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long long	result;

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
			return ((long long)INT_MAX + 1);
		if (sign == -1
			&& result > (-(long long)INT_MIN - (str[i] - '0' )) / 10)
			return ((long long)INT_MIN - 1);
		result = result * 10 + (str[i++] - '0');
	}
	return (result * sign);
}
