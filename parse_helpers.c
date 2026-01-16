#include "push_swap.h"

void	free_split(char **arr)
{
	if(!arr)
		return ;
	int i = 0;
	while(arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_stack(t_node *a)
{
	t_node *tmp;

	if(!a)
		return ;
	while(a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}
