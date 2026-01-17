#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	error_exit(t_node *a, char **numbers)
{
	free_split(numbers);
	free_stack(a);
	write(2, "Error\n", 6);
	exit(0);
}

int is_invalid_number(char *s)
{
	 int i = 0;
	 while(s[i] == ' ')
		 i++;
	 if(s[i] == '-' || s[i] == '+')
	 {
	 	if(!(s[i+1] >= '0' && s[i + 1] <= '9'))
			return 1;
		i++;
	 }
	 while(s[i])
	{
		if(!(s[i] >= '0' && s[i] <= '9'))
			return 1;
		i++;
	}	
	return 0;
}

int has_duplicate(t_node *a, int n)
{
	t_node *ptr;

	ptr = a;
	while(ptr)
	{
		if(ptr->value == n)
			return 1;
		ptr = ptr->next;
	}
	return 0;
}

t_node *parse_args(int ac, char **av)
{
	t_node *a;
	int		i;
	int		j;
	char	**numbers;
	long long	n;

	a = NULL;
	i = 1;
	if(ac == 1)
		return NULL;
	while (i < ac)
	{
		numbers = ft_split(av[i], ' ');
		if(!numbers || !numbers[0])
			error_exit(a, numbers);
		j = 0;
		while(numbers[j])
		{
			if(is_invalid_number(numbers[j]))
				error_exit(a, numbers);
			n = ft_atoi(numbers[j]);
			if(n < INT_MIN || n > INT_MAX)
				error_exit(a, numbers);
			if(has_duplicate(a, n))
				error_exit(a, numbers);
			if(!add_stack_front(&a, n))
				error_exit(a, numbers);
			j++;		
		}
		free_split(numbers);	
		i++;
	}
	return a;
}
