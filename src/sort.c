/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:04:27 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/15 13:47:32 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushing_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	media;

	stack_size = get_stack_size(*stack_a);
	while (stack_size > 3)
	{
		stack_size = get_stack_size(*stack_a);
		media = media_indexes(*stack_a);
		if (stack_size == 3)
			break ;
		if ((*stack_a)->index <= media)
			do_pb(stack_a, stack_b);
		else
			do_ra(stack_a);
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{

	pushing_to_stack_b(stack_a, stack_b);
	sort_tiny(stack_a);
	while (*stack_b)
	{
		get_position(stack_b);
		take_cost(stack_a, stack_b);
		*stack_b = (*stack_b)->next;
	}
}
