/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:11:21 by vrestles          #+#    #+#             */
/*   Updated: 2018/12/03 16:07:08 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_arrdel(char **as, int count)
{
	int	i;

	if (as == NULL || *as == NULL)
		return ;
	i = 0;
	while (i < count)
	{
		free(as[i]);
		as[i] = NULL;
		i++;
	}
	free(as);
	as = NULL;
}
