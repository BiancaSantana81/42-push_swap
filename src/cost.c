/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:02:21 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/17 13:12:51 by bsantana         ###   ########.fr       */
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
			current->cost_a = current->pos;
		else
			current->cost_a = (stack_size - current->pos) * -1;
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

void	total_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = *stack_a;
	while (current_a)
	{
		current_b = *stack_b;
		while (current_b)
		{
			if (current_b->target_pos == current_a->index)
			{
				current_b->total_cost = sum_cost(current_a->cost_a,
						current_b->cost_b);
			}
			current_b = current_b->next;
		}
		current_a = current_a->next;
	}
}

int	sum_cost(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}
