/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:59:04 by houkaamo          #+#    #+#             */
/*   Updated: 2026/02/02 18:53:27 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
		dup[j++] = s[i++];
	dup[j] = '\0';
	return (dup);
}

static char	*null_handler(char const *s1, char const *s2)
{
	if (!s1)
		return (ft_strdup(s2));
	return (ft_strdup(s1));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (null_handler(s1, s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1_len--)
		str[i++] = s1[j++];
	j = 0;
	while (s2_len--)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
