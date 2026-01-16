#include "push_swap.h"

void	swap(t_node *stack)
{
	int	tmp;
	
	if(!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}


void	sa(t_node *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_node *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_node *a, t_node *b)
{
	swap(a);
	swap(b);
	write(1, "sa\nsb\n",6);
}
