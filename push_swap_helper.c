#include "push_swap.h"

void	print_stack(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while(tmp)
	{
		printf("%d\n",tmp->value);
		tmp = tmp->next;
	}
}
