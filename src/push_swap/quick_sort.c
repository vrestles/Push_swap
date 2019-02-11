/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:40:30 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/05 12:40:31 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_quick_sort(t_stack **x, t_stack **y, char **com)
{
	int	i;

	i = 0;
	while (!(ft_is_asc_sort(*x) == 1 && ft_is_desc_sort(*y) == 1))
	{
		while (ft_is_asc_sort(*x) == 0)
		{
			ft_sort_a(x, y, com);
			i++;
		}
		while (ft_is_desc_sort(*y) == 0)
		{
			(*x)->flag = 0;
			ft_sort_b(y, x, com);
			i++;
		}
	}
	while ((*y)->size != 0)
		ft_push(y, x, com, 'a');
}

void			ft_sort(char **com, t_stack **x, t_stack **y)
{
	if (ft_is_asc_sort(*x) == 1)
		return ;
	if ((*x)->size == 3 && ft_is_desc_sort(*x) == 1)
	{
		ft_swap(x, com, 'a');
		ft_reverse_rotate(x, com, 'a');
	}
	else if (ft_is_desc_sort(*x) == 1)
		ft_desc_sort(x, y, com);
	else
		ft_quick_sort(x, y, com);
	ft_optimization(com);
}
