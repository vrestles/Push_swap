/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:21:20 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/04 15:21:26 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static	int	ft_check_null(char **next_line, char **line)
{
	if (*line == NULL)
	{
		ft_strdel(next_line);
		return (1);
	}
	return (0);
}

static	int	ft_new_line(char **next_line, char **line)
{
	char			*tmp;
	int				size;

	size = 0;
	while (next_line[0][size] != '\n' && next_line[0][size] != '\0')
		size++;
	if (next_line[0][size] == '\n')
	{
		*line = ft_strsub(next_line[0], 0, size);
		if (ft_check_null(next_line, line) == 1)
			return (-1);
		tmp = ft_strdup(next_line[0] + size + 1);
		ft_strdel(next_line);
		CHECK_PTR(tmp);
		next_line[0] = tmp;
	}
	else if (next_line[0][size] == '\0')
	{
		*line = ft_strdup(next_line[0]);
		ft_strdel(next_line);
		CHECK_PTR(*line);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static	char	*next_line = NULL;
	int				ret;
	char			*tmp;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (next_line == NULL)
			next_line = ft_strnew(0);
		if (next_line == NULL)
			return (-1);
		tmp = ft_strjoin(next_line, buff);
		ft_strdel(&next_line);
		CHECK_PTR(tmp);
		next_line = tmp;
		if (ft_strchr(buff, '\n') != NULL)
			break ;
	}
	if (ret == 0 && (next_line == NULL || next_line[0] == '\0'))
		return (0);
	return (ft_new_line(&next_line, line));
}
