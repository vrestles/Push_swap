/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:21:57 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/04 17:26:16 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_size(t_stack *x)
{
	int		size;
	t_node	*tmp;

	tmp = x->top;
	size = 0;
	while (tmp != NULL && tmp->sort == 0)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int		ft_find_shift(t_stack **x, int val)
{
	int pos;
	int shift;

	pos = ft_find_position(*x, val);
	if (pos <= ((*x)->size / 2))
		shift = pos - 1;
	else
	{
		shift = (*x)->size - pos + 1;
		(*x)->dir = 1;
	}
	return (shift);
}

int		ft_find_position(t_stack *stack, int med)
{
	t_node	*tmp;
	int		i;

	tmp = stack->top;
	i = 1;
	while (tmp != NULL)
	{
		if (tmp->data == med)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
