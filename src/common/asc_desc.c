/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asc_desc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:33:14 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/04 15:40:42 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_is_asc_sort(t_stack *stack)
{
	t_node	*tmp;
	int		n;
	int		i;

	tmp = NULL;
	if (stack == NULL || stack->size == 0)
		return (1);
	tmp = stack->top;
	n = tmp->data;
	i = 1;
	tmp = tmp->next;
	while (tmp)
	{
		if (n < tmp->data)
		{
			n = tmp->data;
			i++;
		}
		else
			break ;
		tmp = tmp->next;
	}
	if (stack->size == i)
		return (1);
	return (0);
}

int				ft_is_desc_sort(t_stack *stack)
{
	t_node	*tmp;
	int		n;
	int		i;

	tmp = NULL;
	if (stack == NULL || stack->size == 0)
		return (1);
	tmp = stack->top;
	n = tmp->data;
	i = 1;
	tmp = tmp->next;
	while (tmp)
	{
		if (n > tmp->data)
		{
			n = tmp->data;
			i++;
		}
		else
			break ;
		tmp = tmp->next;
	}
	if (stack->size == i)
		return (1);
	return (0);
}
