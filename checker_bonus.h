/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houkaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:50:00 by houkaamo          #+#    #+#             */
/*   Updated: 2026/02/07 16:30:14 by houkaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_lis
{
	int	*arr;
	int	*tails;
	int	tails_indx;
	int	*parent;
	int	*lis_len;
	int	size;
}	t_li;

t_node		*parse_args(int ac, char **av);
char		**ft_split(const char *s, char c);
char		*ft_strjoin(const char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
long		ft_atoi(const char *s);
void		free_split(char **arr);
void		free_stack(t_node *stack);
int			add_stack_back(t_node **stack, int value);
void		error_exit(t_node *stack, char **arr);
int			is_sorted(t_node *stack);
int			ft_strcmp(const char *s1, const char *s2);

void		sa(t_node **a);
void		sb(t_node **b);
void		ss(t_node **a, t_node **b);

void		pa(t_node **a, t_node **b);
void		pb(t_node **a, t_node **b);

void		ra(t_node **a);
void		rb(t_node **b);
void		rr(t_node **a, t_node **b);

void		rra(t_node **a);
void		rrb(t_node **b);
void		rrr(t_node **a, t_node **b);

#endif
