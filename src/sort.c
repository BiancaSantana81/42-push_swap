/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:04:27 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/12 19:33:05 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	pushing_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int		max_index;

	max_index = highest_index(*stack_a);
	while (stack_a)
	{
		do_pb(stack_a, stack_b);
		// if (stack_a->index <= max_index)
		// {
		// 	do_pb(&stack_a, &stack_b);
		// 	max_index--;
		// }
		// else
		// 	do_ra(&stack_a);
		stack_a = &(*stack_a)->next;
	}
}

void	sort_tiny(t_stack **stack)
{
	if ((*stack)->index == highest_index(*stack))
		do_ra(stack);
	else if ((*stack)->next->index == highest_index(*stack))
		do_rra(stack);
	if (is_sorted(*stack) == 1)
		do_sa(stack);
}
