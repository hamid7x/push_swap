#include <unistd.h>
#include "push_swap.h"

void	free_stack(t_node *a)
{
	t_node *curr;
	t_node *tmp;

	curr = a;
	while(curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
}

int main(int ac, char **av)
{
	t_node	*a;

	if(ac == 1)
		return 0;
	a = parse_args(ac,av);

	while(a)
	{
		printf("%d\n",a->value);
		a = a->next;
	}
	free_stack(a);

}
