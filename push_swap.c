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
	//printf("size: %d\n",size);
	if (size == 1)
		return 0;
	sorted = is_sorted(a);
	//printf("is_sorted: %d\n", sorted);
	if (sorted)
		return 0;
	//printf("stack A: Before:\n");
	//print_stack(a);
	if (size == 2)
		sa(a);
	indexing_stack(a);
	if (size > 2 && size <=	5)
		sort_small_numbers(&a, &b, size);
	//printf("stack A: After:\n");
	//print_stack(a);

	free_stack(a);
	free_stack(b);

}
