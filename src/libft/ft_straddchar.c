/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:18:14 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/04 15:19:29 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_straddchar(char const *s, char c)
{
	char	*res;
	int		len;
	int		i;

	if (s == NULL)
		return (NULL);
	len = (int)ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 3));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i++] = c;
	res[i++] = '\n';
	res[i] = '\0';
	return (res);
}
