#include "push_swap.h"

int    add_stack_front(t_node **stack, int value)
{
         t_node *new;

         new = malloc(sizeof(t_node));
         if (!new)
		 return (0);
	 new->value = value;
         new->next = *stack;
         *stack = new;
	 return (1);
}

void	free_split(char **arr)
{
	int	i;

	if(!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_stack(t_node *a)
{
	t_node *tmp;

	if (!a)
		return ;
	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}
