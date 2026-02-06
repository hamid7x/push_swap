/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:47:24 by houkaamo          #+#    #+#             */
/*   Updated: 2026/02/05 16:47:38 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (counter);
}

static void	free_memory(char **arr, int n)
{
	while (n--)
		free(arr[n]);
	free(arr);
}

static char	*get_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static int	fill_arr(char **arr, const char *s, char c)
{
	int	start;
	int	i;
	int	arr_i;

	i = 0;
	arr_i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			arr[arr_i] = get_word(s, start, i);
			if (!arr[arr_i])
				return (free_memory(arr, arr_i), 0);
			arr_i++;
		}
	}
	arr[arr_i] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	if (!fill_arr(arr, s, c))
		return (NULL);
	return (arr);
}
