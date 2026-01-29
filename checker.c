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

void	call_operation(char *line)
{
	if (ft_strcmp(line, "pb") == 0)
		printf("u call pb\n");
	else if (ft_strcmp(line, "pa") == 0)
		printf("u call pa\n");
	else if (ft_strcmp(line, "ra") == 0)
		printf("u call ra\n");
	else if (ft_strcmp(line, "rb") == 0)
		printf("u call rb\n");
	else if (ft_strcmp(line, "rra") == 0)
		printf("u call rra\n");
	else if (ft_strcmp(line, "rrb") == 0)
		printf("u call rrb\n");
}

void	checker()
{
	char	*buffer;
	int	size;

	buffer = malloc(sizeof(char) * 5);
	if (!buffer)
		return ;
	size = read(0, buffer, 5);
	int count = 0;
	while (size > 0)
	{
		char	*line;
		line = malloc(sizeof(char) * size);

		int i = 0;
		while (i < size - 1)
		{
			line[i] = buffer[i];
			i++;
		}
		line[i] = '\0';
		call_operation(line);
		size = read(0, buffer, 5);
	}
}
