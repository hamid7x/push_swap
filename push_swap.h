#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_node
{
	int	value;
	struct s_node *next;
} t_node;

t_node *parse_args(int ac, char **av);
char	**ft_split(const char *s, char c);
long long		ft_atoi(const char *s);
