/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:29:12 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/05 12:29:13 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_modify_string(char **com, char *str, char *mask)
{
	char	*first;
	char	*second;
	char	*new;

	*str = '\0';
	first = ft_strdup(*com);
	second = ft_strdup(str + ft_strlen(mask));
	new = ft_strjoin(first, second);
	ft_strdel(&first);
	ft_strdel(&second);
	ft_strdel(&(*com));
	*com = new;
}

static void	ft_optimization_b(char **com)
{
	char	*str;

	str = ft_strstr(*com, "\nrb\nrrb");
	if (str != NULL)
	{
		ft_modify_string(com, str, "\nrb\nrrb");
		ft_optimization_b(com);
	}
	str = ft_strstr(*com, "\nrrb\nrb");
	if (str != NULL)
	{
		ft_modify_string(com, str, "\nrrb\nrb");
		ft_optimization_b(com);
	}
	
}

static void	ft_optimization_a(char **com)
{
	char	*str;

	str = ft_strstr(*com, "\nra\nrra");
	if (str != NULL)
	{
		ft_modify_string(com, str, "\nra\nrra");
		ft_optimization_a(com);
	}
	str = ft_strstr(*com, "\nrra\nra");
	if (str != NULL)
	{
		ft_modify_string(com, str, "\nrra\nra");
		ft_optimization_a(com);
	}
	ft_optimization_b(com);
}

void		ft_optimization(char **com)
{
	char	*str;

	str = ft_strstr(*com, "\npa\npb");
	if (str != NULL)
	{
		ft_modify_string(com, str, "\npa\npb");
		ft_optimization(com);
	}
	str = ft_strstr(*com, "\npb\npa");
	if (str != NULL)
	{
		ft_modify_string(com, str, "\npb\npa");
		ft_optimization(com);
	}
	ft_optimization_a(com);
}
