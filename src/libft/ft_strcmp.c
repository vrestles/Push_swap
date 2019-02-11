/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:03:56 by vrestles          #+#    #+#             */
/*   Updated: 2018/12/03 13:12:14 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned const char *n1;
	unsigned const char	*n2;

	n1 = (unsigned const char *)s1;
	n2 = (unsigned const char *)s2;
	while (*n1 && (*n1 == *n2))
	{
		n1++;
		n2++;
	}
	return (*(unsigned char *)n1 - *(unsigned char *)n2);
}
