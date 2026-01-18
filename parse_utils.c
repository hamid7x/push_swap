/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 09:37:25 by houkaamo          #+#    #+#             */
/*   Updated: 2026/01/18 12:19:40 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_node *stack, char **arr)
{
	free_split(arr);
	free_stack(stack);
	write(1, "Error\n", 6);
	exit(0);
}

int	add_stack_back(t_node **stack, int value)
{
	t_node	*new;
	t_node	*curr;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->value = value;
	new->next = NULL;
	if (!*stack)
		*stack = new;
	else
	{
		curr = *stack;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
	return (1);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_stack(t_node *a)
{
	t_node	*tmp;

	if (!a)
		return ;
	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}
