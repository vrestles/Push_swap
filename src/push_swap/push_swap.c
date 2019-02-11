/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:37:38 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/05 12:37:39 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static t_stack	*ft_make_a_stack(const char *str)
{
	int		count;
	char	**new;
	t_stack	*stack;

	count = ft_count_words(str, ' ');
	if (count == 0)
		exit(1);
	new = ft_strsplit(str, ' ');
	stack = ft_valid_check(-1, count, (const char **)new, 1);
	ft_arrdel(new, count);
	return (stack);
}

int				main(int argc, const char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*com;

	if (argc == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	else if (argc == 2)
		a = ft_make_a_stack(argv[1]);
	else
		a = ft_valid_check(0, argc, argv, 0);
	b = ft_make_stack();
	com = ft_strnew(0);
	ft_sort(&com, &a, &b);
	ft_putstr_fd(com, 1);
	ft_strdel(&com);
	ft_del_stack_nodes(&a);
	ft_del_stack_nodes(&b);
	return (0);
}
