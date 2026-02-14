/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:47:48 by houkaamo          #+#    #+#             */
/*   Updated: 2026/02/14 19:40:19 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_sorted(t_node *stack)
{
	t_node	*curr;
	t_node	*next;
	
	if (!stack)
		return (0);
	curr = stack;
	while (curr->next)
	{
		next = curr->next;
		if (curr->value > next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			return ((char *)(s + i));
		i++;
	}
	if ((unsigned char) c == '\0')
		return ((char *)s + i);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}
