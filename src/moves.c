/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:34:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/17 18:15:05 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_rrr(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	cost_a++;
	cost_b++;
	do_rrr(stack_a, stack_b);
}

void	both_rr(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	cost_a--;
	cost_b--;
	do_rr(stack_a, stack_b);
}

void	move_a(t_stack **stack_a, int *cost_a)
{
	if (cost_a > 0)
	{
		do_ra(stack_a);
		cost_a++;
	}
	if (cost_a < 0)
	{
		do_rra(stack_a);
		cost_a--;
	}
}

void	move_b(t_stack **stack_b, int *cost_b)
{
	if (cost_b > 0)
	{
		do_rb(stack_b);
		cost_b++;
	}
	if (cost_b < 0)
	{
		do_rrb(stack_b);
		cost_b--;
	}
}
