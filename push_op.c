#include "push_swap.h"

void	push_to_stack(t_node **stack, t_node **dest)
{
	t_node	*first;
	
	first = *stack;
	*stack = (*stack)->next;
	first->next = *dest;
	*dest = first;	
}

void	pa(t_node **a, t_node **b)
{
	t_node	*tmp;

	if(!*b)
		return ;
	push_to_stack(b, a); 
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*tmp;

	if(!*a)
		return ;
	push_to_stack(a, b);
	write(1, "pb\n", 3);
}

