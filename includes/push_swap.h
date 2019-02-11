/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:16:13 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/05 14:16:15 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../src/libft/includes/libft.h"
# define CHECK(x) if (x == NULL) return (NULL);

typedef struct		s_node
{
	int				data;
	int				sort;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_stack
{
	int				size;
	int				flag;
	int				dir;
	t_node			*pivot;
	t_node			*top;
	t_node			*down;
}					t_stack;

t_stack				*ft_make_stack(void);
t_node				*ft_make_node(int data);
void				ft_add_node_to_stack(t_stack **stack, t_node *node);
t_node				*ft_find_n_node(int n, t_stack *stack);
t_stack				*ft_valid_check(int start, int count,
									const char **str, int flag);
void				ft_del_stack_nodes(t_stack **stack);
int					ft_swap_int(t_stack **x);
int					ft_push_int(t_stack **x, t_stack **y);
int					ft_rotate_int(t_stack **x);
int					ft_reverse_rotate_int(t_stack **x);
void				ft_swap(t_stack **x, char **com, char c);
void				ft_push(t_stack **x, t_stack **y, char **com, char c);
void				ft_rotate(t_stack **x, char **com, char c);
void				ft_reverse_rotate(t_stack **x, char **com, char c);
void				ft_sort(char **com, t_stack **x, t_stack **y);
void				ft_asc_sort3(t_stack **stack, char **com, char c);
void				ft_desc_sort3(t_stack **stack, char **com, char c);
void				ft_desc_sort(t_stack **x, t_stack **y, char **com);
void				ft_sort_a(t_stack **x, t_stack **y, char **com);
void				ft_sort_b(t_stack **x, t_stack **y, char **com);
void				ft_optimization(char **com);
int					ft_is_asc_sort(t_stack *stack);
int					ft_is_desc_sort(t_stack *stack);
int					ft_abs(int num);
int					ft_find_min(t_stack *x, int size);
int					ft_find_max(t_stack *x, int size);
void				ft_find_med_pivot(t_stack **x, char **com);
void				ft_find_pivot_a(t_stack **x, t_stack **y, char **com);
void				ft_find_pivot_b(t_stack **x, t_stack **y, char **com);
void				ft_return_pivot(t_stack **x, char **com, char c, int piv);
int					ft_find_size(t_stack *x);
int					ft_find_shift(t_stack **x, int val);
int					ft_find_median_val(t_stack *stack);
int					ft_find_position(t_stack *stack, int med);
void				ft_apply_commands(char *str, t_stack **x, t_stack **y);

#endif
