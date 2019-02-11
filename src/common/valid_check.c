/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:55:47 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/05 12:55:49 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_duplicates(t_stack **stack, int n)
{
	t_node	*tmp;

	tmp = NULL;
	if (*stack == NULL || stack == NULL)
		return (0);
	tmp = (*stack)->top;
	while (tmp != NULL)
	{
		if (tmp->data == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	ft_print_error(t_stack **stack, char **new, int count, int flag)
{
	ft_del_stack_nodes(stack);
	if (flag == 1)
		ft_arrdel(new, count);
	ft_putendl_fd("Error", 2);
	exit(1);
}

t_stack		*ft_valid_check(int start, int count, const char **str, int flag)
{
	t_stack			*stack;
	t_node			*node;
	long long int	new;
	int				i;

	stack = NULL;
	node = NULL;
	i = count - 1;
	while (i > start)
	{
		if (ft_is_number((char *)str[i]) == 0)
			ft_print_error(&stack, (char **)str, count, flag);
		new = ft_atoi(str[i]);
		if ((new > 2147483647 || new < -2147483648) ||
			ft_check_duplicates(&stack, (int)new) == 1)
			ft_print_error(&stack, (char **)str, count, flag);
		node = ft_make_node((int)new);
		ft_add_node_to_stack(&stack, node);
		i--;
	}
	return (stack);
}
