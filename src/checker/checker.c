/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:41:27 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/04 16:49:02 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int		ft_valid_command(char *str)
{
	char *valid;

	valid = "sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr";
	if (ft_strstr(valid, str) == NULL)
		return (0);
	return (1);
}

static void		ft_make_com_string(char **com, char *line)
{
	char	*res;
	char	*tmp;

	tmp = ft_strjoin(*com, line);
	ft_strdel(&line);
	ft_strdel(&(*com));
	res = ft_strjoin(tmp, " ");
	ft_strdel(&tmp);
	*com = res;
}

static void		ft_read_commands(char **com, t_stack **stack)
{
	char	*line;
	int		fd;
	char	*tmp;

	fd = 0;
	tmp = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_valid_command(line) == 0)
		{
			ft_strdel(&line);
			ft_strdel(&(*com));
			ft_del_stack_nodes(stack);
			ft_putendl_fd("Error", 2);
			exit(1);
		}
		else
			ft_make_com_string(com, line);
	}
}

static t_stack	*ft_make_a_stack(const char *str)
{
	int		count;
	char	**new;
	t_stack	*stack;

	count = ft_count_words(str, ' ');
	if (count == 0)
		exit(1);
	new = ft_strsplit(str, ' ');
	stack = ft_valid_check(-1, count, (const char **)new, 1);
	ft_arrdel(new, count);
	return (stack);
}

int				main(int argc, const char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*com;

	if (argc == 1)
		exit(1);
	else if (argc == 2)
		a = ft_make_a_stack(argv[1]);
	else
		a = ft_valid_check(0, argc, argv, 0);
	com = ft_strnew(0);
	ft_read_commands(&com, &a);
	b = ft_make_stack();
	if (ft_strcmp(com, "") != 0)
		ft_apply_commands(com, &a, &b);
	if (ft_is_asc_sort(a) && (b)->size == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_strdel(&com);
	ft_del_stack_nodes(&a);
	ft_del_stack_nodes(&b);
	return (0);
}
