/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:44:45 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/05 12:44:47 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_insert_a(t_stack **x, t_stack **y, char **com)
{
	while ((*x)->top->sort != 1 && (*x)->top != (*x)->pivot)
	{
		if ((*x)->top->data < (*x)->pivot->data)
			ft_push(x, y, com, 'b');
		else
			ft_rotate(x, com, 'a');
	}
	ft_return_pivot(x, com, 'a', (*x)->pivot->data);
}

static void		ft_quick_sort_a(t_stack **x, t_stack **y, char **com)
{
	if ((*x)->pivot == NULL)
	{
		if ((*x)->flag == 1)
			ft_find_med_pivot(x, com);
		else
			ft_find_pivot_a(x, y, com);
	}
	ft_insert_a(x, y, com);
	if ((*x)->top == (*x)->pivot)
	{
		(*x)->pivot->sort = 1;
		(*x)->pivot = NULL;
		ft_push(x, y, com, 'b');
	}
}

static int		ft_make_shift_a(t_stack **x, t_stack **y, char **com, int *val)
{
	int	count;
	int shift;

	count = 0;
	shift = val[1];
	while (shift >= 0)
	{
		if ((*x)->top->data == val[0])
		{
			ft_push(x, y, com, 'b');
			if ((*x)->dir == 1)
				count--;
			break ;
		}
		else
		{
			if ((*x)->dir == 0)
				ft_rotate(x, com, 'a');
			else
				ft_reverse_rotate(x, com, 'a');
			count++;
		}
		shift--;
	}
	return (count);
}

static void		ft_kick_min_sort(t_stack **x, t_stack **y, char **com, int size)
{
	int	min;
	int	count;
	int	shift;
	int val[2];

	(*x)->dir = 0;
	if (size == 0)
		return ;
	min = ft_find_min(*x, size);
	shift = ft_find_shift(x, min);
	val[0] = min;
	val[1] = shift;
	count = ft_make_shift_a(x, y, com, val);
	while (count > 0)
	{
		if ((*x)->dir == 0)
			ft_reverse_rotate(x, com, 'a');
		else
			ft_rotate(x, com, 'a');
		count--;
	}
	ft_kick_min_sort(x, y, com, --size);
}

void			ft_sort_a(t_stack **x, t_stack **y, char **com)
{
	int	size;

	while ((*x)->top != NULL && (*x)->top->sort == 1)
		ft_push(x, y, com, 'b');
	size = ft_find_size(*x);
	if (size <= 20)
		ft_kick_min_sort(x, y, com, size);
	else
		ft_quick_sort_a(x, y, com);
}
