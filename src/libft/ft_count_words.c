/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:11:44 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/04 17:13:10 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_words(char const *s, char c)
{
	int		count;
	int		flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (flag == 0)
			{
				flag = 1;
				count++;
			}
		}
		else
			flag = 0;
		s++;
	}
	return (count);
}
