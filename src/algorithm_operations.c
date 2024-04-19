/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:00:29 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/19 14:32:23 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_better_operation(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		lower_cost;

	current = *stack_b;
	lower_cost = find_cheaper(stack_b);
	while (current)
	{
		if (current->total_cost == lower_cost)
		{
			moves(stack_a, stack_b, current->target_pos, current->pos);
			return ;
		}
		current = current->next;
	}
}

void	moves(t_stack **stack_a, t_stack **stack_b, int target_pos, int pos)
{
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = *stack_a;
	current_b = *stack_b;
	while (current_a->index != target_pos)
		current_a = current_a->next;
	while (current_b->pos != pos)
		current_b = current_b->next;
	while (current_b)
	{
		if (current_a->cost_a > 0 && current_b->cost_b > 0)
			both_rr(stack_a, stack_b, current_a->index, current_b->index);
		else if (current_a->cost_a < 0 && current_b->cost_a < 0)
			both_rrr(stack_a, stack_b, current_a->index, current_a->index);
		move_a(stack_a, target_pos);
		move_b(stack_b, pos);
		if (current_a->cost_a == 0 && current_b->cost_b == 0)
			break ;
	}
	do_pa(stack_a, stack_b);
}
