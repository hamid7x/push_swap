#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	error_exit()
{
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
void	add_stack_back(t_node **a, int value)
{
	 t_node *new;

	 new = malloc(sizeof(t_node));
	 new->value = value;
	 new->next = NULL;
	 t_node *curr = *a;
	 if(*a == NULL)
		*a = new;
	 else
         {
	 	while(curr->next)
			curr = curr->next;
		curr->next = new;
	 }
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
void	free_split(char **arr, int j)
{
	int i = 0;
	while(i < j)
		free(arr[i++]);
	free(arr);
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
			error_exit();
		j = 0;
		while(numbers[j])
		{
			if(is_invalid_number(numbers[j]))
				error_exit();
			n = ft_atoi(numbers[j]);
			if(n < INT_MIN || n > INT_MAX)
				error_exit();
			if(has_duplicate(a, n))
				error_exit();
			add_stack_back(&a, n);
			j++;		
		}
		free_split(numbers, j);	
		i++;
	}
	return a;
}
