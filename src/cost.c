/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:02:21 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/15 13:38:34 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	take_cost(t_stack **stack_a, t_stack **stack_b)
{
	calculate_cost_a(*stack_a);
	calculate_cost_b(*stack_b);
}

void	calculate_cost_a(t_stack *stack_a)
{
	t_stack	*current;
	int		stack_size;
	int		middle;

	stack_size = get_stack_size(stack_a);
	current = stack_a;
	middle = (stack_size + 1) / 2;
	while (current)
	{
		if (current->pos <= middle)
			current->cost_b = current->pos;
		else
			current->cost_b = (stack_size - current->pos) * -1;
		current = current->next;
	}
}

void	calculate_cost_b(t_stack *stack_b)
{
	t_stack	*current;
	int		stack_size;
	int		middle;

	stack_size = get_stack_size(stack_b);
	current = stack_b;
	middle = (stack_size + 1) / 2;
	while (current)
	{
		if (current->pos <= middle)
			current->cost_b = current->pos;
		else
			current->cost_b = (stack_size - current->pos) * -1;
		current = current->next;
	}
}
