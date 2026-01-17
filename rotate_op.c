#include "push_swap.h"

void	add_stack_back(t_node *stack, t_node *tmp)
{
	t_node *curr;

	tmp->next = NULL;
	curr = stack;
	while(curr->next)
		curr = curr->next;
	curr->next = tmp;
}

int	rotate(t_node **stack)
{
	t_node *tmp;

	if(!*stack || !(*stack)->next)
		return 0;
	tmp = *stack;
	*stack = (*stack)->next;
	add_stack_back(*stack, tmp);
	return 1;
}

void	ra(t_node **a)
{
	if(rotate(a))
		write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	if(rotate(b))
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate(a);
	rotated_b = rotate(b);
	if(rotated_a || rotated_b)
		write(1, "rr\n", 3);
}
