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
char		**ft_split(const char *s, char c);
long long	ft_atoi(const char *s);
void		free_split(char **arr);
void		free_stack(t_node *a);
int		add_stack_front(t_node **stack, int value);
void		print_stack(t_node *stack);

void	swap(t_node *stack);
void	sa(t_node *a);
void	sb(t_node *b);
void	ss(t_node *a, t_node *b);

void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);

void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
