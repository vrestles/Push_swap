/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:44:43 by vrestles          #+#    #+#             */
/*   Updated: 2018/12/03 13:10:16 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *r;
	char *p;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		r = (char *)haystack;
		p = (char *)needle;
		while (*p && *r && *r == *p)
		{
			r++;
			p++;
		}
		if (!(*p))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
