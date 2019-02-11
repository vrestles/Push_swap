/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:49:23 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/05 12:49:24 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_insert_b(t_stack **x, t_stack **y, char **com)
{
	while ((*x)->top->sort != 1 && (*x)->top != (*x)->pivot)
	{
		if ((*x)->top->data > (*x)->pivot->data)
			ft_push(x, y, com, 'a');
		else
			ft_rotate(x, com, 'b');
	}
	ft_return_pivot(x, com, 'b', (*x)->pivot->data);
}

static void		ft_quick_sort_b(t_stack **x, t_stack **y, char **com)
{
	if ((*x)->pivot == NULL)
		ft_find_pivot_b(x, y, com);
	ft_insert_b(x, y, com);
	if ((*x)->top == (*x)->pivot)
	{
		(*x)->pivot->sort = 1;
		(*x)->pivot = NULL;
		ft_push(x, y, com, 'a');
	}
}

static int		ft_make_shift_b(t_stack **x, t_stack **y, char **com, int *val)
{
	int	count;
	int	shift;

	count = 0;
	shift = val[1];
	while (shift >= 0)
	{
		if ((*x)->top->data == val[0])
		{
			ft_push(x, y, com, 'a');
			if ((*x)->dir == 1)
				count--;
			break ;
		}
		else
		{
			if ((*x)->dir == 0)
				ft_rotate(x, com, 'b');
			else
				ft_reverse_rotate(x, com, 'b');
			count++;
		}
		shift--;
	}
	return (count);
}

static void		ft_kick_max_sort(t_stack **x, t_stack **y, char **com, int size)
{
	int	max;
	int	count;
	int	shift;
	int val[2];

	(*x)->dir = 0;
	if (size == 0)
		return ;
	max = ft_find_max(*x, size);
	shift = ft_find_shift(x, max);
	val[0] = max;
	val[1] = shift;
	count = ft_make_shift_b(x, y, com, val);
	while (count > 0)
	{
		if ((*x)->dir == 0)
			ft_reverse_rotate(x, com, 'b');
		else
			ft_rotate(x, com, 'b');
		count--;
	}
	ft_kick_max_sort(x, y, com, --size);
}

void			ft_sort_b(t_stack **x, t_stack **y, char **com)
{
	int	size;

	while ((*x)->top != NULL && (*x)->top->sort == 1)
		ft_push(x, y, com, 'a');
	size = ft_find_size(*x);
	if (size <= 0)
		ft_kick_max_sort(x, y, com, size);
	else
		ft_quick_sort_b(x, y, com);
}
