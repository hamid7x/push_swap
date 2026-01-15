#include <unistd.h>
#include "push_swap.h"


int main(int ac, char **av)
{
	t_node	*a;

	if(ac == 1)
		return 0;
	a = parse_args(ac,av);
	printf("hi");
	while(a)
	{
		printf("%d\n",a->value);
		a = a->next;
	}

}
