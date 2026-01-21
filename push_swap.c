#include "push_swap.h"

int main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		size;
	int	sorted;

	if (ac == 1)
		return 0;
	a = parse_args(ac,av);
	b = NULL;
	size = stack_size(a);
	printf("size: %d\n",size);
	if (size == 1)
		return 0;
	sorted = is_sorted(a);
	printf("is_sorted: %d\n", sorted);
	if (sorted)
		return 0;
	if (size == 2)
		return (sa(a), 0);
	if (size <= 5)
	{
		sort_small_numbers(&a, &b, size);
		return 0;
	}

	printf("before:\n");
	printf("stack A:\n");
	print_stack(a);
		
	//test operation
	printf("operations:\n");
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	printf("stack A:\n");
	print_stack(a);
	
	printf("stack B:\n");
	print_stack(b);
	
	sa(a);

	printf("stack A:\n");
        print_stack(a);


	free_stack(a);
	free_stack(b);

}
