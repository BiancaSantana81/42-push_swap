/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:58:51 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/15 14:19:21 by bsantana         ###   ########.fr       */
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

void	assign_indexes(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*runner;

	current = stack_a;
	while (current)
	{
		runner = stack_a;
		while (runner)
		{	
			if (runner->value < current->value)
				current->index++;
			runner = runner->next;
		}
	current = current->next;
	}
}

int	highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (index < stack->index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

int	media_indexes(t_stack *stack)
{
	int	result;
	int	stack_size;

	result = 0;
	stack_size = get_stack_size(stack);
	while (stack)
	{
		result += stack->index;
		stack = stack->next;
	}
	return (result / stack_size);
}
