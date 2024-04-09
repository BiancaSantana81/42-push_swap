/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:58:51 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/09 17:16:06 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_bottom_list(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*add_node(int nbr)
{
	t_stack	*new_node;

	new_node = malloc(sizeof * new_node);
	if (!new_node)
		return (NULL);
	new_node->value = nbr;
	new_node->next = NULL;
	return (new_node);
}

void	node_list_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = get_bottom_list(*stack);
	tmp->next = new;
}

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;
	long	nbr;

	stack_a = NULL;
	i = 1;
	while (i < ac)
	{
		nbr = ft_atol(av[i]);
		if (!(nbr > INT_MIN && nbr < INT_MAX))
			error(&stack_a);
		if (i == 1)
			add_node((int)nbr);
		else
			node_list_bottom(&stack_a, add_node((int)nbr));
		i++;
	}
	return (stack_a);
}

void	printf_stack(t_stack *stack_a)
{
	while (stack_a != NULL)
	{
		printf("%d", stack_a->value);
		stack_a = stack_a->next;
	}
}
