#include "push_swap.h"
int	stack_size(t_node *stack)
{
	t_node	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	is_sorted(t_node *stack)
{
	t_node	*curr;
	t_node	*next;

	curr = stack;
	while(curr->next)
	{
		next = curr->next;
		if(curr->value > next->value)
			return (0);
		curr = curr->next;
	}
	return 1;

}

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
