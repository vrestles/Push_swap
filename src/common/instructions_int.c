/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:11:30 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/05 12:11:33 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_swap_int(t_stack **x)
{
	t_node	*left;
	t_node	*right;

	if ((*x)->size < 2 || (*x) == NULL)
		return (0);
	left = (*x)->top;
	right = (*x)->top->next;
	left->next = right->next;
	if (right->next != NULL)
		left->next->prev = left;
	right->next = left;
	left->prev = right;
	right->prev = NULL;
	(*x)->top = right;
	if ((*x)->size == 2)
		((*x)->down) = left;
	return (1);
}

int			ft_push_int(t_stack **x, t_stack **y)
{
	t_node *tmp;

	if ((*x)->size == 0 || (*x) == NULL)
		return (0);
	tmp = (*x)->top;
	if ((*x)->size == 1)
	{
		(*x)->top = NULL;
		(*x)->down = NULL;
	}
	else
	{
		(*x)->top = tmp->next;
		(*x)->top->prev = NULL;
	}
	(*x)->size -= 1;
	tmp->prev = NULL;
	tmp->next = NULL;
	ft_add_node_to_stack(y, tmp);
	return (1);
}

int			ft_rotate_int(t_stack **x)
{
	t_node *tmp;

	if ((*x)->size < 2 || (*x) == NULL)
		return (0);
	tmp = (*x)->top;
	(*x)->down->next = tmp;
	tmp->prev = (*x)->down;
	(*x)->top = tmp->next;
	(*x)->top->prev = NULL;
	tmp->next = NULL;
	(*x)->down = tmp;
	return (1);
}

int			ft_reverse_rotate_int(t_stack **x)
{
	t_node *tmp;

	if ((*x)->size < 2 || (*x) == NULL)
		return (0);
	tmp = (*x)->down;
	(*x)->down = tmp->prev;
	(*x)->down->next = NULL;
	tmp->next = (*x)->top;
	(*x)->top->prev = tmp;
	(*x)->top = tmp;
	tmp->prev = NULL;
	return (1);
}
