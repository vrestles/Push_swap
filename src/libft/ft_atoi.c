/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:17:09 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/04 15:14:17 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		skip_first(const char *str)
{
	if (str[0] == '\e')
		return (0);
	if ((str[0] == '+' || str[0] == '-') && (!(str[1] >= '0' && str[1] <= '9')))
		return (0);
	return (1);
}

long long int	ft_atoi(const char *str)
{
	int				sign;
	long long int	nb;

	sign = 1;
	nb = 0;
	if (skip_first(str) == 0)
		return (0);
	if (str[0] == ' ' || str[0] == '\t' || str[0] == '\n' || str[0] == '\v' || \
		str[0] == '\f' || str[0] == '\r' || str[0] == '+')
		return (ft_atoi(++str));
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (sign * nb);
		if ((nb = nb * 10 + (*str - '0')) < 0)
			return (sign == -1 ? 0 : -1);
		str++;
	}
	return (sign * nb);
}
