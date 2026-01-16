#include <unistd.h>
#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	t_node	*tmp;

	if(ac == 1)
		return 0;
	a = parse_args(ac,av);
	b = NULL;
	
	printf("before:\n");
	printf("stack A:\n");
	print_stack(a);

	//test operation
	printf("operations:\n");
	pb(&a, &b);
	pb(&a, &b);
	sb(b);
	pb(&a, &b);
	sb(b);
	pa(&a, &b);
	sb(b);
	pa(&a, &b);
	pa(&a, &b);	
	
	printf("stack A:\n");
	print_stack(a);

	printf("stack B:\n");
	print_stack(b);



	free_stack(a);
	free_stack(b);

}
