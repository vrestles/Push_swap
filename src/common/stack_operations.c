/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:53:33 by vrestles          #+#    #+#             */
/*   Updated: 2019/02/05 12:53:34 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node		*ft_find_n_node(int n, t_stack *stack)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack->top;
	while (tmp != NULL)
	{
		if (i == n)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (tmp);
}

t_node		*ft_make_node(int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	CHECK(new);
	new->data = data;
	new->sort = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack		*ft_make_stack(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	CHECK(new);
	new->size = 0;
	new->down = NULL;
	new->pivot = NULL;
	new->top = NULL;
	new->flag = 1;
	new->dir = 0;
	return (new);
}

void		ft_add_node_to_stack(t_stack **stack, t_node *node)
{
	if ((*stack) == NULL)
	{
		*stack = ft_make_stack();
		(*stack)->down = node;
	}
	if ((*stack)->size == 0)
		(*stack)->down = node;
	(*stack)->size += 1;
	node->next = (*stack)->top;
	if ((*stack)->top != NULL)
		(*stack)->top->prev = node;
	(*stack)->top = node;
}

void		ft_del_stack_nodes(t_stack **stack)
{
	t_node	*tmp;
	t_node	*del;

	tmp = NULL;
	del = NULL;
	if (*stack == NULL || *stack == NULL)
		return ;
	tmp = (*stack)->top;
	while (tmp != NULL)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
		del = NULL;
	}
	free(*stack);
	*stack = NULL;
}
