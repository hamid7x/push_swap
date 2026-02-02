#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int	value;
	int	index;
	int	cost_a;
	int	cost_b;
	int	total_cost;
	char	dir_b;
	char	dir_a;
	struct s_node *next;
}	t_node;

typedef struct s_lis
{
	int	*arr;
	int	*tails;
	int	*tails_indx;
	int	*parent;
	int	*lis_len;
	int	size;
}	t_lis;

t_node	*parse_args(int ac, char **av);
char		**ft_split(const char *s, char c);
long long	ft_atoi(const char *s);
void		free_split(char **arr);
void		free_stack(t_node *a);
int		add_stack_back(t_node **stack, int value);
void		print_stack(t_node *stack);
void		error_exit(t_node *stack, char **arr);

void	index_stack_element(t_node *stack);
int	stack_size(t_node *stack);
int	is_sorted(t_node *stack);
void	sort_small_stack(t_node **stack_a, t_node **stack_b, int size);
void	sort_large_stack(t_node **a, t_node **b, int size);
int	long_inc_sub(int arr[], int size, int lis[], int *lis_len);

int	*ft_malloc_array(int size);
void	free_arrays(t_lis *data);
void	reverse_lis(int *lis, int len);

void	calc_cost_set_rotate_dir(t_node **a, t_node **b);
void	calc_cost_a(t_node *a, int value, int size, t_node *curr_b);
void	calc_cost_b(t_node *curr, int pos, int size);
int	get_pos_of_target(t_node *a, int target);
int	max_cost(int cost_up, int cost_down);

int	find_target(t_node *a, int value);
int	get_pos_of_target(t_node *a, int target);
int	get_min_nb_a(t_node *a);
int	is_found(int arr[], int len, int value);
t_node	*get_cheap_element(t_node*b);

void	push_cheapest_to_a(t_node **a, t_node **b);
void	move_to_top(t_node **a, t_node **b, t_node *el);
void	rotate_both_stacks(t_node **a, t_node **b, t_node *el);

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

#endif
