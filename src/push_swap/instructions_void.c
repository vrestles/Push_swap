/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_void.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:15:06 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/05 12:15:08 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_swap(t_stack **x, char **com, char c)
{
	char	*res;
	char	*name;
	int		ret;

	res = NULL;
	name = NULL;
	ret = ft_swap_int(x);
	if (ret == 1)
	{
		name = ft_straddchar("s", c);
		res = ft_strjoin(*com, name);
		ft_strdel(&name);
		ft_strdel(&(*com));
		*com = res;
	}
}

void		ft_push(t_stack **x, t_stack **y, char **com, char c)
{
	char	*res;
	char	*name;
	int		ret;

	res = NULL;
	name = NULL;
	ret = ft_push_int(x, y);
	if (ret == 1)
	{
		name = ft_straddchar("p", c);
		res = ft_strjoin(*com, name);
		ft_strdel(&name);
		ft_strdel(&(*com));
		*com = res;
	}
}

void		ft_rotate(t_stack **x, char **com, char c)
{
	char	*res;
	char	*name;
	int		ret;

	res = NULL;
	name = NULL;
	ret = ft_rotate_int(x);
	if (ret == 1)
	{
		name = ft_straddchar("r", c);
		res = ft_strjoin(*com, name);
		ft_strdel(&name);
		ft_strdel(&(*com));
		*com = res;
	}
}

void		ft_reverse_rotate(t_stack **x, char **com, char c)
{
	char	*res;
	char	*name;
	int		ret;

	res = NULL;
	name = NULL;
	ret = ft_reverse_rotate_int(x);
	if (ret == 1)
	{
		name = ft_straddchar("rr", c);
		res = ft_strjoin(*com, name);
		ft_strdel(&(*com));
		*com = res;
		ft_strdel(&name);
	}
}
