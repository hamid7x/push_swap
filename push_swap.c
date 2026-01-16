#include <unistd.h>
#include "push_swap.h"


int main(int ac, char **av)
{
	t_node	*a;
	t_node	*tmp;

	if(ac == 1)
		return 0;
	a = parse_args(ac,av);
	tmp = a;
	while(tmp)
	{
		printf("%d\n",tmp->value);
		tmp = tmp->next;
	}
	free_stack(a);

}
