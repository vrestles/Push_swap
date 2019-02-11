/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:49:48 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/04 17:20:06 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_choose_command_2(char *str, t_stack **x, t_stack **y)
{
	int ret;

	if (ft_strcmp(str, "rra") == 0)
		ret = ft_reverse_rotate_int(x);
	else if (ft_strcmp(str, "rrb") == 0)
		ret = ft_reverse_rotate_int(y);
	else if (ft_strcmp(str, "rrr") == 0)
	{
		ret = ft_reverse_rotate_int(x);
		ret = ft_reverse_rotate_int(y);
	}
	else
		ret = 0;
}

static void		ft_choose_command_1(char *str, t_stack **x, t_stack **y)
{
	int ret;

	if (ft_strcmp(str, "ra") == 0)
		ret = ft_rotate_int(x);
	else if (ft_strcmp(str, "rb") == 0)
		ret = ft_rotate_int(y);
	else if (ft_strcmp(str, "rr") == 0)
	{
		ret = ft_rotate_int(x);
		ret = ft_rotate_int(y);
	}
	else if (ft_strcmp(str, "pa") == 0)
		ret = ft_push_int(y, x);
	else
		ft_choose_command_2(str, x, y);
}

static void		ft_choose_command(char *str, t_stack **x, t_stack **y)
{
	int ret;

	if (ft_strcmp(str, "sa") == 0)
		ret = ft_swap_int(x);
	else if (ft_strcmp(str, "sb") == 0)
		ret = ft_swap_int(y);
	else if (ft_strcmp(str, "ss") == 0)
	{
		ret = ft_swap_int(x);
		ret = ft_swap_int(y);
	}
	else if (ft_strcmp(str, "pb") == 0)
		ret = ft_push_int(x, y);
	else
		ft_choose_command_1(str, x, y);
}

void			ft_apply_commands(char *str, t_stack **x, t_stack **y)
{
	char	**res;
	int		count;
	int		i;

	count = ft_count_words(str, ' ');
	res = ft_strsplit(str, ' ');
	i = 0;
	while (i < count)
	{
		ft_choose_command(res[i], x, y);
		i++;
	}
	ft_arrdel(res, count);
}
