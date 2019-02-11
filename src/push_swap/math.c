/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:24:29 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/05 12:24:31 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_abs(int num)
{
	if (num < 0)
		return ((-1) * num);
	return (num);
}

static int		ft_sum(t_stack *stack)
{
	t_node	*tmp;
	int		res;

	tmp = stack->top;
	res = 0;
	while (tmp != NULL)
	{
		res += tmp->data;
		tmp = tmp->next;
	}
	return (res);
}

int				ft_find_median_val(t_stack *stack)
{
	int		sum;
	int		avg;
	int		diff;
	int		pos;
	t_node	*tmp;

	sum = ft_sum(stack);
	avg = sum / stack->size;
	tmp = stack->top;
	diff = ft_abs(avg - tmp->data);
	pos = tmp->data;
	while (tmp != NULL)
	{
		if (ft_abs(avg - tmp->data) < diff)
		{
			diff = ft_abs(avg - tmp->data);
			pos = tmp->data;
		}
		tmp = tmp->next;
	}
	return (pos);
}

int				ft_find_max(t_stack *x, int size)
{
	int		max;
	t_node	*tmp;

	tmp = x->top;
	max = tmp->data;
	while (size > 0 && tmp != NULL)
	{
		if (tmp->data > max)
			max = tmp->data;
		size--;
		tmp = tmp->next;
	}
	return (max);
}

int				ft_find_min(t_stack *x, int size)
{
	int		min;
	t_node	*tmp;

	tmp = x->top;
	min = tmp->data;
	while (size > 0 && tmp != NULL)
	{
		if (tmp->data < min)
			min = tmp->data;
		size--;
		tmp = tmp->next;
	}
	return (min);
}
