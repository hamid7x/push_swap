#include "push_swap.h"
#include <stdio.h>

int	r_rotate(t_node **stack)
{
	t_node	*curr;
	t_node	*last;

	if(!*stack || !(*stack)->next)
		return 0;
	curr = *stack;
	while(curr->next->next)
		curr = curr->next;
	last = curr->next;
	curr->next = NULL;
	last->next = *stack;
	*stack = last;
	return 1;
}

void	rra(t_node **a)
{
	if(r_rotate(a))
		write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	if(r_rotate(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	if(r_rotate(a) == 0 && r_rotate(b) == 0)
		return ;
	write(1, "rrr\n", 4);	
}
