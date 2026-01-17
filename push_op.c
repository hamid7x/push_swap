#include "push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*tmp;

	if(!*b)
		return ;
	if(!add_stack_front(a, (*b)->value))
	{
		free_stack(a);
		free_stack(b);
		exit(1);
	}
	tmp = *b;
	*b = (*b)->next;
	 free(tmp);
	 write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*tmp;

	if(!*a)
		return ;
	if(!add_stack_front(b, (*a)->value))
	{
		free_stack(a);
		free_stack(b);
		exit(1);
	}

	tmp = *a;
	*a = (*a)->next;
	free(tmp);
	write(1, "pb\n", 3);
}

