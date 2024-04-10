/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:58:51 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/10 12:05:20 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			stack_a = add_node((int)nbr);
		else
			node_list_bottom(&stack_a, add_node((int)nbr));
		i++;
	}
	return (stack_a);
}

t_stack	*add_node(int nbr)
{
	t_stack	*new_node;

	new_node = malloc(sizeof * new_node);
	if (!new_node)
		return (NULL);
	new_node->value = nbr;
	new_node->index = 0;
	new_node->pos = -1;
	new_node->target_pos = -1;
	new_node->cost_a = -1;
	new_node->cost_b = -1;
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

t_stack	*get_bottom_list(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

// void	printf_stack(t_stack *stack_a)
// {
// 	while (stack_a != NULL)
// 	{
// 		printf("valor: %d index: %d\n", stack_a->value, stack_a->index);
// 		stack_a = stack_a->next;
// 	}
// }
