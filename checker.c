#include "push_swap.h"
#include <string.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}

void	call_operation(char *line, t_node **a, t_node **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(*a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(*b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(*a, *b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b);
	else
		error_exit(*a, NULL);
}

void	checker(t_node **a, t_node **b)
{
	char	*buffer;
	int	size;
	char	*stash;
	char	*line;
	
	line = NULL;
	buffer = malloc(sizeof(char) * 2);
	if (!buffer)
		return ;
	size = read(0, buffer, 1);
	while (size > 0)
	{
		buffer[size] = '\0';
		line = ft_strjoin(line, buffer);
		if (strchr(line, '\n'))
		{
			call_operation(line, a, b);
			line = NULL;
		}
		size = read(0, buffer, 1);
	}
	if (line != NULL)
		error_exit(*a, NULL);
	printf("Stack A:\n");
	print_stack(*a);
	printf("Stack B:\n");
	print_stack(*b);
	
	if (is_sorted(*a) && !*b)
		printf("OK\n");
	else
		printf("KO\n");
}
