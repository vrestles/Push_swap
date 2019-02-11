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

void			ft_desc_sort(t_stack **x, t_stack **y, char **com)
{
	while ((*x)->size != 0)
	{
		ft_reverse_rotate(x, com, 'a');
		ft_push(x, y, com, 'b');
	}
	while ((*y)->size != 0)
		ft_push(y, x, com, 'a');
}

void			ft_asc_sort3(t_stack **stack, char **com, char c)
{
	void	(*mix[4])(t_stack **stack, char **com, char c);
	int		i;
	t_node	*tmp;

	mix[0] = ft_swap;
	mix[1] = ft_rotate;
	mix[2] = ft_swap;
	mix[3] = ft_reverse_rotate;
	i = 0;
	while (ft_is_asc_sort(*stack) == 0)
	{
		mix[i](stack, com, c);
		i++;
		if (i == 4)
			i = 0;
	}
	tmp = (*stack)->top;
	while (tmp != NULL)
	{
		tmp->sort = 1;
		tmp = tmp->next;
	}
}

void			ft_desc_sort3(t_stack **stack, char **com, char c)
{
	void	(*mix[4])(t_stack **stack, char **com, char c);
	int		i;
	t_node	*tmp;

	mix[0] = ft_swap;
	mix[1] = ft_rotate;
	mix[2] = ft_swap;
	mix[3] = ft_reverse_rotate;
	i = 0;
	while (ft_is_desc_sort(*stack) == 0)
	{
		mix[i](stack, com, c);
		i++;
		if (i == 4)
			i = 0;
	}
	tmp = (*stack)->top;
	while (tmp != NULL)
	{
		tmp->sort = 1;
		tmp = tmp->next;
	}
}
