/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:31:41 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/05 12:31:43 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_find_med_pivot(t_stack **x, char **com)
{
	int	med;
	int	pos;
	int	shift;

	med = ft_find_median_val(*x);
	pos = ft_find_position(*x, med);
	if (pos <= ((*x)->size / 2))
	{
		while (pos > 0)
		{
			ft_rotate(x, com, 'a');
			pos--;
		}
	}
	else
	{
		shift = (*x)->size - pos;
		while (shift > 0)
		{
			ft_reverse_rotate(x, com, 'a');
			shift--;
		}
	}
	(*x)->pivot = (*x)->down;
}

void		ft_find_pivot_a(t_stack **x, t_stack **y, char **com)
{
	while ((*x)->top != NULL && (*x)->top->sort == 1)
		ft_push(x, y, com, 'b');
	(*x)->pivot = (*x)->top;
	ft_rotate(x, com, 'a');
}

void		ft_find_pivot_b(t_stack **x, t_stack **y, char **com)
{
	while ((*x)->top != NULL && (*x)->top->sort == 1)
		ft_push(x, y, com, 'a');
	(*x)->pivot = (*x)->top;
	ft_rotate(x, com, 'b');
}

void		ft_return_pivot(t_stack **x, char **com, char c, int piv)
{
	int	pos;
	int	shift;

	pos = ft_find_position(*x, piv);
	if (pos <= ((*x)->size / 2))
	{
		while ((pos - 1) > 0)
		{
			ft_rotate(x, com, c);
			pos--;
		}
	}
	else
	{
		shift = (*x)->size - pos + 1;
		while (shift > 0)
		{
			ft_reverse_rotate(x, com, c);
			shift--;
		}
	}
}
