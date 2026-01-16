#include "push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*new;
	t_node	*tmp;

	if(!*b)
		return ;
	add_stack_front(a, (*b)->value);
	tmp = *b;
	*b = (*b)->next;
	 free(tmp);
	 write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*new;
	t_node	*tmp;

	if(!*a)
		return ;
	add_stack_front(b, (*a)->value);

	tmp = *a;
	*a = (*a)->next;
	free(tmp);
	write(1, "pb\n", 3);
}

