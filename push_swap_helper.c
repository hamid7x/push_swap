#include "push_swap.h"

void	index_stack_element(t_node *stack)
{
	int		count;
	t_node	*curr;
	t_node	*tmp;

	curr = stack;
	while(curr)
	{
		tmp = stack;
		count = 0;
		while(tmp)
		{
			if (curr->value > tmp->value)
				count++;
			tmp = tmp->next;
		}
		curr->index = count;
		curr = curr->next;

	}
}

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
