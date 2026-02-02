/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 10:54:06 by houkaamo          #+#    #+#             */
/*   Updated: 2026/01/18 10:59:19 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

long long	ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (is_space(str[i]))
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
