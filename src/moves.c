/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:34:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/19 14:34:00 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_rr(t_stack **stack_a, t_stack **stack_b, int a, int b)
{
	t_stack	*current;

	current = *stack_a;
	while (current && current->index != a)
		current = current->next;
	current->cost_a--;
	current = *stack_b;
	while (current && current->index != b)
		current = current->next;
	current->cost_b--;
	do_rr(stack_a, stack_b);
}

void	both_rrr(t_stack **stack_a, t_stack **stack_b, int a, int b)
{
	t_stack	*current;

	current = *stack_a;
	while (current && current->index != a)
		current = current->next;
	current->cost_a++;
	current = *stack_b;
	while (current && current->index != b)
		current = current->next;
	current->cost_b++;
	do_rrr(stack_a, stack_b);
}

void	move_a(t_stack **stack_a, int target_pos)
{
	t_stack	*current;

	current = *stack_a;
	while (current)
	{
		if (current->index == target_pos)
		{
			while (current->cost_a != 0)
			{
				if (current->cost_a > 0)
				{
					do_ra(stack_a);
					current->cost_a--;
				}
				if (current->cost_a < 0)
				{
					do_rra(stack_a);
					current->cost_a++;
				}
			}
			return ;
		}
		current = current->next;
	}
}

void	move_b(t_stack **stack_b, int current_pos)
{
	t_stack	*current;

	current = *stack_b;
	while (current)
	{
		if (current->pos == current_pos)
		{
			while (current->cost_b != 0)
			{
				if (current->cost_b > 0)
				{
					do_rb(stack_b);
					current->cost_b--;
				}
				if (current->cost_b < 0)
				{
					do_rrb(stack_b);
					current->cost_b++;
				}
			}
			return ;
		}
		current = current->next;
	}
}
