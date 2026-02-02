/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:20:27 by houkaamo          #+#    #+#             */
/*   Updated: 2026/01/28 12:28:27 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int	size;

	if (ac == 1)
		return 0;
	a = parse_args(ac,av);
	b = NULL;

	//printf("stack A: Before\n");
	//print_stack(a);
	size = stack_size(a);
	if (size == 1)
		return 0;
	if (is_sorted(a))
		return 0;
	if (size == 2)
		sa(a);
	else if (size > 2 && size <=	5)
	{
		index_stack_element(a);
		sort_small_stack(&a, &b, size);
	}
	else
		sort_large_stack(&a, &b, size);

	//printf("stack A: After sorted:\n");
	//print_stack(a);
	free_stack(a);
	free_stack(b);
	return (0);
}
